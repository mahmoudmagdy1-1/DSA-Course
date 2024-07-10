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
				postfix += s.pop();
			}
			s.push(infix[i]);
		}
	}
	return postfix;
}

double operations(double a, double b, char sign){
	if(sign == '+') return a + b;
	if(sign == '-') return a - b;
	if(sign == '/') return a / b;
	if(sign == '*') return a * b;
	return pow(a, b);
}

double evaluate_postfix(string postfix){
	Stack s;
	for (int i = 0; i < postfix.size(); i++)
	{
		if(isdigit(postfix[i])) 
			s.push(postfix[i] - '0');
		else{
			double temp = s.pop();
			s.push(operations(s.pop(), temp, postfix[i]));
		}
	}
	return s.pop();
}

int main() {
	cout << evaluate_postfix("52/") << endl;
	cout << evaluate_postfix("12+3+") << endl;
	cout << evaluate_postfix("123*+") << endl;
	cout << evaluate_postfix("23*4+") << endl;
	cout << evaluate_postfix("135*+72/-") << endl;
	cout << evaluate_postfix("432^^") << endl;
}