#include<iostream>
#include<vector>
#include<cmath>
#include<cassert>
using namespace std;

struct TreeNode{
	TreeNode* left{};
	TreeNode* right{};
	int data{};
	TreeNode(int data) : data(data) {}
};

struct BinaryTree{
	TreeNode* root{};
	void _print_inorder(TreeNode* TreeNode){
		if(!TreeNode) return;
		_print_inorder(TreeNode->left);
		cout << TreeNode->data << " ";
		_print_inorder(TreeNode->right);
	}
	BinaryTree(int data) : root(new TreeNode(data)) {}
	void add(vector<int> values, vector<char> direction){
		TreeNode* temp = this->root;
		for (int i = 0; i < values.size(); i++)
		{
			if(direction[i] == 'L'){
				if(!temp->left)
					temp->left = new TreeNode(values[i]);
				temp = temp->left;
			}
			else{
				if(!temp->right)
					temp->right = new TreeNode(values[i]);
				temp = temp->right;
			}
		}
	}
	void print_inorder(){
		_print_inorder(root);
		cout << endl;
	}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        return 1 + max(maxDepth(root->right),maxDepth(root->left));
    }
};

int main() {
	BinaryTree tree(1);
	tree.add( { 2, 4, 7 }, { 'L', 'L', 'L' });
	tree.add( { 2, 4, 8 }, { 'L', 'L', 'R' });
	tree.add( { 2, 5, 9 }, { 'L', 'R', 'R' });
	tree.add( { 3, 6, 10 }, { 'R', 'R', 'L' });

	cout << Solution().maxDepth(tree.root) << " ";
}