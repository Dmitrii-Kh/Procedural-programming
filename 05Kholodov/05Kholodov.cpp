using namespace std;
#include <iostream>
#include <cassert>
#include "FuncHeader.h"
#include <time.h>


int main() {
	//cout.precision(7);
	//srand((unsigned int)time(0)); 

	test(2, 2);
	test(1, 2);
	test(-1, 2);
	test(-1, 6);
	test(2.22, 3);
	test(-4.12, 4);
	test(5.76, 3);
	test(12.002, 4);
	test(-11.36, 2);

	return 0;
}
