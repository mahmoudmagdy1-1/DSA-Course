#include<iostream>
#include<cassert>
using namespace std;
//solution at line 43

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
	void insert_at_bottom(int x){
		// recursive
		if(isEmpty())
			push(x);
		else{
			int temp = pop();
			insert_at_bottom(x);
			push(temp);
		}
		/* iterative
		for (int i = ++top; i > 0; i--)
		{
			arr[i] = arr[i-1];
		}
		arr[0] = x; */
	}
};

int main() {
	Stack s(10);
	s.push(4);
	s.push(3);
	s.push(2);
	s.push(1);
	s.insert_at_bottom(10);
	s.print();
}