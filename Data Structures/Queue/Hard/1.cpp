#include<iostream>
#include<cassert>
#include<cmath>
using namespace std;

class Stack{
private:
	int top{};
	int* array{};
	int size;
public:
	Stack(int size) : size(size), top(-1) {
		array = new int[size];
	}
	~Stack(){
		delete[] array;
	}
	void push(int val){
		assert(!isFull());
		array[++top] = val;
	}
	int pop(){
		assert(!isEmpty());
		return array[top--];
	}
	bool isEmpty(){
		return top == -1;
	}
	bool isFull(){
		return top == size - 1;
	}
	int peek(){
		assert(!isEmpty());
		return array[top];
	}
};

class Queue{
private:
	int size{};
	int added_elements{};
	Stack s1;
	Stack s2;
	void move(Stack& from, Stack& to){
		while(!from.isEmpty()){
			to.push(from.pop());
		}
	}
public:
	Queue(int size) : size(size), s1(size), s2(size) {}
	void enqueue(int val){
		assert(!isFull());
		s1.push(val);
		++added_elements;
	}
	int dequeue(){
		assert(!isEmpty());
		if(s2.isEmpty())
			move(s1, s2);
		int last = s2.pop();
		--added_elements;
		return last;
	}
	bool isEmpty(){
		return added_elements == 0;
	}
	bool isFull(){
		return added_elements == size;
	}
};

int main() {
	Queue qu(6);
	for (int i = 1; i <= 3; i++)
		qu.enqueue(i);
	cout << qu.dequeue() << " ";
	for (int i = 4; i <= 5; i++)
		qu.enqueue(i);
	while(!qu.isEmpty())
		cout << qu.dequeue() << " ";
}