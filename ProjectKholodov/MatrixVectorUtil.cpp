#include <cassert>
#include <iostream>
#include "MatricesHeader.h"
using namespace std;

void initialize(WrappedMatrix& m) {
	m._pMatrix = new double* [m._size_m];

	for (unsigned int i = 0; i < m._size_m; i++)
		m._pMatrix[i] = new double[m._size_m];

	for (unsigned int k = 0; k < m._size_m; k++) {
		for (unsigned int j = 0; j < m._size_m; j++) {
			m._pMatrix[k][j] = 0;
		}
	}
}

void vectorInit(WrappedVector& v) {
	v._x = new double[v._n];
	for (unsigned int i = 0; i < v._n; i++)
		v._x[i] = 0;
}

void destroyMatrix(WrappedMatrix& m) {
	for (unsigned int i = 0; i < m._size_m; i++) {
		delete[] m._pMatrix[i];
		m._pMatrix[i] = 0;
	}
	delete[] m._pMatrix;
	m._pMatrix = 0;
	return;
}


ostream& operator<<(ostream& os, const WrappedMatrix& M) {
	for (unsigned int i = 0; i < M._size_m; i++) {
		for (unsigned int j = 0; j < M._size_m; j++)
			cout << M._pMatrix[i][j] << ' ';
		cout << endl;
	}
	return os;
}



void destroyVector(WrappedVector& u) { delete[] u._x; u._x = 0;    return; }

bool verification(const WrappedVector& u, const WrappedMatrix& mat) {
	for (unsigned int i = 0; i < mat._size_m; i++) {
		for (unsigned int j = 0; j < mat._size_m; j++) {
			if (u._x[i * mat._size_m + j] != mat._pMatrix[i][j]) return false;
		}
	}
	return true;
}

void linearization(WrappedVector& u, const WrappedMatrix& mat) {
	u._x = new double[u._n];
	for (unsigned int i = 0; i < mat._size_m; i++) {
		for (unsigned int j = 0; j < mat._size_m; j++) {
			u._x[i * mat._size_m + j] = mat._pMatrix[i][j];
		}
	}
	assert(verification(u, mat) == true);
};


ostream& operator<<(ostream& os, const WrappedVector& V) {
	for (unsigned int i = 0; i < V._n; i++) {
		cout << V._x[i] << " ";
	}
	return os;
}

void toMatrix(const WrappedVector& u, WrappedMatrix& mat) {
	for (unsigned int i = 0; i < mat._size_m; i++) {
		for (unsigned int j = 0; j < mat._size_m; j++) {
			mat._pMatrix[i][j] = u._x[i * mat._size_m + j];
		}
	}
};

WrappedVector operator~(WrappedVector& u) {		//транспонування
	double t = 0;
	unsigned int vecSize = (unsigned int)sqrt(u._n); //double -> size_t, але відповідно до завдання, матриці - квадратні, тому результат sqrt буде натуральне число
	for (unsigned int i = 0; i < vecSize; i++) {
		for (unsigned int j = i; j < vecSize; j++) {
			t = u._x[i * vecSize + j];
			u._x[i * vecSize + j] = u._x[j * vecSize + i];
			u._x[j * vecSize + i] = t;
		}
	}
	return u;
};

WrappedVector operator+=(WrappedVector& firstV, const WrappedVector& secondV) {
	unsigned int size = (unsigned int)sqrt(firstV._n);
	for (unsigned int i = 0; i < size; i++) {
		for (unsigned int j = 0; j < size; j++) {
			firstV._x[i * size + j] += secondV._x[i * size + j];
		}
	}
	return firstV;
}

WrappedVector operator*=(WrappedVector& firstV, const WrappedVector& secondV) {
	WrappedVector copyV;
	copyV._n = firstV._n;
	vectorInit(copyV);
	unsigned int size = (unsigned int)sqrt(firstV._n);

	for (unsigned int l = 0; l < copyV._n; l++) {
		copyV._x[l] = firstV._x[l];
	}
	for (unsigned int l = 0; l < copyV._n; l++) {
		firstV._x[l] = 0;
	}

	for (unsigned int i = 0; i < size; i++) {
		for (unsigned int j = 0; j < size; j++) {
			for (unsigned int k = 0; k < size; k++) {
				firstV._x[i * size + j] += copyV._x[i * size + k] * secondV._x[k * size + j];
			}
		}
	}
	destroyVector(copyV);
	return firstV;
}

//Через сигнатуру функції Calc, функції multAssign та sumAssign не можуть бути використані в Calc
WrappedVector multAssign(WrappedVector& a, const WrappedVector& b) {
	return a *= b;
}

WrappedVector sumAssign(WrappedVector& a, const WrappedVector& b) {
	return a += b;
}

WrappedVector mult(const WrappedVector& a, const WrappedVector& b) {
	WrappedVector resV;
	resV._n = a._n;
	vectorInit(resV);
	size_t size = (unsigned int)sqrt(a._n);

	for (unsigned int i = 0; i < size; i++) {
		for (unsigned int j = 0; j < size; j++) {
			for (unsigned int k = 0; k < size; k++) {
				resV._x[i * size + j] += a._x[i * size + k] * b._x[k * size + j];
			}
		}
	}
	return resV;
}

WrappedVector sum(const WrappedVector& a, const WrappedVector& b) {
	WrappedVector resV;
	resV._n = a._n;
	vectorInit(resV);
	size_t size = (unsigned int)sqrt(a._n);

	for (unsigned int i = 0; i < size; i++) {
		for (unsigned int j = 0; j < size; j++) {
			resV._x[i * size + j] = a._x[i * size + j] + b._x[i * size + j];
		}
	}
	return resV;
}

WrappedMatrix sum(const WrappedMatrix& a, const WrappedMatrix& b) {
	size_t size = a._size_m;
	WrappedMatrix resM;
	resM._size_m = size;
	initialize(resM);

	for (unsigned int i = 0; i < size; i++) {
		for (unsigned int j = 0; j < size; j++) {
			resM._pMatrix[i][j] = a._pMatrix[i][j] + b._pMatrix[i][j];
		}
	}
	return resM;
}

WrappedMatrix mult(const WrappedMatrix& a, const WrappedMatrix& b) {
	size_t size = a._size_m;
	WrappedMatrix resM;
	resM._size_m = size;
	initialize(resM);

	for (unsigned int i = 0; i < size; i++) {
		for (unsigned int j = 0; j < size; j++) {
			for (unsigned int k = 0; k < size; k++) {
				resM._pMatrix[i][j] += a._pMatrix[i][k] * b._pMatrix[k][j];
			}
		}
	}
	return resM;
}

