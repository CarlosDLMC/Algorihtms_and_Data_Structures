#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include "binarynode.h"
#include <iomanip>

using namespace std;

template<class container>
void printElements(container& c){
	for(auto it = c.begin(); it != c.end(); it++){
		cout << *it << " ";
	}
	cout << endl;
}

void printNode(binaryNode* bn){
	cout << bn->value << endl;
	if(bn->left) printNode(bn->left);
	if(bn->right) printNode(bn->right);
}

void breadth(binaryNode* bn){
	binaryNode* node;
	binaryNode* current;
	node = new binaryNode(bn->value);
	node->right = bn->right;
	node->left = bn->left;
	queue<binaryNode*> currentlevel;
	currentlevel.push (node);
	while(!currentlevel.empty ()){
		current = currentlevel.front ();
		if(current->left) currentlevel.push (current->left);
		if(current->right) currentlevel.push (current->right);
		cout << current->value << endl;
		currentlevel.pop ();
	}
}
//	cout << nextlevel.front()->value << endl;
//	nextlevel.pop ();
//	cout << nextlevel.front ()->value << endl;
void brrecursive(queue<binaryNode*> cola){
	if(cola.empty ()) return;
	cout << cola.front ()->value << endl;
	if(cola.front ()->left) cola.push (cola.front()->left);
	if(cola.front ()->right) cola.push (cola.front ()->right);
	cola.pop ();
	brrecursive(cola);

}

void breadthrecursive(binaryNode* bn){
	queue<binaryNode*> cola;
	cola.push(bn);
	brrecursive(cola);
}

void inOrder(binaryNode* bn){
	binaryNode* current = bn;
	stack<binaryNode*> st;
	while(!st.empty () || current){
		if(current){
			st.push (current);
			current = current->left;
		}else{
			current = st.top ();
			st.pop ();
			cout << current->value << endl;
			current = current->right;
		}
	}
}

void postOrder(binaryNode* bn){
	if(bn->left)
		postOrder (bn->left);
	if(bn->right)
		postOrder (bn->right);

	cout << bn->value << endl;

}

void iterative(binaryNode* bn){
	binaryNode* current = bn;
	stack<binaryNode*> st;
	st.push (current);
	while(!st.empty ()){
		current = st.top ();
		st.pop();
		cout << current->value << " ";
		if(current->left) st.push (current->left);
		if(current->right) st.push (current->right);
	}
	cout << endl;

}

bool search(vector<int> v, int n){
	int min = 0;
	int max = v.size();
	int size = max;
	int index = (max - min) / 2;
	int count = 0;
	while(min < max && count < size){
		if(n == v[index]){
			return true;
		}else if(n > v[index]){
			min = index;
		}else{
			max = index;
		}
		count++;
		index = min + (max - min) / 2;
	}
	return false;

}


int main(){
	binaryNode* bn = new binaryNode(9);
	bn->insert (6);
	bn->insert (34);
	bn->insert (1);
	bn->insert (8);
	bn->insert (12);
	bn->insert (45);
//			9
//		6		34
//	1	   8  12   45
	cout << "a lo ancho:" << endl;
	breadth (bn);
	cout << "a lo ancho recursivo: " << endl;
	breadthrecursive(bn);
	cout << "a lo alto recursivo: " << endl;
	printNode(bn);
	cout << "el otro recursivo" << endl;
	postOrder (bn);
	cout << "en orden: " << endl;
	inOrder(bn);
	cout << "Iterativamente: " << endl;
	iterative(bn);
//	printNode(bn);
	cout << "ahora vamos a probar a buscar en una lista" << endl;
	vector<int> v = {1, 5, 7, 9, 10, 12, 16, 17, 19, 21, 26, 29};
	cout << boolalpha;
	for(int n = 0; n < 30; n++)
		cout << "is " << n << " in v?: " << search(v, n) << endl;

}
