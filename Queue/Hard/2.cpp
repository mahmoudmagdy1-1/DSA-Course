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

class Last_k_numbers_sum_stream {
private:
	int k;
	int added_elements{};
	int sum{};
	Queue q;
public:
	Last_k_numbers_sum_stream(int k) : k(k), q(k){}
	int next(int new_num){
		if(added_elements == k){
			sum -= q.dequeue();
			--added_elements;
		}
		q.enqueue(new_num);
		++added_elements;
		sum += new_num;
		return sum;
	}
};

int main() {
	Last_k_numbers_sum_stream processor(4);

	int num;
	while(cin >> num)
		cout << "Sum of last K numbers " << processor.next(num) << endl;
}