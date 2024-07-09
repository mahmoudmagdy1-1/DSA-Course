#include<iostream>
#include<stack>
#include<cassert>
using namespace std;
//solution at line 45

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
void next_greater_elements(int a[], int len){
	Stack s(len);
	for (int i = 0; i < len; i++)
	{
		while(!s.isEmpty() && a[s.peek()] < a[i])
			a[s.pop()] = a[i];
		s.push(i);
	}
	while(!s.isEmpty()){
		a[s.pop()] = -1;
	}
	for (int i = 0; i < len; i++)
	{
		cout << a[i] << " ";
	}
	
}
int main() {
	int arr[]{15, 10, 3, 5, 20};
	next_greater_elements(arr, 5);
}