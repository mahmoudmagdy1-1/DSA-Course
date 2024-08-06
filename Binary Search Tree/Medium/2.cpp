#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cassert>
using namespace std;
// solution at line 40 && https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/submissions/1337542368/
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
	bool chain(TreeNode*& root, int val, vector<TreeNode*>& ch) {
		if (!root) return false;
		ch.push_back(root);
		if (root->val == val) return true;
		if (root->val > val) return chain(root->left, val, ch);
		return chain(root->right, val, ch);
	}

	TreeNode* minVal(TreeNode* node) {
		TreeNode* current = node;
		while (current && current->left != NULL) {
			current = current->left;
		}
		return current;
	}

	pair<bool, TreeNode*> succ(TreeNode* root, int val) {
		vector<TreeNode*> ch;
		if (chain(root, val, ch)) {
			TreeNode* targetNode = ch.back();
			if (targetNode->right) return {true, minVal(targetNode->right)};
			for (int i = ch.size() - 2; i >= 0; --i) {
				if (ch[i]->val > val) {
					return {true, ch[i]};
				}
			}
			return {false, nullptr};
		}
		return {false, nullptr};
	}

	TreeNode* _delete_node(TreeNode* root, int val){
		if(!root) return nullptr;
		if(root->val > val)
			root->left = _delete_node(root->left, val);
		else if(root->val < val)
			root->right = _delete_node(root->right, val);
		else{
			TreeNode* tmp = root;
			if(!root->left && !root->right)
				root = nullptr;
			else if(!root->left)
				root = root->right;
			else if(!root->right)
				root = root->left;
			else{
				root->val = minVal(root->right)->val;
				root->right = _delete_node(root->right, root->val);
				tmp = nullptr;
			}
			if(tmp)
				delete tmp;
		}
		return root;
	}
	void delete_node(TreeNode* root, int val){
		root = _delete_node(root, val);
	}
};

int main() {
	BinarySearchTree tree(50);
	tree.insert(60);
	tree.insert(20);
	tree.insert(10);
	tree.insert(45);
	tree.insert(60);
	tree.insert(70);
	tree.insert(73);
	tree.insert(35);
	tree.print_inorder();
	Solution().delete_node(tree.root, 50);
	tree.print_inorder();

}