#ifndef GRAPH_H
#define GRAPH_H
#include<map>
#include<vector>
#include<iostream>
#include<array>

class graph
{
public:
	graph();
	int numberOfNodes;
	std::map<int, std::vector<std::array<int, 2>>> adjacentList;
	void addVertex(int value);
	void addEdge(int node1, int node2, int weight);
	void show();
};

#endif // GRAPH_H
