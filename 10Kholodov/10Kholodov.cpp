#include <iostream>
#include "SimpsonHeader.h"
using namespace std;
const double eps = 1.0e-7;

int main() {

	EllipticVerifier(eps);
	PoissonVerifier(eps);
	DirichletVerifier(eps);
	EulersVerifier(eps);

	cout << "Regular functions to test : " << endl;
	cout << "func 0 : " << Simpson(-4, 6, eps, test0) << endl;
	cout << "func 1 : " << Simpson(-0.3, 6.4, eps, test1) << endl;
	cout << "func 2 : " << Simpson(-2, 4, eps, test2) << endl;
}

