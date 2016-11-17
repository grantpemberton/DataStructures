// List_linked_list.cpp
// Written by: Grant Pemberton
// Date: 9/20/2014
// Last Modified: 9.26/2014 20:47


#include "List_linked_list.h"

#include <iostream>
#include <cassert>
#include <cstdlib>

using namespace std;


List_linked_list::List_linked_list()
{
// constructor
	head = NULL;
}

List_linked_list::~List_linked_list() //destructor
{
// delete list by looping through and deleting each node

	Card_Node *tempNode = head;
	//pointer that is searching for the specified card
	Card_Node *tempNodeprev = head;
	//pointer that keeps track of the card at the index before the 
	//removed card

	if (tempNode == NULL){ //no list (list is already destructed)
	    return;
	}

	head = NULL;
	while (tempNode-> next != NULL){
		tempNodeprev = tempNode;
		tempNode = tempNode -> next;
		tempNodeprev ->next = NULL;
		delete tempNodeprev;
	}	
	delete tempNode;	


//note: it looks like another way to accomplish this function 
//is lines 7-12 of the "operator =" function
//
}

// copy constructor
List_linked_list::List_linked_list(const List_linked_list& source) 
{
	// explicit copy constructor necessary because of cards array
	if (source.head == NULL) return; // nothing to do

	head = new Card_Node;
	Card_Node *this_current = head;
	Card_Node *source_current = source.head;

	while (source_current != NULL) {
		// deep copy each Card_Node
		if (source_current->next != NULL) {
			Card_Node *new_node = new Card_Node();
			this_current->next = new_node;
			new_node->card = source_current->next->card;
		}
		else {
			this_current->next = NULL; // at tail
		}
		source_current = source_current->next;
		this_current = this_current->next;
	}
}

// operator= overload
List_linked_list List_linked_list::operator =(const List_linked_list&
		source) 
{
	// explicit operator= overload necessary because of cards array

	// check for self-assignment -- return without doing anything
	if (this == &source) {
		return *this;
	}
	// delete all current cards
	while (head != NULL) {
		Card_Node *next = head->next;
		delete head;
		head = next;
	}
	// copy over all cards from source list
	if (source.head == NULL) return *this; // nothing to do

	head = new Card_Node;
	Card_Node *this_current = head;
	Card_Node *source_current = source.head;

	while (source_current != NULL) {
		// deep copy each Card_Node
		this_current->card = source_current->card;
		if (source_current->next != NULL) {
			Card_Node *new_node = new Card_Node();
			this_current->next = new_node;
		}
		else {
			this_current->next = NULL; // at tail
		}
		source_current = source_current->next;
		this_current = this_current->next;
	}
	return *this;
}

void List_linked_list::print_list()
{
	Card_Node *current = head;
	while (current != NULL) {
		current->card.print_card();
		if (current->next != NULL) {
			cout << ",";
		}
		else {
			cout << "\n";
		}
		current = current->next;
	}
}

void List_linked_list::print_list_int()
{
	Card_Node *current = head;
	while (current != NULL) {
		current->card.print_card_int();
		if (current->next != NULL) {
			cout << ",";
		}
		else {
			cout << "\n";
		}
		current = current->next;
	}
}

int List_linked_list::cards_in_hand()
{
// returns the number of cards in the hand
	int i = 0;
	Card_Node *tempNode = head;
	if (tempNode == NULL){
		return i;
	}

	while (tempNode != NULL){
	    i++;
	    tempNode = tempNode -> next;
	}
	return i;
}
void List_linked_list::make_empty()
{
// empties the list; head should equal NULL

	head -> next = NULL;
	head = NULL;
  
}
void List_linked_list::insert_at_head(Card c)
{
// inserts a card at the head
// Should allow insert into an empty list

	Card_Node *newNode = new Card_Node();
	newNode -> card = c;
	Card_Node *tempNode = head;

	if (tempNode == NULL){ //no list yet
		head = newNode;
		newNode -> next = NULL;
	}else{ //have list
		newNode -> next = head;
		//update newNode's next to point where head did
		head = newNode;
		//head now points at newNode
	}
}
void List_linked_list::insert_at_tail(Card c)
{
// inserts a card at the tail (final node)
// should allow insert into an empty list

	Card_Node *newNode = new Card_Node();
	newNode -> card = c;
	Card_Node *tempNode = head;

	if (tempNode == NULL){ //no list yet
		head = newNode;
		newNode -> next = NULL;

	}else{//have valid list
		while (tempNode->next != NULL){
			tempNode = tempNode -> next;//step through list until
						    //tempNode next
						    //points at NULL
		}
		tempNode -> next = newNode;//tempNode's next points at newNode
		newNode -> next = NULL;//newNode's next points at NULL
	}
}

void List_linked_list::insert_at_index(Card c, int index)
{
// inserts a card at an index such that
// all cards following the index will be moved farther
// down the list by one.
// The index can be one after the tail of the list
// I.e., you can insert at index 0 into an empty list,
// and you can insert at index 4 in a list with 4 nodes.
// In the first case, the node inserted would become the head
// In the second case, the node inserted would be inserted
// after the current tail.
	
	Card_Node *newNode = new Card_Node;
	Card_Node *tempNode = head;
	Card_Node *tempNodeprev = head;
	newNode->card = c;
	int i = 0;
	
	if(head == NULL) {
		head = newNode;
		newNode->next = NULL;
		return;
	}
	
	else if (index == 0) {
		insert_at_head(c);
		return;
	}
	else {
		while ((i < index) && tempNode != NULL) { 
			tempNodeprev = tempNode;
			tempNode = tempNode->next;
			i++;
		}
		newNode->next = tempNode;
		tempNodeprev->next = newNode;
	}
}

void List_linked_list::replace_at_index(Card c, int index)
{
// inserts a card at an index such that
// all cards following the index will be moved farther
// down the list by one.
// The index can be one after the tail of the list
// I.e., you can insert at index 0 into an empty list,
// and you can insert at index 4 in a list with 4 nodes.
// In the first case, the node inserted would become the head
// In the second case, the node inserted would be inserted
// after the current tail.
// replaces the card at index
// A card at index must already exist

//schematic of list in counter notation
// [ ]->[ ]->[ ]->[ ]->[ ]->[ ]->[ ]->[ ]->NULL
//  0    1    2    3    4    5    6    7    8

	Card_Node *newNode = new Card_Node(); 
	newNode -> card = c;	//card(c.get_rank(), c.get_suit());	
				//create new Card_Node with card identity c
	int i = 0;
	Card_Node *tempNode = head;		
	//pointer that is searching for the specified card

	if (tempNode == NULL){ 	//no list yet
		head = newNode;	//inserts card into empty list
		newNode -> next = NULL;
		return;
	}
	while (i < index && tempNode -> next != NULL){
	//step through list until i is equal to the index 
	//(if index is 3, this loop will terminate when tempNode points at 3)
	    tempNode = tempNode -> next;
	    i++;
	}
	
	tempNode -> card.set_suit(c.get_suit());
	tempNode -> card.set_rank(c.get_rank());
}

Card List_linked_list::card_at(int index)
{
// returns the card at index.
// allowed to crash if index is not in the list

//schematic of list in counter notation
// [ ]->[ ]->[ ]->[ ]->[ ]->[ ]->[ ]->[ ]->NULL
//  0    1    2    3    4    5    6    7    8

	int i = 0;
	Card_Node *tempNode = head;		
	//pointer that is searching for the specified card
	
	if (head == NULL){ //no list yet
		exit (EXIT_FAILURE);	
		//kills program if the card doesnt exist in the list
	}
    
	while (i < index && tempNode -> next != NULL){
	//step through list until i is equal to the index 
	//(if index is 3, this loop will terminate when tempNode points at 3)
		tempNode = tempNode -> next;
		i++;
	}
	return tempNode -> card;

	
}
bool List_linked_list::has_card(Card c)
{	
//comparison of info from c to the info in a cardNode
//create tempNode pointing to head buisness
	
	Card_Node *tempNode = head;

	if (tempNode == NULL){ //no list yet
		return false;//if the list is empty, return false
	}
	while (tempNode->next != NULL){//have valid list
		//loop through list until we have a card thats the same card
		if (!tempNode->card.same_card(c)){
			tempNode = tempNode -> next;
		}else{ //tempNode's card is the same as the input card
			return true; // returns true if the card is in the list
		}
	}
	return false;	// returns false if the card is not in the list
}
bool List_linked_list::remove(Card c)
{
// removes the card from the list
// Returns true if the card was removed
// Returns false if the card was not in the list

	Card_Node *tempNode = head;
	//pointer that is searching for the specified card
	Card_Node *tempNodeprev = head;
	//pointer that keeps track of the card at the index before the 
	//removed card
	if (tempNode == NULL){ //no list yet
		return false;
	}
    
	while (tempNode-> next != NULL){
		if (!tempNode->card.same_card(c)){
			tempNodeprev = tempNode;
			tempNode = tempNode -> next;
		}else{
			tempNodeprev -> next = tempNode -> next;
			return true;
		}
	}
	return false;

}
Card List_linked_list::remove_from_head()
{
// Removes the card from the head, and assigns the head
// to head->next
// Returns the card that was removed
// Allowed to fail if list is empty

	Card_Node *tempNode = new Card_Node;
	tempNode -> card = head -> card;
	if (tempNode == NULL){ //no list yet
		exit (EXIT_FAILURE);	
		//kills program if the card doesnt exist in the list
	}
    
	head = head -> next;
	return tempNode -> card;

}
Card List_linked_list::remove_from_tail()
{
// removes the card from the list
// Returns true if the card was removed
// Returns false if the card was not in the list
// Removes the card from the tail
// Returns the card that was removed
// Allowed to fail if the list is empty

	Card_Node *tempNode = head;
	//pointer that is searching for the specified card
	Card_Node *tempNodeprev = head;
	//pointer that keeps track of the card at the index before the 
	//removed card
	if (head == NULL){ //no list yet
		exit (EXIT_FAILURE);	
	}
    if (head -> next == NULL){
	    tempNode = head;
	    head = NULL;
	    return tempNode -> card;
    }
	while (tempNode-> next != NULL){
		tempNodeprev = tempNode;
		tempNode = tempNode -> next;
	}
	tempNodeprev -> next = NULL;
	return tempNode -> card;


}
Card List_linked_list::remove_from_index(int index)
{
//schematic of list in counter notation
// [ ]->[ ]->[ ]->[ ]->[ ]->[ ]->[ ]->[ ]->NULL
//  0    1    2    3    4    5    6    7    8
	
	int i = 0;
	Card_Node *tempNode = head;		
	//pointer that is searching for the specified card
	Card_Node *tempNodeprev = head;		
	//pointer that keeps track of the card at the index before the 
	//removed card
	if (head == NULL){ 	//no list yet
		exit (EXIT_FAILURE);	
		//kills program if the card doesnt exist in the list
	}
	if (index == 0){
		head = head -> next;
		return tempNode -> card;
	}
	
	while (i < index && tempNode -> next != NULL){
	//step through list until i is equal to the index 
	//(if index is 3, this loop will terminate when tempNode points at 3)
		tempNodeprev = tempNode;
		tempNode = tempNode -> next;
		i++;
	}
    
	tempNodeprev -> next = tempNode -> next;
	//update pointers to point the second to last node to next of tempNode 
	//(excludes index node)
	return tempNode -> card;//return the removed card :)
}

