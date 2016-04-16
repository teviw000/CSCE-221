// Kyle Loyka
// Programming Assigment 2
// radix-sort.cpp

#include <iostream>
#include <cmath>
#include "sort.h"
using namespace std;

const int base = 10;
int digit(int k, int num){
	int r;
	r = num/(int)pow(base, k);
	return r % base;
}

int find_d(int A[], int n){

	// find max value
	int max = 0;
	for (int i = 0; i < n; ++i){
		if (A[i] > max) max = A[i];
	}

	// log base 10 of max, will return a value
	// the ceiling of this number will be the number of digits in the number
	return ceil(log(max));
}

void RadixSort::sort(int A[], int size){

	// A is our given array of integers
	// n is the size of this array
	// d is the number of digits in the largest number

	int d = find_d(A,size);

	// special case for dealing with negative number
	int min = 0;
	bool neg = false;
	// finding lowest number
	for (int i = 0; i < size; ++i)
		if (A[i] < 0) min = A[i];
	if (min < 0){
		neg = true;
		// add the absolute value of the lowest (negative) number to each element
		// this will make the smallest value in the array == 0, and  counting sort will work
		for (int i = 0; i < size; ++i)
			A[i] +=abs(min);
	}

	int i, j, m;
	int *C = new int[base];
	int *B = new int[size];

	// counting sort
	for (m = 0; m < d; m++){

		// setting initial values
		for (i = 0; i < base; i++) C[i] = 0;

		// polulating array with the number of times that digit appears
		for (j = 0; j < size; j++) C[digit(m,A[j])]++;

		// adding previous element to current element
		for (i = 1; i < base; i++) C[i] += C[i-1];

		// decrimenting counter and producing sorted array
		for (j = size-1; j >= 0; j--){
			i = --C[digit(m,A[j])];
			B[i] = A[j];
		}

		// copying sorted array back to original array
		for (j = 0; j < size; j++) A[j] = B[j];
	}

	delete [] B;
	delete [] C;

	// final handling of special case
	if (neg){
		// subtract the absolute value of the lowest (negative number) from each element
		// this will revert each element back to its original value
		for (int i = 0; i < size; ++i)
			A[i] -= abs(min);
	}

}
