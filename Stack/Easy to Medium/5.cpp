#include<iostream>
#include<stack>
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
	void push(type val){
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
string removeDuplicates(string str){
	Stack s(str.size());
	for (int i = 0; i < str.size(); i++)
	{
		if(!s.isEmpty() && s.peek() == str[i])
			s.pop();
		else s.push(str[i]);
	}
	str = "";
	while(!s.isEmpty()){
		str = s.pop() + str;
	}
	return str;
}
int main() {
	cout << removeDuplicates("abbaca") << endl;
	cout << removeDuplicates("azxxzy") << endl;
}