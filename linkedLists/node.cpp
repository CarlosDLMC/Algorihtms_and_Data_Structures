#include "node.h"
#include <iostream>

Node::Node(int value){
	this->value = value;
	this->node = nullptr;
}

void Node::append(int value){
	Node* node = this;
	while(node->node != nullptr){
		node = node->node.get();
	}
	node->node = std::make_unique<Node>(value);
}

void Node::print(){
	Node* node = this;
	std::cout << "[ ";
	do{
		std::cout << node->value << " ";
		node = node->node.get();
	}while(node != nullptr);
	std::cout << "]\n";
}

void Node::pop(){
	if(this->node == nullptr) return;
	Node* node = this;
	while(node->node->node != nullptr){
		node = node->node.get();
	}
	node->node.reset();
}

void Node::prepend(int value){
	std::unique_ptr<Node> temp = std::make_unique<Node>(this->value);
	temp->node = std::move(this->node);
	this->value = value;
	this->node = std::move(temp);

}

void Node::insert(int index, int value){
	int i = 0;
	Node* node = this;
	std::unique_ptr<Node> newNode = std::make_unique<Node>(value);
	if(index == 0){
		this->prepend (value);
		return;
	}
	while(i != index - 1){
		node = node->node.get();
		i++;
	}
	newNode->node = std::move(node->node);
	node->node = std::move(newNode);
}

void Node::remove(int index){
	Node* randomNode = this;
	int i = 0;
	if(index == 0){
		randomNode->value = randomNode->node->value;
		randomNode->node = std::move(randomNode->node->node);
		return;
	}
	while(i != index - 1){
		randomNode = randomNode->node.get();
		i++;
	}

	randomNode->node = std::move(randomNode->node->node);

}


std::unique_ptr<Node> Node::reverse() {
	std::unique_ptr<Node> next;
	Node* current = this;
	std::unique_ptr<Node> previous;
	while(current != nullptr){
		next = std::move(current->node);
		current->node = std::move(previous);
		previous = std::make_unique<Node>(current->value);
		previous->node = std::move(current->node);
		current = next.get();

	}
	return previous;
}

void Node::reverseArr(){
	int count = 1;
	Node* node = this;
	while(node->node != nullptr){
		count++;
		node = node->node.get();
	}
	node = this;
	int* values = new int[count];
	count--;
	while(node->node != nullptr){
		values[count] = node->value;
		node = node->node.get();
		count--;
	}
	values[count] = node->value;
	for(node = this; node != nullptr; node = node->node.get()) node->value = values[count++];
	delete [] values;
}
