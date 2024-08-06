#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cassert>
using namespace std;
// solution at line 40 && https://leetcode.com/problems/validate-binary-search-tree/submissions/1346518152/
struct TreeNode{
	TreeNode* left{};
	TreeNode* right{};
	int val{};
	TreeNode(int val) : val(val) {}
};

struct BinarySearchTree{
	TreeNode* root{};
	BinarySearchTree(int val) : root(new TreeNode(val)) {}
	void _print_inorder(TreeNode* TreeNode){
		if(!TreeNode) return;
		_print_inorder(TreeNode->left);
		cout << TreeNode->val << " ";
		_print_inorder(TreeNode->right);
	}
	TreeNode* __insert(TreeNode* root, int target){
		if(!root) root = new TreeNode(target);
		if(target < root->val)
			root->left = __insert(root->left, target);
		if(target > root->val)
			root->right = __insert(root->right, target);
		return root;
	}
	void insert(int target){
		root = __insert(root, target);
	}
	void print_inorder(){
		_print_inorder(root);
		cout << endl;
	}
}; 
class Solution {
public:
	bool isValidBST(TreeNode* root, long long mn = LONG_LONG_MIN, long long mx = LONG_LONG_MAX){
        if(!(root->val > mn && root->val < mx)) return 0;
        bool status = !root->left || isValidBST(root->left, mn, root->val);
        if(!status) return 0;
        status = !root->right || isValidBST(root->right, root->val, mx);
        return status;
    }
};

int main() {
}