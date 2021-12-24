#include <iostream>
#include <map>
#include <string>
#include <array>
#include <functional>
#include <vector>
#define MAX(a, b) ((a > b) ? a : b)

using namespace std;

int add90(map<int, int> &cache, int n){
	if(!cache[n]){
		cout << "This takes a long time" << endl;
		cache[n] = 90 + n;
	}
	return cache[n];
}

void fibonacci(map<int, int>& f, int n){
	for(int i = f.rbegin ()->first + 1; i <= n; i++){
		f[i] = f[i - 1] + f[i - 2];
		cout << "in cicle" << endl;
	}
	cout << f[n] << endl;
}


int max(int a, int b){
	return (a > b) ? a: b;
}
int rob(vector<int>& nums) {
	if(nums.size() == 0) return 0;
	if(nums.size() == 1) return nums[0];
	if(nums.size() == 2) return max(nums[0], nums[1]);
	int* sol = new int[nums.size()];
	sol[0] = nums[0];
	sol[1] = max(nums[0], nums[1]);
	for(unsigned int i = 2; i < nums.size(); i++){
		sol[i] = max(nums[i] + sol[i - 2], sol[i - 1]);
	}
	return sol[nums.size() - 1];
}

int main(){	
	map<int, int> cache;
	cout << add90 (cache, 5) << endl;
	cout << add90 (cache, 5) << endl;
	cout << "dynamic fibbonacci" << endl;
	map<int, int> fib;
	fib[0] = 0;
	fib[1] = 1;
	fibonacci (fib, 10);
	fibonacci (fib, 8);
	cout << "Ejercicios dinamicos:" << endl;
	vector<int> houses = {1,2,3,1};
	cout << rob(houses) << endl;
	return 0;
}
