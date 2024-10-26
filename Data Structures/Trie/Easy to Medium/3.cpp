#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

class Trie{
private:
	Trie* child[26];
	bool isLeaf{};
public:
	Trie(){
		memset(child, 0, sizeof(child));
	}
	void insert(string str){
		reverse(str.begin(), str.end());
		Trie* curr = this;
		for (int i = 0; i < str.size(); i++)
		{
			int ch = str[i] - 'a';
			if(curr->child[ch] == nullptr){
				curr->child[ch] = new Trie();
			}
			curr = curr->child[ch];
		}
	}
	bool suffix_exist(string str){
		reverse(str.begin(), str.end());
		Trie* curr = this;
		for (int i = 0; i < str.size(); i++)
		{
			int ch = str[i] - 'a';
			if(!curr->child[ch])
				return 0;
			curr = curr->child[ch];
		}
		return 1;
	}
};

int main(){
	Trie t;
	t.insert("abc");
	cout << t.suffix_exist("bc") << endl;
	cout << t.suffix_exist("ab") << endl;
}