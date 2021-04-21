#ifndef NODE_H
#define NODE_H
#include<memory>

class Node
{
public:
	Node(int value);
	std::unique_ptr<Node> node;
	int value;
	void append(int value);
	void prepend(int value);
	void insert(int index, int value);
	void pop();
	void print();
	std::unique_ptr<Node> reverse();
	std::unique_ptr<Node> rev2();
	void reverseArr();
	void remove(int index);
};

#endif // NODE_H
