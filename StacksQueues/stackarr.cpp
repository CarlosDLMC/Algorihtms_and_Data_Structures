#include "stackarr.h"
#define MAXSIZE 3
#include <iostream>

stackarr::stackarr(){
	this->length = 0;
	this->values = new std::string[MAXSIZE];
}

void stackarr::push(std::string value){
	if(this->length == MAXSIZE){
		std::cout << "Too much elements, bitch" << std::endl;
		return;
	}
	this->values[this->length] = value;
	this->length++;
}

void stackarr::peek(){
	std::cout << this->values[this->length - 1] << std::endl;
}

void stackarr::pop(){
	this->length--;
}
