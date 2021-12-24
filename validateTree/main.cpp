#include <iostream>
#include <iomanip>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool isValidNode(TreeNode* root){
	if(!root->left && !root->right){
		return true;
	}else if(!root->right){
		return (root->val > root->left->val);
	}else if(!root->left){
		return (root->val < root->right->val);
	}else{
		return (root->val > root->left->val && root->val < root->right->val);
	}
}

bool isValid(TreeNode* tn){
	queue<TreeNode*> cola;
	TreeNode* current = tn;
	cola.push (current);
	while(!cola.empty ()){
		current = cola.front ();
		cola.pop ();
		if(!isValidNode(current)) return false;
//		cout << isValidNode (current) << endl;
		if(current->right) cola.push (current->right);
		if(current->left) cola.push (current->left);
	}
	return true;
}

int main()
{
	TreeNode* tn = new TreeNode(5);
	tn->left = new TreeNode(1);
	tn->right = new TreeNode(4);
	tn->right->left = new TreeNode(3);
	tn->right->right = new TreeNode(6);
	cout << boolalpha;
	cout << "is tn valid?: " << isValid(tn) << endl;
//	isValid(tn);
	return 0;
}
