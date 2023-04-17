#include <iostream>
using namespace std;

int main() {
	double N, A, B, X, Y;
	double discount = 0;
	double res;
	cin >> N >> A >> B >> X >> Y;
	if (A > B){
		cout << "Error input data!" << endl;
	}
	else {
		if (N > A && N < B){
			discount = N * (X/100);
			res = N - discount;
			cout << res;
		}
		else if (N > B){
			discount = N * (Y/100);
			res = N - discount;
			cout << res;
		}
		else {
			cout << N;
		}
	}
	return 0;
}