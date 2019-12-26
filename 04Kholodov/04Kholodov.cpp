#include <iostream>
#include "FuncHeader.h"
using namespace std;

int main() {
	cout.precision(16);

	test(0.5365910035746823, 1.6097730107240469);
	test(1, 3.352789134742513);
	test(1.2, 2.33);
	test(6, 28);
	test(32.332, 99.333);
	test(0.879, 10.0);
	test(12.321, 67.890);

	return 0;
}








