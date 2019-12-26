#include <iostream>
using namespace std;


double calcExp(double power, double accuracy) {
	int i = 1;
	double exp = 1, element = 1;
	while (fabs(element *= power / i) > accuracy) {
		exp += element;
		i++;
	}
	return exp;
}

double calcGaussianIntegral(double x, double accuracy) {
	int i = 1, n = 3;
	double res = x, element = x;
	while (fabs(element *= -x * x / i) > accuracy) {
		res += element / n;
		i++;
		n += 2;
	}
	return res;
}

double quickPower(double x, int n) {
	double res = 1;
	while (n > 0) {
		if (n & 1) res *= x;
		n /= 2;
		x *= x;
	}
	return res;
}


double calcExp2(double power) {
	double e = exp(1);
	int integer = floor(power);
	double fractional = power - integer;
	if (power < 0) return 1 / quickPower(e, abs(integer)) * calcExp(fractional, 1e-6);
	return quickPower(e, integer) * calcExp(fractional, 1e-6);
}


//Counters
int calcExpCounter(double power, double accuracy) {
	int i = 1;
	double element = 1;
	while (fabs(element *= power / i) > accuracy) {
		i++;
	}
	return i;
}

int quickPowerCounter(double x, int n) {
	double res = 1;
	int counter = 0;
	while (n > 0) {
		counter++;
		if (n & 1)	res = res * x;
		n /= 2;
		x = x * x;
	}
	counter++;
	return counter;
}

int calcExp2Counter(double power) {
	double e = exp(1);
	int integer = floor(power);
	double fractional = power - integer;
	return quickPowerCounter(e, abs(integer)) + calcExpCounter(fractional, 1e-6);
}
