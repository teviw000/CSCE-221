//============================================================================
// Name        : bubble-sort.cpp
// Author      :
// Date        : 09/16/2015
// Copyright   :
// Description : Implementation of bubble sort in C++
//============================================================================

#include "sort.h"

void BubbleSort::sort(int A[], int size){ //main entry point
  /* Complete this function with the implementation of bubble sort algorithm
     Record number of comparisons in variable num_cmps of class Sort
  */
  resetNumCmps();
  for (int k = 1; k < size; k++) {
	bool cont = false;
	for (int j = 0; j < size - k; j++)
		if (A[j+1] < A[j]) {
    num_cmps++;     
		int tmp = A[j]; // swap A[j] and A[j+1]
		A[j] = A[j+1];
		A[j+1] = tmp;
		cont = true;
	}
	if (!cont) break; // stop sorting
}

}
