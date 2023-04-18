#include <iostream>
#include <vector>
using namespace std;

void PrintVector(vector<int>& nums, int amount_days){
	for (int i = amount_days; i < nums.size(); i++){
		cout << nums[i] << " ";
	}
}

int main() {
    int amount_days;
	int sum = 0;
	int average = 0;
	int count = 0;
	
    cin >> amount_days;
	vector<int> nums(amount_days);
	
    for (int i = 0; i < nums.size(); i++){
		cin >> nums[i];
		sum+=nums[i];
	}
	
    average = sum / amount_days;

	for (int i = 0; i < nums.size(); i++){
		if (nums[i] > average){
			count++;
			nums.push_back(i);
		}
	}
	cout << count << endl;
	PrintVector(nums, amount_days);
    
    return 0;
}