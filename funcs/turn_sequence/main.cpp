#include <iostream>
#include <vector>
using namespace std;

void isReverse(vector<int>& nums){
	int len = nums.size();
	for (int i = len - 1; i >= 0; i--){
		nums.push_back(nums[i]);
		nums.erase(nums.begin() + i);
	}
}

void isReverse2(vector<int>& nums){
	int len = nums.size();
	int tmp;
	for (int i = 0; i < len/2; i++){
		tmp = nums[i];
		nums[i] = nums[len - 1 - i];
		nums[len - 1 - i] = tmp;
	}
}

int main() {
	vector<int> numbers = {1,5,3,4,2};
	isReverse(numbers);
	for (auto x : numbers){
		cout << x << " ";
	}
	cout << "Reverse 2" <<  endl;
	isReverse2(numbers);
	for (auto x : numbers){
		cout << x << " ";

	}
	return 0;
}