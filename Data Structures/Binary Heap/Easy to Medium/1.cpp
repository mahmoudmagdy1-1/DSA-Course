#include <iostream>
using namespace std;

class MaxHeap{
private:
	int* array{};
	int capacity{1000};
	int size{};
	int left(int node){
		return node > size ? -1 : node * 2 + 1;
	}
	int right(int node){
		return node > size ? -1 : node * 2 + 2;
	}
	int parent(int node){
		return node == 0 ? -1 : (node-1) / 2;
	}
	void heapify_up(int child_pos){
		int parent_pos = parent(child_pos);
		if(child_pos == 0) return;
		if(array[parent_pos] < array[child_pos]){
			swap(array[parent_pos], array[child_pos]);
			child_pos = parent_pos;
			heapify_up(child_pos);
		}
		else return;
	}
	void heapify_down(int parent_pos){
		int child_pos = left(parent_pos);
		int right_pos = right(parent_pos);
		if(!child_pos) return;
		if(right_pos && array[right_pos] > array[child_pos])
			child_pos = right_pos;
		if(array[parent_pos] < array[child_pos]){
			swap(array[parent_pos], array[child_pos]);
			heapify_down(child_pos);
		}
	}
public:
	MaxHeap(){
		array = new int[capacity];
	}
	~MaxHeap(){
		delete[] array;
		array = nullptr;
	}
	void push(int item){
		array[size++] = item;
		heapify_up(size-1);
	}
	void pop(){
		array[0] = array[--size];
		heapify_down(0);
	}
	int top(){
		return array[0];
	}
	int sz(){
		return size;
	}
};

int main(){
}