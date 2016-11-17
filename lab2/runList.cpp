//
//  runList.cpp
//  OrderedRunners
//
//  Created by Chris Gregg on 1/31/14.
//  Copyright (c) 2014 Chris Gregg. All rights reserved.
//

#include "runList.h"
#include "runner.h"
#include <iostream>
using namespace std;

RunList::RunList() {
	head = NULL;
	tail = NULL;
}

RunnerNode *RunList::getHead(){
	return head;
}

RunnerNode *RunList::getTail(){
	return tail;
}

void RunList::insertInOrder(string runnerName,int runnerTime) {

	RunnerNode *newNode = new RunnerNode();

	newNode->aRunner = Runner(runnerName,runnerTime);

	RunnerNode *tempNode = head;

	if(tempNode == NULL) { // there aren't any nodes yet
		insertBefore(head,newNode);
	}
	else {
		// TODO: Students enter code here
		while (tempNode != NULL){
			if (tempNode -> aRunner.isFasterThan(newNode->aRunner)){
				insertBefore(tempNode, newNode);
				break;
			}else{
				insertAfter(tempNode, newNode);
				break;
			}
//			cerr << "I'm still looping" << endl;
			tempNode -> prev = tempNode;
			tempNode = tempNode -> next;

		}
	}
}

void RunList::insertBefore(RunnerNode *aNode,RunnerNode *newNode) {
	//Given a new node "newNode" that will go before "aNode"
	if (head == NULL){ //no list yet
		head = newNode;
		newNode -> next = NULL;
		newNode -> prev = NULL;
	}
	//degenerate case

	else{
		// TODO: Students enter code here

		newNode -> next = aNode;
		//newNode next points to aNode

		(aNode->prev)->next = newNode;
		//(aNode -> prev)-> next points to newNode

		(newNode -> prev) = (aNode -> prev);
		//newNode prev points to aNode prev

		aNode -> prev = newNode;
		//aNode prev points to newNode


	}
}
void RunList::insertAfter(RunnerNode *aNode, RunnerNode *newNode) {
	if (aNode == NULL) { // empty list
		head = newNode;
		tail = newNode;
	}
	else {
		newNode->prev = aNode;
		newNode->next = aNode->next;
		if (newNode->next==NULL) { // at the tail
			tail = newNode;
		}
		else {
			newNode->next->prev = newNode;
		}

		aNode->next = newNode;
	}

}

void RunList::printList(bool reversed){
	RunnerNode *iterator;

	if (reversed) {
		iterator = tail;
	}
	else {
		iterator = head;
	}

	while (iterator != NULL) {
		cout << iterator->aRunner.getName() << ": ";
		cout << iterator->aRunner.getTime() << "\n";
		if (reversed) {
			iterator = iterator->prev;
		}
		else {
			iterator = iterator->next;
		}
	}
}
