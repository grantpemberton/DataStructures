// List_linked_list.cpp
// Written by: Grant Pemberton 
// [colaboration C.Gregg (tests)]
// Date: 9/20/2014
// Last Modified: 9.26/2014 20:47

#include <iostream>
#include <cstdlib>
#include <time.h>

#include "hand.h"

using namespace std;
int main()
{
	List_linked_list ll;
	
	Card c('A', 'D');
	
	ll.insert_at_index(c,0);
	ll.print_list();
	c.set_suit(HEART);
	c.set_rank(TEN);
	ll.insert_at_index(c,0);
	ll.print_list();
	
	c.set_suit(SPADE);
	c.set_rank(FIVE);
	ll.insert_at_index(c,1);
	ll.print_list();
	
	c.set_suit(CLUB);
	c.set_rank(TWO);
	ll.insert_at_index(c,3);
	ll.print_list();
	
	c.set_rank(NINE);
	ll.insert_at_index(c,0);
	ll.print_list();

	return 0;

}
