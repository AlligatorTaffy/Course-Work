/**
AlligatorTaffy
Homework #1
January 30, 2019
**/
#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

void arraySort(int[], int);

int main() {
	// Variables
	srand(time(NULL));
	const int size = 50000;
	const int range = 50000000 - 1;
	int *array = new int[size];
	ofstream fout;

	// Initializing Array with random integers 1 - 50,000,000
	for(int i = 0; i < size; i++) {
		array[i] = ((static_cast<double>(rand())/RAND_MAX) * range) + 1;
	}

	// Sorting the Array from Least to Greatest
	arraySort(array, size);

	// Writing Sorted Array to output file "Sorted.txt"
	fout.open("sorted.txt");
	for(int i = 0; i < size; i++) {
		fout << array[i] << endl;
	}
	fout.close();

	delete[] array;
	return 0;
}

void arraySort(int a[], int size) {
	for(int i = 1; i < size; i++) {
		int key = a[i];
		int j = i - 1;
		for(; j >= 0 && a[j] > key; j--){
			a[j + 1] = a[j];
		}
		a[j + 1] = key;
	}

}