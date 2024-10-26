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
		if(child_pos == -1) return;
		if(right_pos != -1 && array[right_pos] < array[child_pos])
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
	void heapify(){
		for (int i = size/2 - 1; i >= 0; --i)
			heapify_down(i);
	}
	bool is_heap(int parent_pos){
		if(parent_pos == -1)
			return 1;
		int lft = left(parent_pos);
		int rght = right(parent_pos);
		if(lft != -1 && array[parent_pos] > array[lft]) return 0;
		if(rght != -1 && array[parent_pos] > array[rght]) return 0;
		return is_heap(lft) && is_heap(rght);
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
	void heap_sort(int *p, int n){
		int* oldArr = array;
		int oldSz = size;

		array = p;
		size = n;

		heapify();

		while(size--){
			swap(array[0], array[size]);
			heapify_down(0);
		}

		for (int i = 0; i < n/2; i++)
			swap(array[i], array[n-i-1]);

		array = oldArr;
		size = oldSz;
	}
};

int main(){
	int arr[14] = {2, 5, 12, 7,6, 22, 14, 25, 10, 17, 8, 37, 25, 30};
	MinHeap heap;
	heap.heap_sort(arr, 14);
	for (int i = 0; i < 14; i++)
		cout << arr[i] << " ";
	
}