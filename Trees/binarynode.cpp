#include "binarynode.h"

binaryNode::binaryNode(int value)
{
	this->value = value;
	this->right = nullptr;
	this->left = nullptr;
}

void binaryNode::insert(int value){
	binaryNode* node = this;
	while(true){
		if(value > node->value){
			if(node->right != nullptr){
				node = node->right;
			}else{
				node->right = new binaryNode{value};
				break;
			}
		}else if(value < node->value){
			if(node->left != nullptr){
				node = node->left;
			}else{
				node->left = new binaryNode{value};
				break;
			}
		}else{
			return;
		}
	}
}

bool binaryNode::exists(int value){
	binaryNode* node = this;
	while(true){
		if(node->value == value){
			return true;
		}else if(value > node->value){
			node = node->right;
		}else if(value < node->value){
			node = node->left;
		}
		if(node == nullptr) return false;
	}

}

void binaryNode::remove(int value){
	binaryNode* search = this;
	binaryNode* sucesor;
	while(search->right->value != value && search->left->value != value){
		if(value > search->value){
			search = search->right;
		}else if(value < search->value){
			search = search->left;
		}
		if(search->right == nullptr && search->left == nullptr){
			std::cout << "Value " << value << " does not exist in the tree" << std::endl;
			return;
		}
	}
	if(search->right->value == value){
		binaryNode* temp = search->right;
		sucesor = search->right;
		if(sucesor->right == nullptr && sucesor->left == nullptr) {
			search->right = nullptr;
			delete search->right;
			return;
		}
		else if(sucesor->right == nullptr && sucesor->left != nullptr){
			search->right = sucesor->left;
			return;
		}
		else if(sucesor->right != nullptr && sucesor->left == nullptr){
			search->right = sucesor->right;
			return;
		}
		else{
			// temp es el que vamos a borrar, elegido estara en su lugar, sucesor apuntaba a elegido
			binaryNode* elegido;
			elegido = sucesor->right;
			while(elegido->left != nullptr){
				sucesor = elegido;
				elegido = elegido->left;
			}
			search->right = elegido;
			elegido->left = temp->left;
			sucesor->left = elegido->right;
			elegido->right = temp->right;
			delete temp;
		}
	}
	else{
		binaryNode* temp = search->right;
		sucesor = search->left;
		if(sucesor->right == nullptr && sucesor->left == nullptr) {
			search->left = nullptr;
			delete search->left;
			return;
		}
		else if(sucesor->right == nullptr && sucesor->left != nullptr){
			search->left = sucesor->left;
			return;
		}
		else if(sucesor->right != nullptr && sucesor->left == nullptr){
			search->left = sucesor->right;
			return;
		}
		else{
			// temp es el que vamos a borrar, elegido estara en su lugar, sucesor apuntaba a elegido
			binaryNode* elegido;
			elegido = sucesor->left;
			while(elegido->right != nullptr){
				sucesor = elegido;
				elegido = elegido->right;
			}
			search->left = elegido;
			elegido->right = temp->right;
			sucesor->right = elegido->left;
			elegido->left = temp->left;
		}
	}
}
