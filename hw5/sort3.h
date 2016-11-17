//
//  ShellSort.h
//  Header File for SelectionSort class
//

#ifndef __Sorting__ShellSort__
#define __Sorting__ShellSort__

#include <iostream>

struct arrayWithLength{
        int length;
        int *arr;
};

class ShellSort {
public:
        ShellSort(); // constructor
        
        // read in a list of values from stdin
        void readList();
        
        // sort function
	void sort();
        


        // print the array
        void printArray();
        
private:
        arrayWithLength sortArray;
	
	//calculates an appropriate gap size based on the array size
	void CiuraShellSort();
	void HibbardShellSort();
	void swap(int index1, int index2);
	int HibbardGapSize(int k);
};

#endif /* defined(__Sorting__ShellSort__) */
