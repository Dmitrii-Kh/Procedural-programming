using namespace std;
#include <iostream>
#include <cassert>

void fillArray(double* coeff, int size) {
	double max = 100, min = -100; // визначив такі межі для спрощення перевірки обчислень 
	cout << "Coefficients : ";
	for (int i = 0; i < size; i++) {
		coeff[i] = (double)(rand()) / RAND_MAX * (max - min) + min;;
		cout << coeff[i] << " ";
	}
	return;
}

double sum(double* coeff, int size, double sign) {
	double sum = 0;
	for (int i = 1; i <= size; ++i) {
		sum *= sign;
		sum += coeff[size - i];
	}
	return sum;
}


double Horner(double x, int n) {
	double* coeff = new double[n + 1];
	fillArray(coeff, n + 1);

	double result = coeff[n];
	for (int i = 1; i <= n; ++i) {
		result *= x;
		result += coeff[n - i];
	}
	if (x == 1 || x == -1) {
		assert(result == sum(coeff, n + 1, x));
		cout << "\nResult : " << result << "; Sum of coefficients: " << sum(coeff, n + 1, x) << "\nResult == Sum : True";
	}
	delete[] coeff; 
	return result;
}

void test(double x, int power) {
	cout << "X = " << x << "; Power = " << power << endl;
	if ((x != 1) & (x != -1)) { cout << "\nResult : " << Horner(x, power) << endl; }
	else { Horner(x, power); cout << endl; };
	cout << "\n";
}
