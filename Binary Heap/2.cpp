#include <iostream>
using namespace std;

class PriorityQueue{
private:
	int* key{};
	int* value{};
	int capacity{1000};
	int size{};
	int left(int node){
		int leftChild = node * 2 + 1;
		return leftChild < size ? leftChild : -1;
	}
	int right(int node){
		int rightChild = node * 2 + 2;
		return rightChild < size ? rightChild : -1;
	}
	int parent(int node){
		return node == 0 ? -1 : (node-1) / 2;
	}
	void heapify_up(int child_pos){
		int parent_pos = parent(child_pos);
		if(child_pos == 0) return;
		if(key[parent_pos] < key[child_pos]){
			swap(key[parent_pos], key[child_pos]);
			swap(value[parent_pos], value[child_pos]);
			heapify_up(parent_pos);
		}
		else return;
	}
	void heapify_down(int parent_pos){
		int child_pos = left(parent_pos);
		int right_pos = right(parent_pos);
		if(child_pos == -1) return;
		if(right_pos != -1 && key[right_pos] > key[child_pos])
			child_pos = right_pos;
		if(key[parent_pos] < key[child_pos]){
			swap(key[parent_pos], key[child_pos]);
			swap(value[parent_pos], value[child_pos]);
			heapify_down(child_pos);
		}
	}
public:
	PriorityQueue(){
		key = new int[capacity];
		value = new int[capacity];
	}
	~PriorityQueue(){
		delete[] key;
		delete[] value;
		key = nullptr;
		value = nullptr;
	}
	void enqueue(int val, int keys){
		key[size] = keys;
		value[size++] = val;
		heapify_up(size-1);
	}
	int dequeue(){
		key[0] = key[--size];
		int res = value[0];
		value[0] = value[size];
		heapify_down(0);
		return res;
	}
	int top(){
		return value[0];
	}
	int sz(){
		return size;
	}
	bool isEmpty(){
		return size == 0;
	}
};

int main() {
	PriorityQueue tasks;

	tasks.enqueue(1131, 1);
	tasks.enqueue(3111, 3);
	tasks.enqueue(2211, 2);
	tasks.enqueue(3161, 3);
	tasks.enqueue(7761, 7);

	cout << tasks.dequeue() << "\n";
	cout << tasks.dequeue() << "\n";

	tasks.enqueue(1535, 1);
	tasks.enqueue(2815, 2);
	tasks.enqueue(3845, 3);
	tasks.enqueue(3145, 3);

	while (!tasks.isEmpty())
		cout << tasks.dequeue() << " ";

	return 0;
}

