#include<iostream>
#include<unordered_set>
using namespace std;

int count_unique_substrings(const string &str){
	unordered_set<string> subs;
	for (int i = 0; i < str.size(); i++){
		string a = "";
		for (int j = i; j < str.size(); j++){
			a += str[j];
			subs.insert(a);
		}
	}
	return subs.size();
}

int main() {
	cout << count_unique_substrings("aaaaa") << endl;
	cout << count_unique_substrings("aaaba") << endl;
	cout << count_unique_substrings("abcdef");
}