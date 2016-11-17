#include <iostream>
#include <stdio.h>
#include "hector.h"

using namespace std;
//
// hector.cpp -- compare three different collision solutions
//
// your job: code the insert functions
//  our job: run the three insert functions and report results
//

// constructor
Hector::Hector()
{
	for(int i = 0; i < TSIZE; i++)
	{
		cheneyTable[i] = NULL;
		linnyTable[i] = -1;
		doublesTable[i] = -1;
	}
}


// linear probing
//
//  returns number of collisions before finding a spot
//
int Hector::linny(int value)
{
	int attempt = 0;
	int index;
	bool found = false;
	while(!found)
	{
		index = Hhash(value,0,attempt);
		if (linnyTable[index] == SENTINEL){
			linnyTable[index] = value;
			found = true;
		}else{
			attempt++;
		}
	}
	return attempt;
}

// double hashing using a second function
//  
//  returns number of collisions before finding a spot
//
int Hector::doubles(int value)
{

	int attempt = 0;
	int index;
	bool found = false;
	while(!found)
	{
		index = Hhash(value,1,attempt);
		if (doublesTable[index] == SENTINEL){
			doublesTable[index] = value;
			found = true;
		}else{
			attempt++;
		}
	}
	return attempt;
	
}

// chained hashing -- each spot in table is a linked list 
//
//  returns number of items in that spot before insertion
//
int Hector::cheney(int value)
{
	//before insertion???
	int counter = 1;
	Node *counterNode = cheneyTable[Hhash(value,0,0)];
		while (counterNode != NULL){
			counterNode = counterNode->next;
			counter++;
		}

	return counter;

	//try to insert
	if (cheneyTable[Hhash(value,0,0)] == NULL){//the index is empty
		Node *newNode = new Node;
		newNode->key = Hhash(value,0,0);
		newNode->next = NULL;
		cheneyTable[Hhash(value,0,0)] = newNode;
		//this should end up returning 1
	}else{//there is a collision
		Node *tempNode = new Node;
		tempNode->key = Hhash(value,0,0);
		tempNode->next = cheneyTable[Hhash(value,0,0)];
		cheneyTable[Hhash(value,0,0)] = tempNode;
	}




	//if there is no collision then insert the value and return 1
	//if there is a collision, then insert the value at the head, and then traverse the list. Return the number of nodes in the list
}

// print the hash tables
void Hector::print()
{
	for(int i=0; i < TSIZE; i++)
	{
		cout << linnyTable[i] << " ";
		
	}
	
	cout << endl;
	
	for(int i=0; i < TSIZE; i++)
	{
		cout << doublesTable[i] << " ";
		
	}
	cout << endl;
	
	Node* iter = NULL;
	for(int i=0; i < TSIZE; i++)
	{
		iter = cheneyTable[i];
		cout << "[ ";
		while(iter != NULL)
		{
			cout << iter->key << " ";
			iter = iter->next;
		}
		cout << "]";
	}
	cout << endl;
}

int Hector::Hhash(int value, bool jump, int attempt){
	if (!jump){
		return ((3*(value))+7+attempt)%17;
	}else{
		return ((3*(value))+7+attempt*(13-(value%13)))%17;
	}


}
