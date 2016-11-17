# ReadMe for COMP 15 HW4
## Binary Search Tree Assignment 

Every assignment you submit you will include a ReadMe file. The name
could be ReadMe, readme, Read-me.txt, readME, ReadMe.md (the “.md”
stands for “markdown,” which allows lightweight formatting) or almost
anything you like that has the word read followed by the word me. Exact
spelling is not important, the contents are.

The purpose of the ReadMe file is the same as the little paper insert
you get in a new appliance -- to give the reader an introduction and
overview of the product.

Your ReadMe file for the assignments **must** include:

1.  The purpose of your program

2.  List of files with one/or two-line summary
	BinarySearchTree.h
		Declaration of functions for a binary search tree, these functions include find_max(), find_min(), contains(value), remove(value)
		descriptions of these functions can be found in this file
	BinarySearchTree.cpp
		Implementation and definition of funcitons declared in BinarySearchTree.h. Almost every function has a public and private variant.
		The public variant calls the private variant with the root as its starting node.
	pretty_print.cpp
		Helper function written by Chris Gregg to print the tree in a more human pleasing way
	main#.cpp
		each main#.cpp tests for a different thing. These were provided by Chris Gregg
		to use these main#.cpp files, the Makefile was modified
		after testing, the Makefile was reset to its original text

3.  How to compile it
	Use associated Makefile

4.  Outline of data structure (depending on the assignment)
	The abstract data type is a binary search tree, which is implemented by a linked list where each node has a left and right pointer

5.  Outline of algorithm
	Several functions utilize a recursive algorithm in either pre-order or post-order orientation
	the remove function has an algorithm that is dependent on how many children the node that is to be removed has
		if 0 child -> delete the node's contents and clean up memory
		if 1 child -> jump over the node
		if 2 children -> replace node's data with the data of the min node in the right sub tree and recursively delete the min node

6.  A list of people who materially helped you on the assignment
	Rebecca Cutler
	Daniel Baigel


7. Notes:
	//I have tried for so long to debug for main21.cpp, could whoever is grading this please help me figure out where I'm going wrong? thanks