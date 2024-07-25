#include<iostream>
#include<vector>
#include<stack>
#include<cmath>
#include<cassert>
using namespace std;
// solution at line 45 && https://leetcode.com/problems/diameter-of-binary-tree/submissions/1333315602/
struct TreeNode{
	TreeNode* left{};
	TreeNode* right{};
	int val{};
	TreeNode(int val) : val(val) {}
};

struct BinaryTree{
	TreeNode* root{};
	BinaryTree(int val) : root(new TreeNode(val)) {}
	void _print_inorder(TreeNode* TreeNode){
		if(!TreeNode) return;
		_print_inorder(TreeNode->left);
		cout << TreeNode->val << " ";
		_print_inorder(TreeNode->right);
	}
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
	int diam = 0;
    int height(TreeNode* root){
		if(!root) return 0;
		int l = height(root->left);
		int r = height(root->right);
		diam = max(diam, l + r);
		return 1 + max(l, r);
	}
	int diameterOfBinaryTree(TreeNode* root){
		if(!root) return 0;
		height(root);
		return diam;
	}
};

int main() {
	BinaryTree tree(1);
	tree.add( { 3 }, { 'R' });
	tree.add( { 2, 5}, { 'L', 'R' });
	tree.add( { 2, 4 }, { 'L', 'L'});
	cout << (Solution().diameterOfBinaryTree(tree.root)) << endl;
}