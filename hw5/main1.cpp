// Written by Grant Pemberton 11/7/2014
//  main1.cpp
//  Sorting
//  SelectionSort

#include <iostream>
#include "SelectionSort.h"

using namespace std;

int main()
{
        SelectionSort sorter;
        
        sorter.readList();
        sorter.sort();
        cout << "Output:\n";
        sorter.printArray();
	return 0;
}
