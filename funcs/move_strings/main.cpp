#include <iostream>
#include <vector>
#include <string>
using namespace std;

void moveStrings(vector<string>& first, vector<string>& second){
	for (auto x : first){
		second.push_back(x);
	}
	first.clear();
}

int main() {
	vector<string> source = {"a", "b" ,"c"};
	vector<string> destination = {"z"};
	moveStrings(source, destination);
	for (auto x : destination){
		cout << x << " ";
	}
	return 0;
}