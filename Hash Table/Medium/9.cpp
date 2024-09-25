#include<iostream>
#include<unordered_set>
#include<algorithm>
using namespace std;

struct Node
{
	int data{};
	Node* next{};
	Node(int data) : data(data) {}
};


class LinkedList{
private:
	Node* head{};
	Node* tail{};
	int len = 0;
public:
	void print(){
		for (Node* curr = head; curr; curr = curr->next)
			cout << curr->data << " ";
		cout << endl;
	}
	void insert_end(int val){
		if(!head) {
			head = tail = new Node(val);
		}
		else{
			Node* temp = new Node(val);
			tail->next = temp;
			tail = temp;
		}
	}
	void create_cycle(){
		for (int i = 0; i < 4; ++i)
			insert_end(i);
		Node* now = tail; 
		for (int i = 0; i < 3; ++i)
			insert_end(14 + i);
		tail->next = now;
	}
	void remove_cycle(){
		//tail->next = nullptr;
		unordered_set<Node*> nodes;
		for (Node* curr = head, *prev = nullptr; curr; prev = curr, curr = curr->next)
		{
			if(nodes.count(curr)){
				prev->next = nullptr;
				tail = prev;
				return;
			}
			nodes.insert(curr);
		}	
	}
};

int main() {
	LinkedList lst;
	lst.create_cycle();
	lst.remove_cycle();
	lst.print();
}