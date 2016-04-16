//============================================================================
// Name        : selection-sort.cpp
// Author      : 
// Date        :
// Copyright   :
// Description : Implementation of selection sort in C++
//============================================================================

 /* Complete this function with the implementation of selection sort algorithm
  Record number of comparisons in variable num_cmps of class Sort
  */

#include "sort.h"
#include <iostream>



void SelectionSort::sort(int A[], int size)				// main entry point
{
 resetNumCmps();
 int min;
 int temp;
	for(int i = 0; i < size-1; i++){
	min = i;
		for(int j = i+1 ; j < size ; j++){
			if(A[j] < A[min])
				min = j;
			num_cmps++;

		}
		if(min != i){
			temp = A[i];
			A[i]= A[min];
			A[min]= temp;

		}

	}
}
