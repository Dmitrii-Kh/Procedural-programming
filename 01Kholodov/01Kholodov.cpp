#include <iostream>
#include <cmath>
#include "Functions.h"
using namespace std;


int main() {
	cout.precision(5);

	cout << "\nCosine calculation : \n" << endl;
	for (double i = 0; i < 6; i += 0.5) { 
		cout << "X = " << i <<"; " << "My result: " << calcCos(i, 1e-6) << "; <cmath> result : ";
		cout << cos(i) << endl;
	}


	cout << "\nNatural logarithm calculation : \n" << endl;
	for (double i = 0.5; i < 6; i += 0.5) {
		cout << "X = " << i <<"; " << "My result: " << calcLog(i, 1e-6) << "; <cmath> result : ";
		cout << log(i) << endl;
	}

	cout << "\nX to the power of N : \n" << endl;
	cout << "X = -2.0" << endl;
	for (int i = 0; i < 11; i++) {
		cout << "N = " << i << "; " << "My result: " << xToPower(-2.0, i) << "; <cmath> result : ";
		cout << pow(-2.0, i) << endl;
	}
	
	return 0;
}
