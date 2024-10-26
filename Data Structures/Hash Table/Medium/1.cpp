#include <iostream>
using namespace std;

int hash_string(string str, int n = 152130){
	long long nn = n;
	long long s = 0;
	int val = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if(isdigit(str[i]))
			val = 52 + str[i] - '0';
		else if(islower(str[i]))
			val = str[i] - 'a';
		else if(isupper(str[i]))
			val = 26 + str[i] - 'A';
		s = (s * 62 + val) % nn;
	}
	return s;
}

int main(){
	auto x = "aabcdefgAxT334gfa";
	cout << hash_string(x);	
}