/*
 * main17.cpp
 *
 *  Created on: Oct. 14, 2014
 *      Author: chrisgregg
 */
#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

int main() {
        int rand_ints[12]={5,3,6,11,-5,-2,15,4,4,9,14,8};

        BinarySearchTree bst;
        for (int i=0;i<12;i++) {
                cout << "Inserting " << rand_ints[i] << "\n";
                bst.insert(rand_ints[i]);
        }
        bst.print_tree();
        cout << "Removing 8.\n";
        bst.remove(8);
        bst.print_tree();

        return 0;
}