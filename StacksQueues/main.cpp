#include <iostream>
#include "stacklist.h"
#include "stackarr.h"
#include "cola.h"

using namespace std;

void printcola(cola q){
	while(q.first != nullptr){
		cout << q.first->value << endl;
		q.dequeue ();
	}
}
void printsl(stacklist st){
	while(st.top != nullptr){
		cout << st.top->value << " ";
		st.pop ();
	}
	cout << endl;
}

void printsar(stackarr sr){
	for(int i = 0; i < sr.length; i++) cout << sr.values[i] << " ";
	cout << endl;
}
int main()
{
	stacklist sl;
	sl.push("hola");
	sl.push("marica");
	sl.push("tres");
	sl.push("cuatro");
	sl.push("cinco");
	sl.push("seis");
	stackarr sr;
	sr.push ("uno");
	sr.push("dos");
	sr.push("tres");
	printsar(sr);
	sr.pop ();
	sr.push("cuatro");
	sr.peek();
//	Ahora con las putas colas de los cojones
	cola c;
	c.enqueue ("Juan");
	c.enqueue ("Pedro");
	c.enqueue ("Alfonso");
	printcola(c);
	return 0;
}
