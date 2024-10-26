#include<iostream>
#include<stack>
#include<cassert>
using namespace std;
//solution at line 52

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
			cout << arr[i] << " ";
		cout << endl;
	}
};
int scoreOfParenthesses(string s){
	Stack st(s.size());
	st.push(0);
	for (int i = 0; i < s.size(); i++)
	{
		char c = s[i];
		if(c == '(')
			st.push(0);
		else{
			int tmp = st.pop();
			if(!tmp)
				tmp = 1;
			else
				tmp *= 2;
			int parent = tmp + st.pop();
			st.push(parent);
		}
	}
	return st.peek();
}
int main() {
	cout << scoreOfParenthesses("(())") << " ";
	cout << scoreOfParenthesses("(()(()))") << " ";
	cout << scoreOfParenthesses("(()())") << " ";
}