#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cassert>
using namespace std;
// solution at line 40 && https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/submissions/1337392805/
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
	TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(nums, 0, nums.size()-1);
    }
    TreeNode* sortedArrayToBST(vector<int>& nums, int start, int end) {
        if(start > end) return nullptr;
        int mid = (start + end)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = sortedArrayToBST(nums, start, mid - 1);
        root->right = sortedArrayToBST(nums, mid + 1, end);
        return root;
    }
};


int main() {
	
}