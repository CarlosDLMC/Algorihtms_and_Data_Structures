#include "cola.h"

cola::cola(){
	this->last = nullptr;
	this->first = nullptr;
}

void cola::enqueue(std::string value){
	std::shared_ptr<smartnode> newNode {new smartnode(value)};
	if(this->first == nullptr) this->first = newNode;
	if(this->last != nullptr) this->last->next = newNode;
	this->last = newNode;
}

void cola::peek(){
	std::cout << this->first->value << std::endl;
}

void cola::dequeue(){
	this->first = std::move(this->first->next);
	if(this->first == nullptr) this->last = nullptr;
}
