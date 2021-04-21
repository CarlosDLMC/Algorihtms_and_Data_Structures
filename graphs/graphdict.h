#ifndef GRAPHDICT_H
#define GRAPHDICT_H
#include<map>
#include<vector>
#include<iostream>

class graphdict
{
public:
	graphdict();
	int numberOfNodes;
	std::map<int, std::map<int, int>> adjacent_list;
	void addVertex(int node);
	void addEdge(int node1, int node2, int weight);
	void show();

};

#endif // GRAPHDICT_H
