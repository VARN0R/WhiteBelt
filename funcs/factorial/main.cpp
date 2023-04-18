#include <iostream>
using namespace std;

int calculateFactorial(int x){
	int res = 1;
	while (x > 0){
		res*=x;
		x--;
	}
	return res;
}

int calculateFactorialRecursion(int x){//
	if (x <= 1){
		return 1;
	}
	return x * calculateFactorialRecursion(x - 1);
}

int main() {
	int x = 0;
	cin >> x;
	cout << calculateFactorial(x) << endl;
	cout << calculateFactorialRecursion(x);
	return 0;
}