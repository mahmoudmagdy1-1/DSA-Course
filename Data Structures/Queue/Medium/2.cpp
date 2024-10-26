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
		assert(!isEmpty());
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

class PriorityQueue{
private:
	Queue q1;
	Queue q2;
	Queue q3;
	int size{};
	int added_elements{};
public:
	PriorityQueue(int size) : q1(size), q2(size), q3(size){}
	void enqueue(int task_id, int priority){
		if(priority == 1) q1.enqueue(task_id);
		else if(priority == 2) q2.enqueue(task_id);
		else q3.enqueue(task_id);
		++added_elements;
	}
	int dequeue(){
		--added_elements;
		if(!q3.isEmpty()) return q3.dequeue();
		else if(!q2.isEmpty()) return q2.dequeue();
		else return q1.dequeue();
		
	}
	void display(){
		cout << "Priority #3 tasks: "; q3.print();
		cout << "Priority #2 tasks: "; q2.print();
		cout << "Priority #1 tasks: "; q1.print();
	}
	bool isEmpty(){
		return added_elements == 0;
	}
	bool isFull(){
		return added_elements == size;
	}
};

int main() {
	PriorityQueue tasks(8);
	tasks.enqueue(1131, 1);
	tasks.enqueue(3111, 3);
	tasks.enqueue(2211, 2);
	tasks.enqueue(3161, 3);
	tasks.display();
	cout << tasks.dequeue() << "\n";
	cout << tasks.dequeue() << "\n";
	tasks.enqueue(1535, 1);
	tasks.enqueue(2815, 2);
	tasks.enqueue(3845, 3);
	tasks.enqueue(3145, 3);
	tasks.display();
	while (!tasks.isEmpty())
		cout << tasks.dequeue() << " ";

}