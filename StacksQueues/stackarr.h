#ifndef STACKARR_H
#define STACKARR_H
#include <iostream>

class stackarr
{
public:
	stackarr();
	std::string* values;
	void peek();
	void push(std::string value);
	void pop();
	int length;
};

#endif // STACKARR_H
