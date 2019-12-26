using namespace std;
#include <iostream>
#include "FuncHeader.h"

int main() {

	double arr0[] = { 10.3, 3.33, -15.3, 34.53, 87.3, -23.344, 80.001 };
	double arrCopy0[] = { 10.3, 3.33, -15.3, 34.53, 87.3, -23.344, 80.001 };
	int size = sizeof(arr0) / sizeof(double);
	testQuickSort(arr0, arrCopy0, size);

	double arr1[] = { 12.2, -23.33, 45.044, 19.33, 19.33, -2, 0, 100 };
	double arrCopy1[] = { 12.2, -23.33, 45.044, 19.33, 19.33, -2, 0, 100 };
	size = sizeof(arr1) / sizeof(double);
	testQuickSort(arr1, arrCopy1, size);

	double arr2[] = { -2.2, -21.6, 0.00234, -0.235, 0.001, 0.001, 12.224, 4 };
	double arrCopy2[] = { -2.2, -21.6, 0.00234, -0.235, 0.001, 0.001, 12.224, 4 };
	size = sizeof(arr2) / sizeof(double);
	testQuickSort(arr2, arrCopy2, size);

	double arr3[] = { -2.2, -21.6, 0.00234, -0.235, 0.001, 0.001, 12.224, 10.3, 3.33, -15.3, 34.53, 87.3, -23.344, 80.001 };
	double arrCopy3[] = { -2.2, -21.6, 0.00234, -0.235, 0.001, 0.001, 12.224, 10.3, 3.33, -15.3, 34.53, 87.3, -23.344, 80.001 };
	size = sizeof(arr3) / sizeof(double);
	testQuickSort(arr3, arrCopy3, size);

	double arr4[] = { -0.234, -0.435, 0.845, 0.993, 0.002, 0.002, -0.89, 0.00213 };
	double arrCopy4[] = { -0.234, -0.435, 0.845, 0.993, 0.002, 0.002, -0.89, 0.00213 };
	size = sizeof(arr4) / sizeof(double);
	testQuickSort(arr4, arrCopy4, size);

	double arr5[] = { 9,8,7,6,5,4,3,2,1,0 };
	double arrCopy5[] = { 9,8,7,6,5,4,3,2,1,0 };
	size = sizeof(arr5) / sizeof(double);
	testQuickSort(arr5, arrCopy5, size);

	return 0;
}


// Вибрав саме цей алгоритм, бо : 
//по-перше, його часова складність : O(nlogn) (середнє значення). Алгоритм швидко працює 
//з массивами великого розміру (Перевіряли за допомогою JUnit в минулому році).
//По-друге, не потребує додаткової пам'яті, як, наприклад, сортування злиттям. 