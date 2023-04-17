#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> nums;
	int N;
	int inVector;
	cin >> N;
	while (N >= 1){
		inVector = N % 2;
		N /= 2;
		nums.push_back(inVector);
	}
	for (int i = nums.size() - 1; i >= 0; i--){
		cout << nums[i];
	}
	return 0;
}