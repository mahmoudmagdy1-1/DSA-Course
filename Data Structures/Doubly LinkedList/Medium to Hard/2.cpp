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
	
	int length = 0;
public:
	Node* head{};
	Node* tail{};
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
	Node* get_nth(int idx){
		int i = 1;
		for (Node* curr = head; curr; curr = curr->next, i++)
		{
			if(i == idx) return curr;
		}
		return nullptr;
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
	void swap_forward_with_backward(int k){
		int back_k = length - k + 1;
		if(k > length || back_k == k)
			return;
		Node* h = get_nth(k), *t = get_nth(back_k);
		Node* htemp = h->next;
		Node* hprev = h->prev;
		Node* ttemp = t->next;
		Node* tprev = t->prev;
		if(k+1 == back_k)
		{
			link(h->prev, t);
			link(t, h);
			link(h, ttemp);
		}
		else{
			link(h->prev, t);
			link(t, htemp);
			link(tprev, h);
			link(h, ttemp);
		}
		if(k == 1){
			swap(head, tail);
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
	l1.insert_end(6);
	l1.insert_end(10);
	l1.insert_end(12);
	l1.insert_end(13);
	l1.insert_end(15);
	l1.insert_end(17);
	l1.print();
	l1.swap_forward_with_backward(1);
	l1.print();
}