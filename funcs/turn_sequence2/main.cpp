#include <iostream>
#include <vector>
using namespace std;

vector<int> isReversed(const vector<int>& nums){
	vector<int> res;
	int len = nums.size();
	for (int i = len - 1; i >= 0; i--){
		res.push_back(nums[i]);
	}
	return res;
}

int main() {
	vector<int> numbers = {1,5,3,4,2};
	numbers = isReversed(numbers);
	for (auto x : numbers){
		cout << x << " ";
	}
	return 0;
}
