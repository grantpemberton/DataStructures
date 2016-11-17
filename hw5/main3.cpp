// Written by Grant Pemberton 11/7/2014
//  main3.cpp
//  Sorting
//  ShellSort

#include <iostream>
#include "sort3.h"

using namespace std;

int main()
{
        ShellSort sorter;
        
        sorter.readList();
        sorter.sort();
        cout << "Output:\n";
        sorter.printArray();
	return 0;
}
