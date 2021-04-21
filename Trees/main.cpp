#include <iostream>
#include "binarynode.h"

using namespace std;


void printTree(const binaryNode &node){
	std::cout << node.value << std::endl;
	if (node.left)
		printTree(*node.left);
	if (node.right)
		printTree(*node.right);
}

int main(){
	binaryNode* bn = new binaryNode(9);
	bn->insert(4);
	bn->insert(20);
	bn->insert(1);
	bn->insert(6);
	bn->insert(15);
	bn->insert(70);
	bn->insert(50);
	bn->insert(99);
	bn->insert(60);
	bn->insert(55);
	bn->insert(65);
	cout << "Antes de eliminar" << endl;
	printTree(*bn);
	cout << "Probemos a quitar el 20" << endl;
	bn->remove (20);
	printTree(*bn);
	cout << bn->right->value << endl;
	cout << "Hasta aqui todo bien" << endl;
	cout << "A la izquierda del 50 debe de haber un 15. Hay: " << bn->right->left->value << endl;
	cout << "A la izquierda del 50 debe de haber un 70. Hay: " << bn->right->right->value << endl;
	cout << "A la izquierda del 70 debe de haber un 60. Hay: " << bn->right->right->left->value << endl;
	cout << "A la derecha del 70 debe de haber un 99. Hay: " << bn->right->right->right->value << endl;
	cout << "A la izquierda del 60 debe de haber un 55. Hay: " << bn->right->right->left->left->value << endl;
	cout << "A la derecha del 60 debe de haber un 65. Hay: " << bn->right->right->left->right->value << endl;
	return 0;
}
