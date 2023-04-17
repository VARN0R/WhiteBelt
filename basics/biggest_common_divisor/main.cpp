#include <iostream>
using namespace std;

int main() {
	int A, B;
	int big_value;
	int max = 0;
	cin >> A >> B;
	if (A > B){
		big_value = A;
	}
	else {
		big_value = B;
	}
	for (int i = 1; i <= big_value; i++){
		if (A % i == 0 && B % i == 0){
			if (i > max){
				max = i;
			}
		}
	}
	cout << max;
	return 0;
}