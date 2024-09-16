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
	void insert(string str, int idx = 0){
		if(idx == str.size())
			isLeaf = 1;
		else{
			int ch = str[idx] - 'a';
			if(child[ch] == nullptr){
				child[ch] = new Trie();
			}
			child[ch]->insert(str, idx + 1);
		}
	}
	bool prefix_exists(string str, int idx = 0){
		if(idx == str.size())
			return 1;
		int ch = str[idx] - 'a';
		if(child[ch] == nullptr)
			return 0;
		return child[ch]->prefix_exists(str, idx + 1);
	}
	bool word_exists(string str, int idx = 0){
		if(idx == str.size())
			return isLeaf;
		int ch = str[idx] - 'a';
		if(child[ch] == nullptr)
			return 0;
		return child[ch]->word_exists(str, idx + 1);
	}
	string first_word_prefix(const string &str){
		Trie* curr = this;
		for (int i = 0; i < str.size(); i++)
		{
			int ch = str[i] - 'a';
			if(curr->child[ch] == nullptr)
				break;
			if(curr->child[ch]->isLeaf)
				return str.substr(0, i + 1);
			curr = curr->child[ch];
		}
		return str;
	}
};

int main(){
	Trie t;
	t.insert("xyz");
	t.insert("xyzeA");
	t.insert("a");
	t.insert("bc");
	cout << t.first_word_prefix("x") << endl;
	cout << t.first_word_prefix("xyzabc") << endl;
}