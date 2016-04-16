//============================================================================
// Name        : insertion-sort.cpp
// Author      :
// Date        :09/24/2015
// Copyright   :
// Description : Implementation of insertion sort in C++
//============================================================================


/* Complete this function with the implementation of insertion sort algorithm
  Record number of comparisons in variable num_cmps of class Sort
  */



#include "sort.h"
#include <iostream>

//using namespace std;



void
InsertionSort::sort(int A[], int size)				// main entry point
{

 int i;
 int temp;
 resetNumCmps();
 //resetNumCmps();// This is setting the variable num_cmps to 0 before starts counting the number of comparissons
 for(int i = 1 ; i < size; i ++){
	 int k = i;

	while(k > 0 && (num_cmps++, A[k] < A[k-1])){
		temp = A[k];
		A[k]= A[k-1];
		A[k-1]= temp;
		k--;
    num_cmps++; 


		//std:: cout<<"this are the number of comparissons"<<num_cmps++<<std::endl;
		}

 }


}
