#include "dict.h"
#include <iostream>

dict::dict(int size){
	this->data = new int[size];
	this->size = size;
}

int dict::hash(std::string key){
	int res = 0;
	for(unsigned int i = 0; i < key.size (); i++){
		res = (res + key.at(i) * i) % this->size;
	}
	return res;
}

void dict::set(std::string key, int value){
	int index = dict::hash(key);
	this->data[index] = value;
}

int dict::get(std::string key){
	int index = dict::hash(key);
	return this->data[index];
}
