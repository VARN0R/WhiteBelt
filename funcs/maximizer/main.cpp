#include <iostream>
using namespace std;

void UpdateIfGreater(int first, int& second){
	if (first > second){
		second = first;
	}
}

int main() {
	int x = 6;
	int y = 5;
	UpdateIfGreater(x, y);
	cout << y;
	return 0;
}
