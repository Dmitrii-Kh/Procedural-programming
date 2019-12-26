#include <cassert>
#include <cmath>
#include <iostream>
using namespace std;

struct Matrix2x2 {
	double _11, _12, _21, _22;
};

struct Vector2 {
	double _1, _2;
};

const Matrix2x2 operator* (const Matrix2x2& a, const Matrix2x2& b) {
	Matrix2x2 res = { a._11 * b._11 + a._12 * b._21,a._11 * b._21 + a._12 * b._22,
					a._21 * b._11 + a._22 * b._21,a._21 * b._21 + a._22 * b._22 };
	return res;
};

const Vector2 operator* (const Matrix2x2& a, const Vector2& v) {
	Vector2 res = { a._11 * v._1 + a._12 * v._2, a._21 * v._1 + a._22 * v._2 };
	return res;
};

const Matrix2x2 unitMatrix = { 1,0,0,1 };

// Швидке рекурсивне шаблонне піднесення до степеня
template <typename Type> const Type& quickPower(const Type& base, const int exponent, const Type& y = 1) {
	if (exponent == 0) return y;
	if (exponent % 2 == 0)
		return quickPower(base * base, exponent / 2, y);
	return quickPower(base, exponent - 1, y * base);
};

double slowFib(int n) {
	double f0 = 1, f1 = 1, f = 1;
	if (n == 0 || n == 1) return f0;
	for (int i = 2; i < n; i++) {
		f = f0 + f1;
		f0 = f1;
		f1 = f;
	}
	return f;
}

// Task 3

double quickFib(int n) {
	Matrix2x2 fibMatrix = { 1,1,1,0 };
	Vector2 fibVector = { 1, 0 };
	Vector2 fibRes = quickPower(fibMatrix, n - 1, unitMatrix) * fibVector;
	assert(fibRes._1 == slowFib(n));
	return fibRes._1;
};

// Task 1

void zet(double& y, double& x, unsigned int& k, int& counter){
	counter++;
	if (k > 0) {
		if (k % 2 == 1) {
			y *= x; k--;
		}else {
			x *= x; k /= 2;
		};
		zet(y, x, k, counter);
	}
}

double power(double x, unsigned int n, int& counter) {
	int n0 = n;
	double x0 = x;
	double y = 1;
	zet(y, x, n, counter);
	assert(y == pow(x0, n0));
	return y;
}

//Task 2

void fib(double& f1, double& f2, unsigned int n, int& counter) {
	counter++;
	if (n >= 2) {
		double f = f2; f2 += f1; f1 = f;
		fib(f1, f2, n - 1, counter);
	}
};

double Fibonaci(unsigned int n, int& counter) {
	double f0 = 0, f1 = 1;
	switch (n) {
	case 0:
		return f0; break;
	case 1:
		return f1; break;
	default:
		fib(f0, f1, n, counter);
		assert(f1 == slowFib(n));
		return f1;
	}
};

void testQuickPow(double x, unsigned int n, int& counter) {
	cout << "X = " << x << " ; N = " << n << endl;
	cout << "QUICK POWER result : " << power(x, n, counter) << endl;
	cout << "Num of recursive calls : " << counter << endl;
	cout << "BUILT-IN POWER result : " << pow(x, n) << endl;
	cout << endl;
	counter = 0;
}

void testFib(unsigned int n, int& counterFib) {
	cout << "N = " << n << endl;
	cout << "Fibonacci result : " << Fibonaci(n, counterFib) << endl;
	cout << "Num of recursive calls : " << counterFib << endl;
	cout << "SLOW Fibonacci result : " << slowFib(n) << endl;
	cout << endl;
	counterFib = 0;
}