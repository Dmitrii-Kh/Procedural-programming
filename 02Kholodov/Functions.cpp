#include <iostream>
using namespace std;

double power(double x, int n) {
	double res = 1.0;
	for (int i = 0; i < n; i++) {
		res *= x;
	}
	return res;
}


double powerRec(double x, int n) {
	if (n == 0) return 1;
	return x * powerRec(x, n - 1);
}


double quickPower(double x, int n) {
	double res = 1; 

	while (n > 0) {
		if (n & 1)	res *= x;
		n /= 2; 
		x *= x; 
	}
	return res;
}


double quickPowerRec(double x, int n) {
	if (n == 0) return 1;
	double temp = quickPowerRec(x, n / 2);

	if (n % 2 == 0)
		return temp * temp;
	else
		return x * temp * temp;
}


//
//Counters
//

int powerRecCounter(double x, int n, int counter) {
	double res = 1;
	if (n == 0) return counter;
	counter++;
	return res * powerRecCounter(x, n - 1, counter);
}


int quickPowerRecCounter(double x, int n, int counter) {

	counter++;
	if (n == 0) {
		return counter;
	}
	double temp = quickPowerRecCounter(x, n / 2, counter);
}


int powerCounter(double x, int n) {
	int counter = 0;
	for (int i = 0; i < n; i++) counter++;
	return counter;
}


int quickPowerCounter(double x, int n) {
	int res = 1;
	int counter = 0;
	while (n > 0) {
		counter++;
		if (n & 1)	res = res * x;

		n = n >> 1;
		x = x * x;
	}
	counter++;
	return counter;
}