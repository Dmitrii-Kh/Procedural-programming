#pragma once
#include <iostream>
using namespace std;
struct WrappedVector {
	size_t _n;
	double* _x;
};
struct WrappedMatrix {
	size_t _size_m;
	double** _pMatrix;
};  //загорнуті *квадратні* матриці
void initialize(WrappedMatrix &m);
void vectorInit(WrappedVector& v);
void destroyMatrix(WrappedMatrix& m);
ostream& operator<<(ostream& os, const WrappedMatrix& M);
void destroyVector(WrappedVector& u);
bool verification(const WrappedVector& u, const WrappedMatrix& mat);
void linearization(WrappedVector& u, const WrappedMatrix& mat);
ostream& operator<<(ostream& os, const WrappedVector& V);
void toMatrix(const WrappedVector& u, WrappedMatrix& mat);
WrappedVector operator~(WrappedVector& u);
WrappedVector operator+=(WrappedVector& firstV, const WrappedVector& secondV);
WrappedVector operator*=(WrappedVector& firstV, const WrappedVector& secondV);
WrappedVector multAssign(WrappedVector& a, const WrappedVector& b);
WrappedVector sumAssign(WrappedVector& a, const WrappedVector& b);
WrappedVector mult(const WrappedVector& a, const WrappedVector& b);
WrappedVector sum(const WrappedVector& a, const WrappedVector& b);
WrappedMatrix sum(const WrappedMatrix& a, const WrappedMatrix& b);
WrappedMatrix mult(const WrappedMatrix& a, const WrappedMatrix& b);
template <typename T> T Calc(const T& a, const T& b, T(*const f)(const T&, const T&)) { return f(a, b); }