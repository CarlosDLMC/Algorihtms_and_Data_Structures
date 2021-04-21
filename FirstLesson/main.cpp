#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
using namespace std;

vector<int> mergeSorted(vector<int> v1, vector<int> v2){
	vector<int> result;
	int p1 {};
	int p2 {};
	int m1 = v1.size() - 1;
	int m2 = v2.size() - 1;
	for(unsigned int i {}; i < v1.size() + v2.size(); i++){
		if(p2 > m2 || (p1 <= m1 && v1.at(p1) < v2.at(p2))){
			result.push_back (v1.at(p1));
			p1++;
		}else{
			result.push_back(v2.at(p2));
			p2++;
		}
	}
	return result;
}

vector<int> mergeSortedIt(vector<int> v1, vector<int> v2){
	vector<int> result;
	auto it1 = v1.begin();
	auto it2 = v2.begin();
	while(it1 != v1.end() || it2 != v2.end()){
		if(it2 == v2.end() || (*it1 < *it2 && it1 != v1.end())){
			result.push_back (*it1);
			it1++;
		}
		else{
			result.push_back (*it2);
			it2++;
		}
	}
	return result;
}
int main(){
	vector<int> v1 = {0, 3, 4, 8, 10, 14, 21, 26, 31};
	vector<int> v2 = {4, 6, 13, 17, 20, 27, 30};
	auto t1 = chrono::high_resolution_clock::now ();
	vector<int> res1 = mergeSortedIt(v1, v2);
	auto t2 = chrono::high_resolution_clock::now ();
	vector<int> res2 = mergeSorted(v1, v2);
	auto t3 = chrono::high_resolution_clock::now ();
	auto withit = chrono::duration_cast<chrono::microseconds>(t2 - t1);
	auto noit = chrono::duration_cast<chrono::microseconds>(t3 - t2);
	cout << "Sin iteradores: " << noit.count () << " microsegundos" << endl;
	cout << "Con iteradores: " << withit.count () << " microsegundos" << endl;
	return 0;
}
