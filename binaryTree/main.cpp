#include <iostream>

using namespace std;

int main(){
	int* i = new int;
	int* j = new int(*i);
	*i = 3;
	cout << *j << endl;
	return 0;
}
