#include <iostream>
using namespace std;
const double aElliptic = 4;
const double bElliptic = 16;
const double aDirichlet = 1;
const double alpha = 0.5;
const double PI = 3.1415926535897932384626;


double Simpson(const double a, const double b, const double eps, double(*const f)(double)) {
	int n = 2;
	double h = (b - a) * 0.5;
	double ss = 0;
	double s1 = h * (f(a) + f(b));
	double s2 = 0;
	double s4 = 4 * h * f(a + h);
	double s = s1 + s2 + s4;
	do {
		ss = s;
		n *= 2;
		h /= 2;
		s1 *= 0.5;
		s2 = 0.5 * s2 + 0.25 * s4;
		s4 = 0;
		int i = 1;
		do {
			s4 = s4 + f(a + i * h);
			i += 2;
		} while (i <= n);
		s4 = 4 * h * s4;
		s = s1 + s2 + s4;
	} while (fabs(s - ss) > eps);
	return s / 3;
}

double AGM(const double a, const double b) {
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


double Elliptic(double x) {
	return 1.0 / sqrt(bElliptic * bElliptic * cos(x) * cos(x) + aElliptic * aElliptic * sin(x) * sin(x));
}

double Dirichlet(double x) {
	return sin(aDirichlet * x) / x;
}

double Poisson(double x) {
	return exp(-pow(x, 2));
}

double Eulers(double x) {
	return pow(x, alpha-1) / (1 + x);
}

double signum(double a) {
	if (a > 0)  a = 1;
	if (a < 0)  a = -1;
	if (a == 0) a = 0;
	return a;
}

void EllipticVerifier(double eps) {
	cout << "Elliptic integral : " << 2 / PI * Simpson(0, PI / 2, eps, Elliptic) << endl;
	cout << "AGM value : " << 1 / AGM(aElliptic, bElliptic) << endl;
	cout << "A koeff = " << aElliptic << " ; B koeff = " << bElliptic << endl;
	cout << "_________________________" << endl;
	cout << "\n";
}

void PoissonVerifier(double eps) {
	cout << "Poisson : " << Simpson(0, 1.0e+5, eps, Poisson) << endl;
	cout << "Poisson check value : " << 0.5 * sqrt(PI) << endl;
	cout << "_________________________" << endl;
	cout << "\n";
}

void DirichletVerifier(double eps) {
	cout << "Dirichlet : " << Simpson(1.0e-10, 1.0e+6, eps, Dirichlet) << endl;
	cout << "Dirichlet check value : " << 0.5 * PI * signum(aDirichlet) << endl;
	cout << "A koeff = " << aDirichlet << endl;
	cout << "_________________________" << endl;
	cout << "\n";
}

void EulersVerifier(double eps) {
	cout << "Euler`s : " << Simpson(1.0e-3, 1.0e+3, eps, Eulers) << endl;
	cout << "Euler`s check value : " <<  PI / sin(alpha*PI) << endl;
	cout << "alpha = " << alpha <<  endl;
	cout << "_________________________" << endl;
	cout << "\n";
}

//regular functions to test Simpson`s method
double test0(double x) {     
	return sqrt(x * x + 3);
}

double test1(double x) {
	return pow(x, 4);
}

double test2(double x) {
	return 8 + 2 * x - x * x;
}