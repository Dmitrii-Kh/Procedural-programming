#include <iostream>
#include <cmath>
using namespace std;

double dichotomy(const double a, const double b, const double eps, double(*f)(double)) {
	if ((f(a) * f(b) > 1e-10)) {
		cout << "F(x) has same signs on both sides of the gap! ";
		return -1; 
	}
	double left = a, right = b, c = 0;    
	while (abs(right - left) > eps) {
		c = 0.5 * (left + right);
		if (f(c) == 0) {
			break;
		}
		if (f(left) * f(c) < 0) 
			right = c;      
		else         
			left = c;  	
	}   
	return 0.5*(left+right);
} 

double sinX(double x) {
	return sin(x) - x;
}

double logX(double x) {
	return log(x) - 1;
}

double expX(double x) {
	return exp(x) - 2 + x;
}
