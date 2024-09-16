#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

class Trie{
private:
	Trie* child[26];
	bool isLeaf{};
public:
	Trie(){
		memset(child, 0, sizeof(child));
	}
	void insert_rec(string str, int idx = 0){
		if(idx == str.size())
			isLeaf = 1;
		else{
			int ch = str[idx] - 'a';
			if(child[ch] == nullptr){
				child[ch] = new Trie();
			}
			child[ch]->insert_rec(str, idx + 1);
		}
	}
	void insert_itr(string str){
		Trie* curr = this;
		for (int i = 0; i < str.size(); i++)
		{
			int ch = str[i] - 'a';
			if(curr->child[ch] == nullptr)
				curr->child[ch] = new Trie();
			curr = curr->child[ch];
		}
		curr->isLeaf = 1;
	}
	bool prefix_exists(string str, int idx = 0){
		if(idx == str.size())
			return 1;
		int ch = str[idx] - 'a';
		if(child[ch] == nullptr)
			return 0;
		return child[ch]->prefix_exists(str, idx + 1);
	}
	bool word_exists_rec(string str, int idx = 0){
		if(idx == str.size())
			return isLeaf;
		int ch = str[idx] - 'a';
		if(child[ch] == nullptr)
			return 0;
		return child[ch]->word_exists_rec(str, idx + 1);
	}
	bool word_exists_itr(string str){
		Trie* curr = this;
		for (int i = 0; i < str.size(); i++)
		{
			int ch = str[i] - 'a';
			if(curr->child[ch] == nullptr)
				return 0;
			curr = curr->child[ch];
		}
		return curr->isLeaf;
	}
};

int main(){
	Trie t;
	t.insert_itr("alo");
	//t.insert_rec("alo");
	cout << t.prefix_exists("al") << endl;
	cout << t.prefix_exists("lo") << endl;
	cout << t.prefix_exists("alo") << endl;
	cout << t.prefix_exists("s") << endl;
	cout << t.word_exists_rec("al") << endl;
	cout << t.word_exists_rec("alo") << endl;
	cout << t.word_exists_itr("al") << endl;
	cout << t.word_exists_itr("alo") << endl;
}