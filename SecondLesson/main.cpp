#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;


pair<int, vector<int>> findEntryWithLargestValue(map<int, vector<int>> sampleMap){
	vector<int> v;
	pair<int, vector<int>> entryWithMaxValue = *sampleMap.begin();
	for (auto currentEntry = sampleMap.begin(); currentEntry != sampleMap.end(); currentEntry++) {
		if (currentEntry->first > entryWithMaxValue.first) {
			entryWithMaxValue = make_pair(currentEntry->first, currentEntry->second);
		}
	}
	return entryWithMaxValue;
}
int vectorSum(vector<int> v){
	int res = 0;
	for(int i : v){
		res += i;
	}
	return res;
}

void printVector(vector<int> v){
	cout << "[";
	for(unsigned int i = 0; i < v.size(); i++){
		cout << v.at(i);
		if(i < v.size() - 1){
			cout << ", ";
		}
	}
	cout << "]";
}

pair<int, vector<int>> maxSubArray(vector<int>& nums) {
	vector<int> currVector;
	int suma;
	map<int, vector<int>> results;
	unsigned int size = nums.size();
	for(unsigned int i = 0; i < size; i++){
		suma = nums.at(i);
		currVector = {suma};
		results[suma] = currVector;
		for(unsigned int j = i + 1; j < size; j++){
			suma += nums.at(j);
			currVector.push_back(nums.at(j));
			results[suma] = currVector;
		}
	}
	pair<int, vector<int>> largest = findEntryWithLargestValue(results);
	return largest;
}


int main(){
	vector<int> input = {-1};
	pair<int, vector<int>> resultado = maxSubArray (input);
	cout << resultado.first << endl;
	printVector(resultado.second);
	cout << endl;
	return 0;
}
