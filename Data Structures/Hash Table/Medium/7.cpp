#include<iostream>
#include<unordered_set>
using namespace std;

int count_substrings_match(const string &str1, const string &str2){
	unordered_set<string> subs1;
	unordered_set<string> subs2;
	int res = 0;
	for (int i = 0; i < str1.size(); i++){
		string a = "";
		for (int j = i; j < str1.size(); j++){
			a += str1[j];
			subs1.insert(a);
		}
	}
	for (int i = 0; i < str2.size(); i++){
		string a = "";
		for (int j = i; j < str2.size(); j++){
			a += str2[j];
			subs2.insert(a);
		}
	}
	for(auto& i : subs2){
		if(subs1.count(i)) res++;
	}
	return res;
}

int main() {
	cout << count_substrings_match("aaab", "aa") << endl;
	cout << count_substrings_match("aaab", "ab") << endl;
	cout << count_substrings_match("aaaaa", "xy") << endl;
	cout << count_substrings_match("aaaaa", "aaaaa") << endl;
}