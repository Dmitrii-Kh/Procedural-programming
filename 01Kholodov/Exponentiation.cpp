using namespace std;
#include <iostream>

double xToPower(double x, int n) {
	double answer = 1.0;
	for (int i = 0; i < n; i++) {
		answer *= x;
	}
	return answer;
}

// Область визначення функції : D(f) = R 