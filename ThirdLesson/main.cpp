#include <iostream>
#include <vector>

using namespace std;



void rotate(vector<int>& nums, int k) {
		int s = nums.size();
		vector<int> res;
		k %= s;
		if(s > 1){
			for(int i = s - k; i < s; i++){
				res.push_back(nums.at(i));
			}
			for(int j = 0; j < s - k; j++){
				res.push_back(nums.at(j));
			}
			nums = res;
		}
	}

int main(){
	vector<int> v = {1, 2, 3, 4, 5 ,6 ,7, 8};
	rotate(v, 2);
	for(int i : v) cout << i << ", ";
	cout << endl;
	return 0;
}
