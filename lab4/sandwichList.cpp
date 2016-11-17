/* sandwichList.cpp
 * Comp 15 
 * Spring 2014 
 * Lab 4
 */

#include "sandwichList.h"


SandwichList::SandwichList()
{
	capacity = INITIAL_SIZE;
	orders = new Order[INITIAL_SIZE];
	orderCount = 0;

	back = 0;
	front = 0;
}

bool SandwichList::isEmpty()
{
	if (size() == 0)
		return true;
	else
		return false;
}


int SandwichList::size()
{
        return orderCount;
        // you could use the following arithmetic (but be careful):
	//return (back - front + capacity) % capacity;
}

//function to remove Order from the front of the queue
Order SandwichList::dequeue()
{

// TODO: Students write code here
	Order temp = orders[front];
	front = (front+1) % capacity;
	orderCount --;
	return temp;
}

//add an element, make sure it is not full, if it is call expand funciton
void SandwichList::enqueue(const Order& sw)
{

// TODO: Students write code here
	if (orderCount == capacity){
		expandList();
	}
	orders[back] = sw;
	orderCount ++;
	back = (back+1) % capacity;
}

//Double the queue size, copy the values, and reset back and front
void SandwichList::expandList()
{

// TODO: Students write code here

//1)
	//Create a new array with 2x capacity
	Order *temp = new Order[capacity*2];

//2)
	//copy in elements from old array (be careful of wrap around)

	for (int i = 0; i < orderCount; i++){
		temp[i] = orders[((front+i)%capacity)];
	}

	//update front and back
	front = 0;
	back = orderCount;

//3)
	//delete old array
	delete [] orders;

//4)
	//point at new array
	orders = temp;

//5)
	//update current capacity
	capacity = capacity*2;

}

void SandwichList::printOrder(Order s)
{
	cout << s.sandwich << " " << s.customerName << " " << s.orderNbr << " " << s.fries;
	cout << endl;
}



