#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<cassert>
using namespace std;
// solution at line 45 && https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/submissions/1334287034/
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
	void lev(TreeNode* root){
		deque<TreeNode*> q;
		q.push_front(root);
		int level = 1;
		while(!q.empty()){
			int itr = q.size();
			cout << "Level " << level << endl;
			while (itr--)
			{
				TreeNode* curr;
				if(level%2!=0){
					curr = q.front();
					q.pop_front();
					if(curr->left){
						q.push_back(curr->left);
					}
					if(curr->right){
						q.push_back(curr->right);
					}
				}
				else{
					curr = q.back();
					q.pop_back();
					if(curr->right)
						q.push_front(curr->right);
					if(curr->left)
						q.push_front(curr->left);
				}
					cout << curr->val << " ";
			}
			level++;
			cout << endl;
		}
	}
};


int main() {
	BinaryTree tree(3);
	tree.add( { 9 }, { 'L' });
	tree.add( { 20, 15 }, { 'R', 'L'});
	tree.add( { 20, 7 }, { 'R', 'R'});
	Solution().lev(tree.root);
}