#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void width(TreeNode* root){
	queue<TreeNode*> currentlevel;
	queue<TreeNode*> nextlevel;
	TreeNode* node = root;
	vector<int> res;
	currentlevel.push (node);
	while(!currentlevel.empty () || !nextlevel.empty ()){
		res.push_back (currentlevel.front ()->val);
		while(!currentlevel.empty ()){
			node = currentlevel.front ();
			currentlevel.pop ();
			cout << node->val << endl;
			if(node->right) nextlevel.push (node->right);
			if(node->left) nextlevel.push (node->left);
		}
		while(!nextlevel.empty ()){
			currentlevel.push (nextlevel.front ());
			nextlevel.pop ();
		}
	}
	cout << "vistos a la derecha: " << endl;
	for(int n : res) cout << n << " ";
	cout << endl;
}

void markvisited(vector<vector<char>>& grid,int y,int x,int ymax,int xmax){
	if(x < 0 || y < 0 || y >= ymax || x >= xmax || grid[y][x] != '1'){
		return;
	}
	grid[y][x] = '2';
	markvisited(grid, y + 1, x, ymax, xmax);
	markvisited(grid, y - 1, x, ymax, xmax);
	markvisited(grid, y, x + 1, ymax, xmax);
	markvisited(grid, y, x - 1, ymax, xmax);
}
int numIslands(vector<vector<char>>& grid) {
	int rows = grid.size();
	int columns = grid[0].size();
	int islands = 0;
	for(int y = 0; y < rows; y++){
		for(int x = 0; x < columns; x++){
			if(grid[y][x] == '1'){
				markvisited(grid, y, x, rows, columns);
				islands++;
			}
		}
	}
	return islands;
}

bool isHappy(int n) {
	int count = 0;
	string s;
	int res {};
	int current = n;
	while(count < 10){
		res = 0;
		s = to_string(current);
		for(char c : s){
			res += (c - '0') * (c - '0');
		}
		if(res == 1) return true;
		current = res;
		count++;
	}
	return false;

}
int main()
{
	cout << "Ejercicio 1: " << endl;
	TreeNode* root = new TreeNode(100);
	root->left = new TreeNode(50);
	root->right = new TreeNode(150);
	root->left->left = new TreeNode(25);
	root->left->right = new TreeNode(75);
	root->right->left = new TreeNode(125);
	root->right->right = new TreeNode(175);
	width(root);
	cout << "Ejercicio 2: " << endl;
	vector<vector<char>> grid = {
		{'0', '0', '0', '2', '1'},
		{'0', '0', '0', '1', '1'},
		{'0', '0', '0', '1', '1'},
		{'0', '0', '0', '1', '1'},
		{'0', '0', '0', '1', '1'},
	};
	cout << numIslands(grid) << endl;
	cout << "Ejercicio 3:" << endl;
	cout << boolalpha;
	cout << isHappy (2) << endl;
	cout << "Probando mierdas de bits  demas cosas" << endl;
	for(int n = 0; n < 10; n++){
		cout << n << ": " << (n & 1) << endl;
	}
	return 0;
}
