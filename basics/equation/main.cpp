#include <iostream>
#include <cmath>
using namespace std;

int main() {
	double A, B, C;
	cin >> A >> B >> C;
	double dis;
	double x1, x2;
	dis = pow(B,2.0) - 4 * A * C;
	if (dis == 0){
		x1 = (-B + sqrt(dis))/(2 * A);
		cout << x1;
	} else if (dis > 0){
		x1 = (-B + sqrt(dis))/(2 * A);
		x2 = (-B - sqrt(dis))/(2 * A);
		cout << x1 << " " << x2;
	}
	else {
		cout << "";
	}

	return 0;
}