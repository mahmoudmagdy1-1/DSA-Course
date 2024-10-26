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
	void print(){
		for (Node* curr = head; curr; curr = curr->next)
			cout << curr->data << " ";
		cout << endl;
	}
};

int presedence(char c){
	if(c == '^')
		return 3;
	if(c == '*' || c == '/')
		return 2;
	else if(c == '+' || c == '-')
		return 1;
	else return 0;
}

string infix_to_postfix(string infix){
	string postfix = "";
	Stack s;
	infix += '+';
	s.push('!');
	for (int i = 0; i < infix.size(); i++)
	{
		if(isdigit(infix[i]))
			postfix += infix[i];
		else if(infix[i] == '(')
				s.push('(');
		else if(infix[i] == ')'){
			while(s.peek() != '('){
				postfix += s.pop();
			}
			s.pop();
		}
		else{
			while(presedence(infix[i]) <= presedence(s.peek())){
				if(presedence(infix[i]) == presedence(s.peek()) && presedence(infix[i]) == 3) break;
				postfix += s.pop();
			}
			s.push(infix[i]);
		}
	}
	return postfix;
}

int main() {
	cout << infix_to_postfix("4^3^2") << endl;
	cout << infix_to_postfix("5+4^3") << endl;
	cout << infix_to_postfix("1+2^3^4*5-6") << endl;
}