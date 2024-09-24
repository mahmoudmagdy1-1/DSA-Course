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

int hash_num(int val, int n = 152130){
	long long nn = n;
	return (val % nn + nn) % nn;
}

int folding_hash(string str, int n = 152130){
	long long nn = n;
	long long res = 0;
	for (int i = 0; i < str.size(); i+=4)
	{
		res += hash_string(str.substr(i, 4));
		res %= nn;
	}
	return res;
}

struct SomeObject
{
	const static int INTERNAL_LIMIT = 2147483647;
	string str1, str2;
	int number;

	int hash(){
		long long s = folding_hash(str1 + str2, INTERNAL_LIMIT);
		s += hash_num(number, INTERNAL_LIMIT);
		return s % INTERNAL_LIMIT;
	}
};


int main(){
	auto x = "aabcdefgAxT334gfa";
	string stt = "apszf";
	cout << hash_string(x) << "\n";
	cout << folding_hash(x);
}