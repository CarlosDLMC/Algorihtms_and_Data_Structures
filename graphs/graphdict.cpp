#include "graphdict.h"

graphdict::graphdict()
{
	this->numberOfNodes = 0;
	this->adjacent_list = std::map<int, std::map<int, int>>();
}

void graphdict::addVertex(int node){
	this->adjacent_list[node] = std::map<int, int>();
	this->numberOfNodes++;
}

void graphdict::addEdge(int node1, int node2, int weight){
	if(this->adjacent_list.find(node1) == this->adjacent_list.end() || this->adjacent_list.find(node2) == this->adjacent_list.end()){
		std::cout << "one or both of those nodes do not exist\n";
		return;
	}
	this->adjacent_list[node1][node2] = weight;
	this->adjacent_list[node2][node1] = weight;
}

void graphdict::show(){
	for(auto it = adjacent_list.begin (); it != adjacent_list.end(); it++){
		std::cout << it->first << "--->";
		for(auto it2 = it->second.begin(); it2 != it->second.end(); it2++){
			std::cout << it2->first << "(" << it2->second << ") ";
		}
		std::cout << std::endl;
	}
}
