#include <iostream>
#include <string>

using namespace std;

int main() {
	string name1, name2, name3;
	cout << "Enter 3 string: " << endl;
	cin >> name1 >> name2 >> name3;
	if (name1 <= name2 &&  name1 <= name3){
		cout << name1;
	}
	else if (name2 <= name1 && name2 <= name3){
		cout << name2;
	}
	else {
		cout << name3;
	}


	return 0;
}