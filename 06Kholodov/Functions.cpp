using namespace std;
#include <iostream>
#include <cassert>
#include <algorithm>

void printArr(double arr[], int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << "; ";
	}
	cout << endl;
}

bool arraysEqual(double arr0[], double arr1[], int size) {
	for (int i = 0; i < size; i++) {
		if (arr0[i] != arr1[i]) return false;
	}
	return true;
}

bool arraySorted(double arr[], int size) {
	for (int i = 0; i < size; i++) {
		if (arr[i] < arr[i-1]) return false;
	}
	return true;
}


int partition(double arr[], int left, int right) {
	double pivot = arr[right];
	int i = (left - 1);

	for (int j = left; j < right; j++) {
		if (arr[j] <= pivot) {

			i++;

			double temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	double temp = arr[i + 1];
	arr[i + 1] = arr[right];
	arr[right] = temp;

	return i + 1;
}

void quicksort(double arr[], int left, int right, double arrCopy[]) {
	if (left < right) {
		int pi = partition(arr, left, right);
		quicksort(arr, left, pi - 1, arrCopy);
		quicksort(arr, pi + 1, right, arrCopy);
	}
	assert(arraysEqual(arr, arrCopy, right + 1) == true);
	assert(arraySorted(arr, right + 1) == true);
}

void testQuickSort(double arr[], double arrCopy[], int size) {

	cout << "Original array : ";
	printArr(arr, size);

	sort(arrCopy, arrCopy + size); // built-in function "sort()"
	quicksort(arr, 0, size - 1, arrCopy);

	cout << "Sorted array : ";
	printArr(arr, size);
	//cout << "Sorted copy : ";
	//printArr(arrCopy, size);
	cout << "\n";
}
