#include <iostream>
#include <string>
using namespace std;

bool isPalindrom(string& name){
	int left = 0;
	int right = name.size() - 1;
	while(left <= right){
		if (name[left] == name[right]){
			left++;
			right--;
		}
		else {
			return false;
		}
	}
	return true;
}

int main() {
	string name = "";
	cout << isPalindrom(name);
	return 0;
}