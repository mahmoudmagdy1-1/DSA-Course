#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cassert>
using namespace std;
// solution at line 40 && https://leetcode.com/submissions/detail/1337726226/
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
    TreeNode* searchBST(TreeNode* root, int val){
        if(!root) return nullptr;
        if(root->val == val) return root;
        if(root->val < val) return searchBST(root->right, val);
        if(root->val > val) return searchBST(root->left, val);
        return root;
    }
	/* TreeNode* searchBST(TreeNode* root, int val){
        while(root && root->val != val){
            if(root->val < val) root = root->right;
            else root = root->left;
        }
        return root;
    } */
};


int main() {
}