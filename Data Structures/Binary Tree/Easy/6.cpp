#include<iostream>
#include<vector>
#include<cmath>
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
    bool isLeaf(TreeNode* root){
        return root && !root->right && !root->left;
    }
	int depth(TreeNode* root){
		if(!root) return 0;
		return 1 + max(depth(root->right), depth(root->left));
	}
    int is_perfect(TreeNode* root, int dep) {
		if(isLeaf(root)) return dep == 0;
		if(!root->left || !root->right) return 0;
		return is_perfect(root->left, dep - 1) && is_perfect(root->right, dep - 1);
	}
	bool is_perfect(TreeNode* root){
		return is_perfect(root, depth(root) - 1);
	}
};

int main() {
	BinaryTree tree(1);
	cout << (Solution().is_perfect(tree.root) == 1) << endl;
	tree.add( { 2 }, { 'L' });
	cout << (Solution().is_perfect(tree.root) == 0) << endl;
	tree.add( { 3 }, { 'R' });
	cout << (Solution().is_perfect(tree.root) == 1) << endl;
	tree.add( { 3, 6}, { 'R', 'R' });
	tree.add( { 3, 14 }, { 'R', 'L'});
	cout << (Solution().is_perfect(tree.root) == 0) << endl;
	tree.add( { 2, 4, 7 }, { 'L', 'L', 'L' });
	tree.add( { 2, 4, 8 }, { 'L', 'L', 'R' });
	tree.add( { 2, 5, 9 }, { 'L', 'R', 'R' });
	tree.add( { 3, 6, 15 }, { 'R', 'R', 'L' });
	cout << (Solution().is_perfect(tree.root) == 0) << endl;
	tree.add( { 2, 5, 13 }, { 'L', 'R', 'L' });
	tree.add( { 3, 6, 12 }, { 'R', 'R', 'R' });
	cout << (Solution().is_perfect(tree.root) == 0) << endl;
	tree.add( { 3, 14, 15 }, { 'R', 'L', 'L' });
	tree.add( { 3, 14, 16 }, { 'R', 'L', 'R' });
	tree.add( { 3, 14, 16, 6 }, { 'R', 'L', 'R', 'L' });
	cout << (Solution().is_perfect(tree.root) == 1) << endl;

	cout<<"bye";

}