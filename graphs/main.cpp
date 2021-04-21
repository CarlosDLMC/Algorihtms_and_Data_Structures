#include <iostream>
#include "graph.h"
#include "graphdict.h"

using namespace std;

int main()
{
	graph g;
	for(int i = 0; i < 7; i++) g.addVertex (i);
	cout << "Metodo con arrays" << endl;
	g.addEdge (0, 2, 4);
	g.addEdge (0, 1, 5);
	g.addEdge (1, 2, 2);
	g.addEdge (1, 3, 5);
	g.addEdge (2, 4, 9);
	g.addEdge (3, 4, 2);
	g.addEdge (4, 5, 1);
	g.addEdge (5, 6, 0);
	g.show();
	cout << "Ahora con diccionarios" << endl;
	graphdict gd;
	for(int i = 0; i < 7; i++) gd.addVertex (i);
	gd.addEdge (0, 2, 4);
	gd.addEdge (0, 1, 5);
	gd.addEdge (1, 2, 2);
	gd.addEdge (1, 3, 5);
	gd.addEdge (2, 4, 9);
	gd.addEdge (3, 4, 2);
	gd.addEdge (4, 5, 1);
	gd.addEdge (5, 6, 0);
	gd.show ();
	return 0;
}
