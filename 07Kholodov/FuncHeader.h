#pragma once
struct Matrix2x2;
struct Vector2;
const Matrix2x2 operator* (const Matrix2x2& a, const Matrix2x2& b);
const Vector2 operator* (const Matrix2x2& a, const Vector2& v);
template <typename Type> const Type& quickPower(const Type& base, const int exponent, const Type& y = 1);
double quickFib(int n);
double slowFib(int n);
void zet(double& y, double& x, unsigned int& k, int& counter);
double power(double x, unsigned int n, int& counter);
double Fibonaci(unsigned int n, int& counter);
void fib(double& f1, double& f2, unsigned int n, int& counter);
void testQuickPow(double x, unsigned int n, int& counter);
void testFib(unsigned int n, int& counterFib);


