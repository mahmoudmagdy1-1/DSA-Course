#include<iostream>
#include<stack>
#include<cassert>
using namespace std;

typedef int type;

class Stack{
private:
	int size{};
	int top1{};
	int top2{};
	type* arr{};
public:
	Stack(int size) : size(size), top1(-1), top2(size) {
		arr = new type[size];
	}
	~Stack(){
		delete[] arr;
	}
	bool isEmpty(int id){
		if(id == 1)
			return top1 == -1;
		return top2 == -1;
	}
	bool isFull(int id){
		if(id == 1)
			return top1 == size - 1;
		return top1 == 0;
	}
	void push(int id, type val){
		assert(!isFull(id));
		if(id == 1)
			arr[++top1] = val;
		else 
			arr[--top2] = val;
		
	}
	type pop(int id){
		assert(!isEmpty(id));
		if(id == 1)
			return arr[top1--];
		return arr[top2++];
	}
	type peek(int id){
		assert(!isEmpty(id));
		if(id == 1)
			return arr[top1];
		return arr[top2];
	}
	void display(){
		for (int i = top1; i >= 0; i--)
			cout << arr[i] << " ";
		cout << endl;
		for (int i = top2; i < size; i++)
			cout << arr[i] << " ";
		cout << endl;
	}
};
int main() {
	Stack stk(10);
	stk.push(2, 5);
	stk.push(2, 6);
	stk.pop(2);
	stk.push(2, 7);
	stk.push(2, 9);

	stk.push(1, 4);
	cout << stk.peek(1) << "\n";
	cout << stk.peek(2) << "\n";
	stk.push(1, 6);
	stk.push(1, 8);
	stk.push(2, 3);
	stk.display();
}