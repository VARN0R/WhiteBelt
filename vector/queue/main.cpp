#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	string temp;
	vector<bool> people;
	int amount;
	int value;
	cout << "Enter amount operations: " << endl;
	cin >> amount;
	while(amount--){
		cin >> temp;
		if (temp == "COME"){
			cin >> value;
			people.resize(people.size() + value, false);
		}
		else if(temp == "WORRY"){
			cin >> value;
			people[value] = true;
		}
		else if(temp == "QUIET"){
			cin >> value;
			people[value] = false;
		}
		else if(temp == "WORRY_COUNT"){
			cout << count(people.begin(), people.end(), true) << endl;
		}
	}
    return 0;
}