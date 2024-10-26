#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cassert>
using namespace std;
// solution at line 45
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
	string ser(TreeNode* root, vector<string>& v){
		if(!root) return "()";
		string s = "(" + to_string(root->val);
		s += ser(root->left, v);
		s += ser(root->right, v);
		s += ")";
		if(root->left || root->right)
			v.push_back(s);
		return s;
    }
	void pr(TreeNode* root){
		vector<string> v;
		ser(root, v);
		sort(v.begin(), v.end());
		string temp;
		for (int i = 0; i < v.size()-1; i++)
		{
			if(v[i] == v[i+1] && temp != v[i]){
				temp = v[i];
				cout << v[i] << endl;
			}
		}
	}
};


int main() {
	BinaryTree tree(1);
	tree.add( { 2, 3 }, { 'L', 'L'});
	tree.add( { 4, 5, 6, 8, 9 }, { 'R', 'R', 'R', 'R', 'R' });
	tree.add( { 4, 2, 3 }, { 'R', 'L', 'L'});
	tree.add( { 4, 5, 6, 7 }, { 'R', 'R', 'L', 'L'});
	tree.add( { 4, 5, 6, 8, 9 }, { 'R', 'R', 'L', 'R', 'R'});
	tree.add( { 4, 5, 6, 7 }, { 'R', 'R', 'R', 'L'});
	Solution().pr(tree.root);
}