#include<iostream>
#include<stack>
#include<vector>
#include<cassert>
using namespace std;

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
	void print_reversed(){
		for (int i = 0; i <= top; i++)
			cout << arr[i] << " ";
		cout << endl;
	}
};

void asteroidCollision(int arr[], int len){
    Stack s(len);
	for (int i = 0; i < len; i++)
	{
		int curr = arr[i];
        if(curr > 0 || s.isEmpty())
            s.push(curr);
        else{
            while(!s.isEmpty() && -curr > s.peek() && s.peek() > 0){
				s.pop();
			}
			if(!s.isEmpty() && -curr == s.peek())  s.pop();
			else if(s.isEmpty() || s.peek() < 0) {
				s.push(curr);
			}
		}
    }
	s.print_reversed();
}

int main() {
	int arr1[5] {-2, -1, 1, 2};
	asteroidCollision(arr1, 5);
	int arr2[3] {5, 10, -5};
	asteroidCollision(arr2, 3);
}