#include <iostream>
#include <string>
using namespace std;

int main() {
	string temp = "comfort";
	int len = temp.size();
	cout << len << endl;
	int counter = 0;
	for (int i = 0; i < len; i++){
		if (temp[i] == 'f'){
			counter++;
			if (counter == 2){
				cout << i;
				break;
			}
		}
	}
	if (counter == 0){
		cout << -2;
	}
	if (counter == 1){
		cout << -1;
	}
	return 0;
}