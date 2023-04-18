#include <iostream>
#include <vector>
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

vector<string> isPalindromFilter(vector<string>& words, int minLength){
	vector<string> res;
	for (string x : words){
		if(isPalindrom(x) && x.size() >= minLength){
			res.push_back(x);
		}
	}
	return res;
}

int main() {
	int len;
	cout << "Enter len vector: " << endl;
	cin >> len;
	vector<string> words(len);
	vector<string> res;
	int minLength;
	cout << "Enter minLength: " << endl;
	cin >> minLength;
	cout << "Enter strings: " << endl;
	for (int i = 0; i < len; i++){
		cin >> words[i];
	}
	res = isPalindromFilter(words, minLength);
	for (string x : res){
		cout << x << " ";
	}
	return 0;
}
