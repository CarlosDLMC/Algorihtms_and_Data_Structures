#ifndef SMARTNODE_H
#define SMARTNODE_H
#include<iostream>
#include <memory>

class smartnode
{
public:
	smartnode(std::string value);
	std::string value;
	std::shared_ptr<smartnode> next;
};

#endif // SMARTNODE_H
