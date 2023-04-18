#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int amount;
	vector<vector<string>> deals(31);
	string temp;
	int value;
	vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int pointer = 0;
	cout << "Enter amount operations: " << endl;
	cin >> amount;
	while(amount--){
		cin >> temp;
		if (temp == "ADD"){
			cin >> value;
			cin >> temp;
			deals[value-1].push_back(temp);
		}
		else if(temp == "DUMP"){
			cin >> value;
			cout << deals[value-1].size() << " ";
			for (int i = 0; i < deals[value-1].size(); i++){
				cout << deals[value-1][i] << " ";
			}
			cout << endl;
		}
		else if(temp == "NEXT"){
			if (pointer == 11){
				pointer = 0;
			}
			else {
				pointer++;
			}
			if (days[pointer] < deals.size()){
				for (int i = days[pointer] - 1; i < deals.size(); i++){
					for (int j = 0; j < deals[i].size(); j++){
						deals[days[pointer] - 1].push_back(deals[i][j]);
					}
				}

			}
			deals.resize(days[pointer]);
        }
	}
	return 0;
}