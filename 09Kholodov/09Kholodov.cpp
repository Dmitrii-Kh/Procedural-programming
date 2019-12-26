#include <iostream>
#include "Dichotomy.h"
using namespace std;
const double PI = 3.14159265358979323846;

int main() {
	cout.precision(10);
	cout << "sin(x) = x, [-1,1] ; X = " << dichotomy(-1, 1, 1.0e-15, sinX) << endl;
	cout << "sin(x) = 0, [PI-1, PI] ; X = " << dichotomy(PI - 1, PI, 1.0e-15, sin) << endl;
	cout << "ln(x) = 1, [2, 3] ; X = " << dichotomy(2, 3, 1.0e-15, logX) <<endl;
	cout << "exp(x) = 2 - x, [0,2] ; X = " << dichotomy(0, 2, 1.0e-15, expX) << endl;
	return 0;
}
