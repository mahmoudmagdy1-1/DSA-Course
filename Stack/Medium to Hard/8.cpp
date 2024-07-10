#include<iostream>
#include<cassert>
#include<cmath>
using namespace std;

typedef double type;

class Stack{
private:
	struct Node{
		type data;
		Node* next{};
		Node(type data): data(data) {}
	};
	Node* head{};
public:
	bool isEmpty(){
		return !head;
	}
	void push(type val){
		Node* item = new Node(val);
		item->next = head;
		head = item;
	}
	type pop(){
		assert(!isEmpty());
		type element = head->data;
		Node* next = head->next;
		delete head;
		head = next;
		return element;
	}
	type peek(){
		assert(!isEmpty());
		return head->data;
	}
	Node* get_mid(){
		Node* mid = head;
		for (Node* fast = head; fast && fast->next; mid = mid->next, fast = fast->next->next){}
		return mid;
	}
	void display(){
		Node* mid = get_mid();
		for (Node* curr = head; curr; curr = curr->next){
			if(curr == mid){
				cout << "[" << curr->data << "] ";
			}
			else cout << curr->data << " ";
		}
		cout << endl;
	}
};
int main() {
	Stack stk;
	for (int i = 0; i < 10; i++)
	{
		stk.push(i);
		stk.display();
	}
	while(!stk.isEmpty()){
		stk.pop();
		stk.display();
	}
}