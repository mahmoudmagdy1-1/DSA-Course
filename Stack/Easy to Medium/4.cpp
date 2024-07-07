#include<iostream>
#include<stack>
#include<cassert>
using namespace std;

typedef int type;

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
bool valid_parentheses(string str){
	Stack s(str.size());
	for (int i = 0; i < str.size(); i++)
	{
		if(str[i] == '(' || str[i] == '[' || str[i] == '{') s.push(str[i]);
		else if(s.isEmpty()) return 0;
        else if((s.peek() == '(' && str[i] == ')') || (s.peek() == '[' && str[i] == ']') || (s.peek() == '{' && str[i] == '}')){
		s.pop();
		}
        else return 0;
	}
	return s.isEmpty();
}
int main() {
	cout << valid_parentheses("()") << endl;
	cout << valid_parentheses("()[]{}") << endl;
	cout << valid_parentheses("(]") << endl;
}