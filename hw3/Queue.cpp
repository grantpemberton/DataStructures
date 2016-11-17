/*
Written By: Grant Pemberton (9/29/2014)
 * Queue.cpp
 *
 */

#include <iostream>
#include "Queue.h"


Queue::Queue(){
// constructor

	capacity = QUEUE_INIT_CAPACITY;
	queue_array = new Student [capacity];
	size = 0;
	back = 0;
	front = 0;
}

Queue::~Queue(){
// destructor

	delete [] queue_array;

}

void Queue::enqueue(Student c){
// enqueue a char onto at the back of the queue

	if (size == capacity) expand();

	queue_array[back] = c;

	back  = (back+1) % capacity;
	size ++;

}

Student Queue::dequeue(){
// dequeue a char from the front of the queue

	Student temp;
	temp = queue_array[front];
	front = (front +1)%capacity;
	size --;
	return temp;
}

bool Queue::is_empty(){
// returns true if there are no elements in the
// queue, false if the queue has elements

	if (size == 0){
		return true;
	}
	else{
		return false;
	}
}

void Queue::expand (){
//1)
	//Create a new array with 2x capacity
	Student *temp = new Student[capacity*2];

//2)
	//copy in elements from old array (be careful of wrap around)

	for (int i = 0; i < size; i++){
		temp[i] = queue_array[((front+i)%capacity)];
	}

	//update front and back
	front = 0;
	back = size;

//3)
	//delete old array
	delete [] queue_array;

//4)
	//point at new array
	queue_array = temp;

//5)
	//update current capacity
	capacity = capacity*2;

}
