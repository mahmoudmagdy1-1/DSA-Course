#include<iostream>
#include<unordered_set>
#include<algorithm>
using namespace std;

int count_substrings_match(const string &str1){
	unordered_set<string> subs1;
	for (int i = 0; i < str1.size(); i++){
		string a = "";
		for (int j = i; j < str1.size(); j++){
			a += str1[j];
			sort(a.begin(), a.end());
			subs1.insert(a);
		}
	}
	return subs1.size();
}

int main() {
	cout << count_substrings_match("aaaaa") << endl;
	cout << count_substrings_match("abcba") << endl;
	cout << count_substrings_match("aabade") << endl;
}