#include<iostream>
#include<vector>
#include<cmath>
#include<cassert>
using namespace std;

struct Node{
	Node* left{};
	Node* right{};
	int data{};
	Node(int data) : data(data) {}
};

struct BinaryTree{
	Node* root{};
	void _print_inorder(Node* node){
		if(!node) return;
		_print_inorder(node->left);
		cout << node->data << " ";
		_print_inorder(node->right);
	}
	BinaryTree(int data) : root(new Node(data)) {}
	void add(vector<int> values, vector<char> direction){
		Node* temp = this->root;
		for (int i = 0; i < values.size(); i++)
		{
			if(direction[i] == 'L'){
				if(!temp->left)
					temp->left = new Node(values[i]);
				temp = temp->left;
			}
			else{
				if(!temp->right)
					temp->right = new Node(values[i]);
				temp = temp->right;
			}
		}
	}
	void print_inorder(){
		_print_inorder(root);
		cout << endl;
	}
};

class Solution{
public:
	// sol 1
	/* int tree_max(Node* node){
		if(!node) return 0;
		return max(tree_max(node->left), max(tree_max(node->right),node->data));
	} */
	// sol 2
	int tree_max(Node* node){
		if(!node) return 0;
		int MAX = node->data;
		MAX = max(MAX, tree_max(node->left));
		MAX = max(MAX, tree_max(node->right));
		return MAX;
	}
};

int main() {
	BinaryTree tree(1);
	tree.add( { 2, 4, 7 }, { 'L', 'L', 'L' });
	cout << Solution().tree_max(tree.root) << " ";
	tree.add( { 2, 4, 8 }, { 'L', 'L', 'R' });
	cout << Solution().tree_max(tree.root) << " ";
	tree.add( { 2, 5, 9 }, { 'L', 'R', 'R' });
	cout << Solution().tree_max(tree.root) << " ";
	tree.add( { 3, 6, 10 }, { 'R', 'R', 'L' });
	cout << Solution().tree_max(tree.root) << " ";
}