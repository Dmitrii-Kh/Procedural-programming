#include <iostream>
#include "FuncHeader.h"
using namespace std;

void test(double x, int toPower) {
	cout << "X = " << x << " to the power of " << toPower << " : " << endl;
	cout << "POWER result : " << power(x, toPower) << " ; Num of iterations : " << powerCounter(x, toPower) << endl;
	cout << "POWER RECURSIVE result : " << powerRec(x, toPower) << " ; Num of iterations : " << powerRecCounter(x, toPower, 0) << endl;
	cout << "QUICK POWER result : " << quickPower(x, toPower) << " ; Num of iterations : " << quickPowerCounter(x, toPower) << endl;
	cout << "QUICK POWER RECURSIVE result : " << quickPowerRec(x, toPower) << " ; Num of iterations : " << quickPowerRecCounter(x, toPower,0) << endl;
	cout << "Built-in pow function`s result : " << pow(x, toPower) << endl;
	cout << "\n";
}


int main()
{
	test(2, 10);
	test(-3, 18);
	test(-4.5, 9);
	test(15, 15);
	test(23, 8);
	test(-90.15, 18);

	cout << "Time complexity of basic solution : O(n) \nTime complexity of optimized solution : O(logn)" << endl;
	return 0;
}

