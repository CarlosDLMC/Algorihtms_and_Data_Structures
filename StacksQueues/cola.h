#ifndef COLA_H
#define COLA_H
#include "smartnode.h"
#include <iostream>
#include <memory>

class cola
{
public:
	cola();
	void enqueue(std::string value);
	void dequeue();
	void peek();
	std::shared_ptr<smartnode> first;
	std::shared_ptr<smartnode> last;
};

#endif // COLA_H
