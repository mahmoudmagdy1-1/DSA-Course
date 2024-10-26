#include<iostream>
using namespace std;

class Stack{
private:
	int size{};
	int added_elements{};
	int* arr{};
public:
	Stack(int size) : size(size){
		arr = new int[size];
	}
	bool isEmpty(){
		return !added_elements;
	}
	bool isFull(){
		return added_elements == size;
	}
	bool push(int val){
		if(isFull()) return 0;
		for (int i = added_elements - 1; i >= 0; i--)
			arr[i+1] = arr[i];
		arr[0] = val;
		added_elements++;
		return 1;
	}
	bool pop(){
		if(isEmpty()) return 0;
		for (int i = 0; i < added_elements; i++)
			arr[i] = arr[i+1];		
		added_elements--;
		return 1;
	}
	bool peek(){
		if(isEmpty()) return 0;
		return 1;
	}
	void print(){
		for (int i = 0; i < added_elements; i++)
			cout << arr[i] << " ";
		cout << endl;
	}
};

int main() {
	Stack s1(5);
	s1.push(1);
	s1.push(2);
	s1.push(3);
	s1.push(4);
	cout << s1.push(5) << " ";
	cout << s1.push(6) << " ";
	cout << "\n";
	s1.print();
	s1.pop();
	s1.print();
	s1.isEmpty();
}
