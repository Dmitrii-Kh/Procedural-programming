#include <iostream>
using namespace std;

double AGM(double a, double b) {
	double aprev = a, bprev = b;
	double an = sqrt(aprev * bprev);
	double bn = (aprev + bprev) * 0.5;

	while (an > aprev && bn < bprev) {
		aprev = an;
		bprev = bn;
		an = sqrt(aprev * bprev);
		bn = (aprev + bprev) * 0.5;
	}
	return an;
}


void test(double a, double b) {
	cout << "A = " << a << "; B = " << b << ";" << endl;
	cout << "AGM : " << AGM(a, b) << "\n" << endl;
}