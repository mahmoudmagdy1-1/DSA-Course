#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

class Trie{
private:
	map<char, Trie*> child;
	bool isLeaf{};
public:
	void insert(string str, int idx = 0){
		if(idx == str.size())
			isLeaf = 1;
		else{
			if(child[str[idx]] == nullptr){
				child[str[idx]] = new Trie();
			}
			child[str[idx]]->insert(str, idx + 1);
		}
	}
	bool prefix_exists(string str, int idx = 0){
		if(idx == str.size())
			return 1;
		if(child[str[idx]] == nullptr)
			return 0;
		return child[str[idx]]->prefix_exists(str, idx + 1);
	}
	bool word_exists(string str, int idx = 0){
		if(idx == str.size())
			return isLeaf;
		if(child[str[idx]] == nullptr)
			return 0;
		return child[str[idx]]->word_exists(str, idx + 1);
	}
};

int main(){
	Trie t;
	t.insert("alo");
	cout << t.prefix_exists("al") << endl;
	cout << t.prefix_exists("lo") << endl;
	cout << t.prefix_exists("alo") << endl;
	cout << t.prefix_exists("s") << endl;
	cout << t.word_exists("alo") << endl;
	cout << t.word_exists("al") << endl;
}