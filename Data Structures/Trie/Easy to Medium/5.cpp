#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

class Trie{
private:
	map<string, Trie*> child;
	bool isLeaf{};
public:
	void insert(const vector<string> &path){
		Trie* curr = this;
		for (int i = 0; i < path.size(); i++)
		{
			if(!curr->child[path[i]])
				curr->child[path[i]] = new Trie();
			curr = curr->child[path[i]];
		}
		curr->isLeaf = 1;
	}
	bool subpath_exist(const vector<string> &path){
		Trie* curr = this;
		for (int i = 0; i < path.size(); i++)
		{
			if(!curr->child[path[i]])
				return 0;
			curr = curr->child[path[i]];
		}
		return 1;
	}
};

int main(){
	Trie t;
	vector<string> path;

	path = {"home", "software", "eclipse"};
	t.insert(path);

	path = {"home", "software", "eclipse", "bin"};
	t.insert(path);

	path = {"home", "installed", "gnu"};
	t.insert(path);

	path = {"user", "mostafa", "tmp"};
	t.insert(path);

	path = {"user", "mostafa", "tmp"};
	cout << t.subpath_exist(path) << "\n"; // 1

	path = {"user", "mostafa"};
	cout << t.subpath_exist(path) << "\n"; // 1

	path = {"user", "mostafa", "private"};
	cout << t.subpath_exist(path) << "\n"; // 0
}