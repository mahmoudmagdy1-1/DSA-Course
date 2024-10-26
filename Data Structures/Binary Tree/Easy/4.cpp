#include<iostream>
#include<vector>
#include<cmath>
#include<cassert>
using namespace std;
// solution at line 45 && https://leetcode.com/problems/sum-of-left-leaves/submissions/1329368334/
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
    bool isLeaf(TreeNode* root){
        return !root->right && !root->left;
    }
    int sumOfLeftLeaves(TreeNode* root, int sum = 0) {
        if(!root) return 0;
		if(root->left && isLeaf(root->left))
			sum += root->left->val;
		sum += sumOfLeftLeaves(root->left);
		sum += sumOfLeftLeaves(root->right);
		return sum;
	}
};

int main() {
	BinaryTree tree(1);
	tree.add( { 2, 4, 7 }, { 'L', 'L', 'L' });
	tree.add( { 2, 4, 8 }, { 'L', 'L', 'R' });
	tree.add( { 2, 5, 9 }, { 'L', 'R', 'R' });
  	tree.add( { 3, 6, 10 }, { 'R', 'R', 'L' });
	cout << Solution().sumOfLeftLeaves(tree.root) << endl;
}