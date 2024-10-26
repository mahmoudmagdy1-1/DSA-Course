#include<iostream>
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
int reverse_int(int num){
	Stack s(25);
	while(num){
		s.push(num%10), num/=10;
	}
	int x = 1;
	while(!s.isEmpty()){
		num = s.pop() * x + num, x*=10;
	}
	return num;
}
int main() {
	int x = 1234;
	cout << reverse_int(x);
}