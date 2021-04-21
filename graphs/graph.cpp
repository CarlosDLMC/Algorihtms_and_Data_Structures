#include "graph.h"

graph::graph(){
	this->numberOfNodes = 0;
}

void graph::addVertex(int value){
	this->numberOfNodes++;
	this->adjacentList[value] = std::vector<std::array<int, 2>>();
}

void graph::addEdge(int node1, int node2, int weight){
	if(this->adjacentList.find(node1) == this->adjacentList.end() || this->adjacentList.find(node2) == this->adjacentList.end()){
		std::cout << "one or both of those nodes do not exist\n";
		return;
	}
	this->adjacentList[node1].push_back (std::array<int, 2>{{node2, weight}});
	this->adjacentList[node2].push_back (std::array<int, 2>{{node1, weight}});
}

void graph::show(){
//	std::cout << "We have " << this->numberOfNodes << " nodes" << std::endl;
	for(auto it = this->adjacentList.begin(); it != this->adjacentList.end(); it++){
		std::cout << it->first << "--->";
		for(std::array<int, 2> ar : this->adjacentList[it->first]) std::cout << ar[0] << "(" << ar[1] << ") ";
		std::cout << std::endl;
	}

}
