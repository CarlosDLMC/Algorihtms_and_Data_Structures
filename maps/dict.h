#ifndef DICT_H
#define DICT_H
#include <iostream>

class dict
{
private:
	int* data;
	int size;
public:
	dict(int size);
	int hash(std::string key);
	void set(std::string key, int value);
	int get(std::string key);
};

#endif // DICT_H
