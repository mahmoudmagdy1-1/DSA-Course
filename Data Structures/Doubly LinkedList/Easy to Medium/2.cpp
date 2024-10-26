#include<iostream>
using namespace std;
// Solution at line 103
struct Node{
	int data{};
	Node* next {};
	Node* prev {};
	Node(int data) : data(data) {}
};

class LinkedList{
private:
	Node* head{};
	Node* tail{};
	int length = 0;
public:
	void link(Node* first, Node* second){
		if(first) first->next = second;
		if(second) second->prev = first;
	}
	void insert_end(int value){
		Node* item = new Node(value);
		if(!head)
			head = tail = item;
		else{
			link(tail, item);
			tail = item;
		}
		length++;
	}
	void insert_front(int value){
		Node* item = new Node(value);
		if(!head)
			head = tail = item;
		else{
			link(item, head);
			head = item;
		}
		length++;
	}
	void embed_after(Node* prev, int value){
		Node* item = new Node(value);
		Node* next = prev ->next;
		link(prev, item);
		link(item, next);
		length++;
	}
	void insert_sorted(int value){
		if(!length || value <= head->data)
			insert_front(value);
		else if(value >= tail->data)
			insert_end(value);
		else{
			for(Node* curr = head; curr; curr = curr->next){
				if(curr->next->data >= value){
					embed_after(curr, value);
					break;
				}
			}
		}
	}
	void delete_front(){
		if(!head)
			return;
		Node* next = head->next;
		delete head;
		head = next;
		if(head)
			head->prev = nullptr;
		else if(!length)
			tail = nullptr;
	}
	void delete_end(){
		if(!head)
			return;
		Node* prv = tail->prev;
		delete tail;
		tail = prv;
		if(tail)
			tail->next = nullptr;
		else if(!length)
			head = nullptr;
	}
	void delete_and_link(Node* cur){
		link(cur->prev, cur->next);
		delete cur;
	}
	void delete_node_with_key(int value){
		if(value == head->data)
			delete_front();
		else if(value == tail->data)
			delete_end();
		else{
			for(Node* curr = head; curr; curr = curr->next){
				if(value == curr->data){
					delete_and_link(curr);
					break;
				}
			}
		}
	}
	///////////// Solution
	void delete_even_positions(){
		for(Node* curr = head; curr && curr->next; curr = curr->next){
			delete_and_link(curr->next);
			if(!curr->next)
				tail = curr;
		}
	}
	void print(){
		for(Node* curr = head; curr; curr = curr->next){
			cout << curr->data << " ";
		}
		cout << endl;
	 }
};

int main() {
	LinkedList l1;
	l1.insert_end(1);
	l1.insert_end(2);
	l1.insert_end(3);
	l1.insert_end(4);
	l1.insert_end(5);
	l1.insert_end(6);
	l1.print();
	l1.delete_even_positions();
	l1.print();
}