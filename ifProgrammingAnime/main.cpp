#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findDuplicate(vector<int> v){
	int s = v.size();
	int p1 = 0;
	int p2;
	while(true){
		p1 = ++p1 % s;
		p2 = v[v[p1]];
		if(p1 != p2 && v[p1] == v[p2]){
			return v[p1];
		}
	}
}

int main(){
	vector<int> numeros = {1, 2, 3, 4, 5, 5, 6};
	cout << findDuplicate(numeros) << endl;
	return 0;
}
