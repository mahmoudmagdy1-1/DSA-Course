#include <iostream>
#include <vector>
using namespace std;

class MinHeap{
private:
	int* array{};
	int capacity{1000};
	int size{};
	int left(int node){
		return node * 2 + 1 >= size ? -1 : node * 2 + 1;
	}
	int right(int node){
		return node * 2 + 2 >= size ? -1 : node * 2 + 2;
	}
	int parent(int node){
		return node == 0 ? -1 : (node-1) / 2;
	}
	void heapify_down(int parent_pos){
		int child_pos = left(parent_pos);
		int right_pos = right(parent_pos);
		if(!child_pos) return;
		if(right_pos && array[right_pos] < array[child_pos])
			child_pos = right_pos;
		if(array[parent_pos] > array[child_pos]){
			swap(array[parent_pos], array[child_pos]);
			heapify_down(child_pos);
		}
	}
	void heapify_up(int child_pos){
		int parent_pos = parent(child_pos);
		if(child_pos == 0) return;
		if(array[parent_pos] > array[child_pos]){
			swap(array[parent_pos], array[child_pos]);
			child_pos = parent_pos;
			heapify_up(child_pos);
		}
		else return;
	}
public:
	MinHeap(){
		array = new int[capacity];
	}
	MinHeap(const vector<int>& vec){
		array = new int[capacity];
		for (int i = 0; i < vec.size(); i++)
			push(vec[i]);
	}
	~MinHeap(){
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
	bool isEmpty(){
		return size == 0;
	}
	void print(){
		for (int i = 0; i < size; i++)
		{
			cout << array[i] << " ";
		}
		
	}
	void print_less_than(int val, int parent_pos = 0){
		if(array[parent_pos] >= val || parent_pos == -1) return;
		cout << array[parent_pos] << " ";
		print_less_than(val, left(parent_pos));
		print_less_than(val, right(parent_pos));
	}
};


int main(){
	vector<int> vec {2, 17, 22, 10, 8, 37, 14, 19, 7, 6, 5, 12, 25, 30};
	MinHeap heap(vec);
	heap.print_less_than(10);
}