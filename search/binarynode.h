#ifndef BINARYNODE_H
#define BINARYNODE_H


class binaryNode
{
public:
	int value;
	binaryNode(int value);
	void insert(int value);
	binaryNode* right;
	binaryNode* left;
};

#endif // BINARYNODE_H
