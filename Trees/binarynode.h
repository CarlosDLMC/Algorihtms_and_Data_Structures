#ifndef BINARYNODE_H
#define BINARYNODE_H
#include<memory>
#include<iostream>

class binaryNode
{
public:
	int value;
	binaryNode(int value);
	binaryNode* right;
	binaryNode* left;
	void insert(int value);
	bool exists(int value);
	void remove(int value);
};

#endif // BINARYNODE_H
