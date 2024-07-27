#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<cassert>
using namespace std;
// solution at line 45 && https://leetcode.com/problems/check-completeness-of-a-binary-tree/submissions/1335325807/
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
	bool isCompleteTree(TreeNode* root) {
	    queue<TreeNode*> q;
		bool end = 0;
		if(root) q.push(root);
		while(!q.empty()){
			TreeNode* node = q.front();
			q.pop();
			if(!node) end = 1;
			else{
				if(end) return 0;
				q.push(node->left);
				q.push(node->right);
			}
		}
		return 1;
    }


};


int main() {
	
	BinaryTree tree(3);
	tree.add( { 9, 8 }, { 'L', 'L' });
	tree.add( { 9, 5 }, { 'L', 'R' });
	tree.add( { 20 }, { 'R' });
	//tree.add( { 20, 4 }, { 'R', 'R' });
	cout << Solution().isCompleteTree(tree.root);
}