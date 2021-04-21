#include <iostream>
#include <map>
#include <vector>
#include "dict.h"

using namespace std;

int firstOcc(vector<int>& v){
	map<int, int> m;
	for(int i : v){
		if(m[i]) return i;
		m[i] = true;
	}
	return 0;
}

bool hasCommon(vector<int>& v1, vector<int>& v2){
	map<int, bool> m;
	for(unsigned int i = 0; i < v1.size(); i++){
		m[v1[i]] = true;
	}
	for(unsigned int j = 0; j < v2.size(); j++){
		if(m[v2[j]]) return true;
	}
	return false;
}
int main(){
	dict d = dict(2);
	d.set("tetas", 4);
	d.set("dinero", 10000);
	vector<int> nums1 = {2, 5, 1, 2, 3, 5, 1, 2, 4};
	vector<int> nums2 = {2, 1, 1, 2, 3, 5, 1, 2, 4};
	cout << d.get("dinero") << endl;
	cout << d.get("tetas") << endl;
	cout << firstOcc (nums1) << endl;
	if (hasCommon (nums1, nums2)) cout << "urra\n";
	return 0;
}
