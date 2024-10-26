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
	void merge_2sorted_lists(LinkedList &other){
		Node* cur1 = head;
		Node* cur2 = other.head;
		Node* prv = nullptr;
		while(cur1 && cur2){
			Node* next = cur1->next;
			Node* temp = cur2->next;
			if(cur2->data <= cur1->data){
				if(!prv){
					head = cur2;
					link(prv, cur2);
					link(cur2, cur1);
					prv = cur2;
				}
				else{
					link(prv, cur2);
					link(cur2, cur1);
					prv = cur2;
				}
				cur2 = temp;
			}
			else prv = cur1, cur1 = next;
			
		}
		if(cur2) link(prv, cur2);
	}
	void print(){
		for(Node* curr = head; curr; curr = curr->next){
			cout << curr->data << " ";
		}
		cout << endl;
	}
	void print_reversed(){
		for(Node* curr = tail; curr; curr = curr->prev){
			cout << curr->data << " ";
		}
		cout << endl;
	}
};

int main() {
	LinkedList l1;
	l1.insert_end(2);
	l1.insert_end(4);
	l1.insert_end(8);
	l1.insert_end(12);
	l1.insert_end(25);
	l1.insert_end(64);

	LinkedList l2;
	l2.insert_end(2);
	l2.insert_end(3);
	l2.insert_end(5);
	l2.insert_end(10);
	l2.insert_end(20);
	l2.insert_end(25);
	l2.insert_end(45);
	l2.insert_end(79);
	
	l1.print();
	l1.merge_2sorted_lists(l2);
	l1.print();
}