// Written by Grant Pemberton 11/7/2014
//  main2.cpp
//  Sorting
//  InsertionSort

#include <iostream>
#include "sort2.h"

using namespace std;

int main()
{
        InsertionSort sorter;
        
        sorter.readList();
        sorter.sort();
	//sorter.rsort(1);
        cout << "Output:\n";
        sorter.printArray();
	return 0;
}
