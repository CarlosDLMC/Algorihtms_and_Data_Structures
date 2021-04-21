#include "stacklist.h"
#include <iostream>

stacklist::stacklist(){
	this->isEmpty = true;
	this->top = nullptr;
	this->bottom = nullptr;
}

void stacklist::push(std::string value){
	Node* newNode = new Node(value);
	newNode->next = this->top;
	if (this->isEmpty) this->bottom = newNode;
	this->top = newNode;
	this->length++;
	this->isEmpty = false;
}

void stacklist::peek(){
	std::cout << this->top->value << std::endl;
}

void stacklist::pop(){
	this->top = this->top->next;
	if(this->top == nullptr) isEmpty = true;
}
