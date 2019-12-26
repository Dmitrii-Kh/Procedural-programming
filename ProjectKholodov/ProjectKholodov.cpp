#include <iostream>
#include "MatricesHeader.h"
using namespace std;

int main() {

	 WrappedMatrix mat;   
	 mat._size_m = 3;
	 initialize(mat);                //ініціалізуємо матрицю 
	 mat._pMatrix[1][0] = 1;
	 mat._pMatrix[0][1] = 2;
	 mat._pMatrix[2][1] = 3;

	 cout << "Initial matrix : \n" << mat << endl;

	 WrappedVector v;
	 v._n = 9;
	 linearization(v, mat);            //лінеаризація
	 cout << "Linearized matrix : "<< v;
	 cout << endl << endl;

	 WrappedMatrix mat2;
	 mat2._size_m = 3;
	 initialize(mat2);

	 toMatrix(v, mat2);                //зворотнє  перетворення вектора на матрицю

	 cout << "Vector to matrix transformation : \n"<< mat2 << endl;
	 ~v;		                	   //транспонували лінеаризовану матрицю
	 cout << "Transposed vector : " <<v <<endl;
	 cout << endl;

	 toMatrix(v, mat);				   //зворотнє  перетворення вже *транспонованого* вектора на матрицю
	 cout << "Transposed vector to matrix : \n" << mat << endl;

	 //+=
	 WrappedMatrix matToSum;
	 matToSum._size_m = 3;
	 initialize(matToSum);

	 matToSum._pMatrix[0][0] = 4;
	 matToSum._pMatrix[1][1] = 4;
	 matToSum._pMatrix[2][2] = 4;

	 cout << "Matrix to be added : \n"<< matToSum<< endl;
	 WrappedVector vToSum;
	 vToSum._n = 9;
	 linearization(vToSum, matToSum);
	 v += vToSum;
	 toMatrix(v, mat);
	 cout <<"Sum of two previous matrices : \n"<< mat << endl;

	 //*=
	 WrappedMatrix matToMult;
	 matToMult._size_m = 3;
	 initialize(matToMult);

	 matToMult._pMatrix[0][0] = 2;
	 matToMult._pMatrix[1][1] = 3;
	 matToMult._pMatrix[2][2] = 4;
	 matToMult._pMatrix[2][1] = -2;
	 matToMult._pMatrix[0][2] = -1;


	 cout << "Matrix multiplier : " <<endl << matToMult << endl;
	 WrappedVector vToMult;
	 vToMult._n = 9;
	 linearization(vToMult, matToMult);
	 v *= vToMult;
	 toMatrix(v, mat);
	 cout << "Result of multiplication : " << endl << mat << endl;

	 destroyVector(v);
	 destroyMatrix(mat);
	 destroyMatrix(mat2);
	 destroyMatrix(matToSum);
	 destroyMatrix(matToMult); 

	//Calc function
	cout << endl << "Calc function testing : " << endl;
	WrappedMatrix matToTest;
	matToTest._size_m = 3;
	initialize(matToTest);

	matToTest._pMatrix[0][0] = 2;
	matToTest._pMatrix[1][1] = -7;
	matToTest._pMatrix[2][2] = -4;
	matToTest._pMatrix[2][1] = -2;
	matToTest._pMatrix[0][2] = -1;
	matToTest._pMatrix[0][2] = 6;


	WrappedMatrix matToTest1;
	matToTest1._size_m = 3;
	initialize(matToTest1);

	matToTest1._pMatrix[0][2] = 8;
	matToTest1._pMatrix[2][1] = -6;
	matToTest1._pMatrix[2][0] = 4;
	matToTest1._pMatrix[2][2] = -6;
	matToTest1._pMatrix[1][1] = -2;


	cout << "Matrix 0 to test : " << endl << matToTest << endl;
	cout << "Matrix 1 to test : " << endl << matToTest1 << endl;

	cout << "Calc m0 * m1  : " << endl << Calc(matToTest, matToTest1, mult) << endl << endl;
	cout << "Calc m0 + m1  : " << endl << Calc(matToTest, matToTest1, sum) << endl << endl;


	WrappedVector vToTest;
	vToTest._n = 9;
	linearization(vToTest, matToTest);

	WrappedVector vToTest1;
	vToTest1._n = 9;
	linearization(vToTest1, matToTest1);

	cout << "Vector 0 to test : " << vToTest << endl;
	cout << "Vector 1 to test : " << vToTest1 << endl;

	cout << "Calc v0 * v1  : " << Calc(vToTest, vToTest1, mult) << endl;
	cout << "Calc v0 + v1  : " << Calc(vToTest, vToTest1, sum) << endl;

	destroyVector(vToTest);
	destroyVector(vToTest1);
	destroyMatrix(matToTest);
	destroyMatrix(matToTest1);
}


