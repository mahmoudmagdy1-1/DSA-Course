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
	TreeNode* _bstFromPreorder(vector<int>& preorder, int& i, int mn, int mx) {
        if(i == preorder.size()) return nullptr;
        int data = preorder[i++];
        TreeNode* root = new TreeNode(data);
        if(preorder.size() > i && preorder[i] > mn && preorder[i] < mx && preorder[i] < data)
            root->left = _bstFromPreorder(preorder, i, mn, data);
        if(preorder.size() > i && preorder[i] > mn && preorder[i] < mx && preorder[i] > data)
            root->right = _bstFromPreorder(preorder, i, data, mx);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int it = 0;
        return _bstFromPreorder(preorder, it, 0, 1e4);
    }
};

int main() {
}