#include<iostream>
#include<cassert>
#include<cmath>
using namespace std;

class Deque{
private:
	int capacity{};
	int front{};
	int rear{};
	int added_elements{};
	int* array{};
public:
	Deque(int capacity) : capacity(capacity) {
		array = new int[capacity];
	}
	~Deque(){
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
	int prev(int idx){
		if(idx == 0)
			return capacity - 1;
		return idx - 1;
	}
	void enqueue_rear(int value){
		assert(!isFull());
		array[rear] = value;
		rear = next(rear);
		++added_elements;
	}
	void enqueue_front(int value){
		assert(!isFull());
		front = prev(front);
		array[front] = value;
		++added_elements;
	}
	int dequeue_front(){
		assert(!isFull());
		int last = array[front];
		front = next(front);
		--added_elements;
		return last;
	}
	int dequeue_rear(){
		assert(!isFull());
		rear = prev(rear);
		int last = array[rear];
		--added_elements;
		return last;
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

int main() {
	Deque q(10);
	q.enqueue_rear(5);
	q.enqueue_rear(4);
	q.enqueue_rear(6);
	q.print();
	q.dequeue_rear();
	q.enqueue_rear(8);
	q.print();
}
