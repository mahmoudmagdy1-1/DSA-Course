#include<iostream>
#include<cassert>
using namespace std;

typedef char type;

class Stack{
private:
	int size{};
	int top{};
	type* arr{};
public:
	Stack(int size) : size(size), top(-1) {
		arr = new type[size];
	}
	~Stack(){
		delete[] arr;
	}
	bool isEmpty(){
		return top == -1;
	}
	bool isFull(){
		return top == size - 1;
	}
	void push(int val){
		assert(!isFull());
		arr[++top] = val;
	}
	type pop(){
		assert(!isEmpty());
		return arr[top--];
	}
	type peek(){
		assert(!isEmpty());
		return arr[top];
	}
	void print(){
		for (int i = top; i >= 0; i--)
			cout << arr[i];
		cout << endl;
	}
};
string reverse_subwords(string line){
	string res = "";
	Stack s(line.size());
	line += ' ';
	for (int i = 0; i < line.size(); i++)
	{
		if(line[i] == ' '){
			while(!s.isEmpty()){
				res += s.pop();
			}
			res += ' ';
		}
		else s.push(line[i]);
	}
	return res;
}
int main() {
	string s = "abc d efg xy";
	cout << reverse_subwords(s);
}