#include <iostream>
#include "FuncHeader.h"
using namespace std;

int main() {
	
	int counter = 0;
	int counterFib = 0;

	cout << "QUICK POWER : " << endl;
	testQuickPow(2, 10, counter);
	testQuickPow(2, 11, counter);
	testQuickPow(3.5, 18, counter);
	testQuickPow(-5.4, 9, counter);
	testQuickPow(-18.5, 21, counter);
	testQuickPow(0.5, 20, counter);

	cout << "REGULAR FIBONACCI : " << endl;
	testFib(6, counterFib);
	testFib(7, counterFib);
	testFib(8, counterFib);
	testFib(9, counterFib);
	testFib(10, counterFib);
	testFib(50, counterFib);

	cout << "QUICK FIBONACCI : " << endl;
	for (int i = 1; i < 15; i++) {
		cout << "Member of sequence : " << i << "; Result : " << quickFib(i) << endl;
	}
}