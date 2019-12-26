using namespace std;
#include <iostream>

double calcCos(double x, double accuracy) {
	int i = 1;
	double cos = 1, element = 1;
	while (fabs(element *= -x * x / (2 * i * (2 * i - 1))) > accuracy) {
		cos += element;
		i++;
	}
	return cos;
}

// Область визначення функції : D(f) = [-35; 35]