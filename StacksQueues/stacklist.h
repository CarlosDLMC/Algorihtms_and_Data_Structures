#ifndef STACKLIST_H
#define STACKLIST_H
#include "node.h"
#include <iostream>

class stacklist
{
public:
	Node* top;
	Node* bottom;
	int length;
	stacklist();
	void peek();
	void push(std::string value);
	void pop();
	bool isEmpty;
};

#endif // STACKLIST_H
