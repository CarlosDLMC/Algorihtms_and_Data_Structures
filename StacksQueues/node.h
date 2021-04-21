#ifndef NODE_H
#define NODE_H
#include <iostream>

class Node
{
public:
	Node(std::string value);
	std::string value;
	Node* next;
};

#endif // NODE_H
