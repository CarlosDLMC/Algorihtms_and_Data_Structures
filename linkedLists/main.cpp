#include <iostream>
#include "node.h"

using namespace std;

int main(){
	cout << "creamos la lista" << endl;
	unique_ptr<Node> lista = make_unique<Node>(6);
	lista->append(7);
	lista->append(18);
	lista->append(5);
	lista->append(35);
	lista->append(23);
	lista->append(67);
	lista->append(2);
	lista->print();
	cout << "Ahora quitamos el ultimo numero" << endl;
	lista->pop();
	lista->print();
	cout << "Metemos un 10 al principio" << endl;
	lista->prepend (10);
	lista->print();
	cout << "metemos 22 al index 2" << endl;
	lista->insert(2, 22);
	lista->print();
	cout << "Ahora quito el 18 al index 4" << endl;
	lista->remove(4);
	lista->print();
	cout << "Pruebo a quitar el 1" << endl;
	lista->remove(0);
	lista->print();
	cout << "Y ahora del reves" << endl;
	lista->reverseArr();
	lista->print();
	cout << "Y otra vez derecha" << endl;
//	reverse(&lista);
	lista = lista->reverse();
	lista->print();
	return 0;
}
