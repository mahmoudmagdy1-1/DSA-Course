#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode{
	int data{};
	TreeNode* right{};
	TreeNode* left{};
	TreeNode(int data) : data(data) {}
};

struct BinaryTree{
	TreeNode* root;
	BinaryTree(int data) : root(new TreeNode(data)) {}
	void add(vector<char> ch, vector<int> val){
		TreeNode* curr = root;
		for (int i = 0; i < ch.size(); i++)
		{
			if(ch[i] == 'L'){
				if(!curr->left) curr->left = new TreeNode(val[i]);
				curr = curr->left;
			}
			else if(ch[i] == 'R'){
				if(!curr->right) curr->right = new TreeNode(val[i]);
				curr = curr->right;
			}
			else break;
		}
	}
	void print(TreeNode* root){
		if(!root) return;
		print(root->left);
		cout << root->data << " ";
		print(root->right);
	}
	void level_order_traversal_sorted(){

	}
	void level_order_traversal(TreeNode* root){
		queue<TreeNode*> q;
		priority_queue<int> pq;
		int levels = 0;
		q.push(root);
		while(!q.empty()){
			int sz = q.size();
			cout << "Level " << ++levels  << " :";
			while(sz--){
				TreeNode* curr = q.front();
				q.pop();
				pq.push(curr->data);
				if(curr->left) q.push(curr->left);
				if(curr->right) q.push(curr->right);
			}
			while(!pq.empty()){
				cout << pq.top() << " ";
				pq.pop();
			}
			cout << endl;
		}
	}
};

int main() {
	BinaryTree tree(25);
	tree.add({'L', 'L'}, {3, 5});
	tree.add({'R', 'L'}, {7, 30});
	tree.add({'R', 'R'}, {7, 6});
	tree.level_order_traversal(tree.root);
}

