#include<iostream>
#include<cassert>
#include<cmath>
using namespace std;

class Queue{
private:
	int capacity{};
	int front{};
	int rear{};
	int added_elements{};
	int* array{};
public:
	Queue(int capacity) : capacity(capacity) {
		array = new int[capacity];
	}
	~Queue(){
		delete[] array;
	}
	bool isEmpty(){
		return added_elements == 0;
	}
	bool isFull(){
		return added_elements == capacity;
	}
	int next(int idx){
		if(idx == capacity - 1)
			return 0;
		return idx + 1;
	}
	void enqueue(int value){
		assert(!isFull());
		array[rear] = value;
		rear = next(rear);
		++added_elements;
	}
	int dequeue(){
		assert(!isFull());
		int last = array[front];
		front = next(front);
		--added_elements;
		return last;
	}
	int front_val(){
		assert(!isEmpty());
		return array[front];
	}
	void print(){
		assert(!isEmpty());
		for (int i = 0, curr = front; i < added_elements; i++, curr = next(curr))
		{
			cout << array[curr] << " ";
		}
		cout << endl;
	}
};

class Stack{
private:
	Queue q;
	int added_elements {};
	void insert_front(int val){
		q.enqueue(val);
		for (int i = 0; i < added_elements; i++)
		{
			q.enqueue(q.dequeue());
		}
		++added_elements;
	}
public:
	Stack(int size) : q(size) {}
	void push(int val){
		insert_front(val);
	}
	void pop(){
		q.dequeue();
		--added_elements;
	}
	bool isEmpty(){
		return q.isEmpty();
	}
	bool isFull(){
		return q.isFull();
	}
	int peek(){
		return q.front_val();
	}
};

int main() {
	Stack s(10);
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	while(!s.isEmpty()){
		cout << s.peek() << " ";
		s.pop();
	}
}