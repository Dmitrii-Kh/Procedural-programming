#include <iostream>
#include "FuncHeader.h"
using namespace std;

int main() {
	cout.precision(10);

	cout << "Gaussian Integral : \n" << endl;
	for (int i = 1; i < 11; i++) {
		cout << "Power = " << i << " Result = " << calcGaussianIntegral(i, 1e-10) << endl;
	}
	cout << "\nAt X > 6, the result of the function is incorrect" << endl;

	cout << "\nComparing results of different exp() functions : " << endl;
	for (int i = -1; i > -41; i -= 5) {
		cout << "Power = " << i << endl;
		cout << "Taylor Series function            || Result : " << calcExp(i, 1e-6) << endl;
		cout << "Integer/fractional ratio function || Result : " << calcExp2(i) << endl;
		cout << "Built-in function                 || Result : " << exp(i) << endl;
		cout << "\n";
	}
	cout << "At X < 0, the result of the Taylor Series function is incorrect" << endl;

	cout << "\nComparing the number of iterations : " << endl;
	for (double power = 15; power < 20; power += 0.5) {
		cout << "Power = " << power << endl;
		cout << "Taylor Series function            || Num of iterations : " << calcExpCounter(power, 1e-6) << endl;
		cout << "Integer/fractional ratio function || Num of iterations : " << calcExp2Counter(power) << endl;
		cout << "\n";
	}

	return 0;
}

//Причина некоректних результатів функцій обчислення інтегралу Гауса та експоненти
//за розкладом в ряд : несумірність доданків. 