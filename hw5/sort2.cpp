// Written by Grant Pemberton 11/7/2014
//  InsertionSort.cpp
//  Sorts integers using the InsertionSort algorithm


#include "sort2.h"

using namespace std;

InsertionSort::InsertionSort(){ // constructor
        sortArray.length = 0;
        sortArray.arr = NULL;
}

// reads in a list of integers from stdin and returns an arrayWithLength
void InsertionSort::readList(){
        int currentCapacity = 10;
        sortArray.arr = new int[currentCapacity];
        
        while (cin >> sortArray.arr[sortArray.length]) {
                ++sortArray.length;
                if (sortArray.length==currentCapacity) {
                        int *temp = new int[currentCapacity*2];
                        for (int i=0;i<currentCapacity;i++) {
                                temp[i] = sortArray.arr[i];
                        }
                        delete [] sortArray.arr;
                        sortArray.arr = temp;
                        currentCapacity *= 2;
                }
        }
}

void InsertionSort::sort(){
        // Insertion sort on sortArray

	for (int i = 1; i < sortArray.length; i++){//loop through array
		//NOTE: zeroeth element is checked below
		int j = i;
		while ((j > 0) && (sortArray.arr[j-1] > sortArray.arr[j])){
			//checks in bounds of array (because we check (j-1))
			//if an element is greater than its next element
			//then swap them
			swap(j, (j-1));
			//j-1 is the new index in question
			j -= 1;
		}
	}
}

//added 1/30/2015
void InsertionSort::rsort(int start){

	int j = start;
	for (int i = start; i < sortArray.length; i++){//loop through array
		//NOTE: zeroeth element is checked below
		//int j = i;
		if ((j>0) && (sortArray.arr[j] > sortArray.arr[j-1])){
			j++;
		}else{
			cerr << j << endl;
			swap(j, (j-1));
			//j++;
			rsort(j);
		}
	}
}

//for comp 160 ^^this doesnt work for the 0th index for some reason :(

void InsertionSort::printArray(){
        // prints out the integers in sorted order
	
	for (int i = 0; i < sortArray.length; i++){
		cout << sortArray.arr[i] << endl;
	}
}

void InsertionSort::swap(int index1, int index2){
	//swap helper function
	
	int temp = sortArray.arr[index1];
	//use of temp preserves the information in index1
	
	//swap the two values
	sortArray.arr[index1] = sortArray.arr[index2];
	sortArray.arr[index2] = temp;
}



