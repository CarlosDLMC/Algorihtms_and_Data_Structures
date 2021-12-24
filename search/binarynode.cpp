#include "binarynode.h"

binaryNode::binaryNode(int value)
{
	this->value = value;
}

void binaryNode::insert(int value){
	binaryNode* node = this;
	while(true){
		if(value > node->value){
			if(node->right){
				node = node->right;
			}else{
				node->right = new binaryNode(value);
				break;
			}
		}else if(value < node->value){
			if(node->left){
				node = node->left;
			}else{
				node->left = new binaryNode(value);
				break;
			}
		}else{
			return;
		}
	}
}
