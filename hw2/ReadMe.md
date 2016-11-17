# ReadMe for COMP 15 HW2 
## Linked Lists
Grant Pemberton


The purpose of your program:

The Purpose of the program was to model a deck of cards using a linked list
data structure to implement the abstract data type of a deck

List of files with one/or two-line summary:

card.cpp
  implementation for the functions that detail how a card can act 
  and different functions that can be performed on a card such as setting 
  suit and setting rank
card.h
  header file for each card, lists the functions for how a card can act 
  and different functions that can be performed on a card such as setting 
  suit and setting rank
hand.cpp
  implementation for each hand, details functions for how a hand can act 
  and different functions that can be performed on a hand such as shuffling
  cards, removing cards
hand.h
  header file for each hand, lists the functions for how a hand can act 
  and different functions that can be performed on a hand such as shuffling
  cards, and removing cards
List_linked_list.cpp
  implementation for the list of cards, structure of functions for how a list acts 
  and different functions that can be performed on a lists such as adding cards,
  removing cards, and other operations
List_linked_list.h
  header file for the list of cards, lists the functions for how a list acts 
  and different functions that can be performed on a lists such as adding cards,
  removing cards, and other operations  
main.cpp
  interface file: this runs the program by inserting cards into a list and forming
  hands from those cards. main can really be anything
Makefile
  associated Makefile allows a user to build the program (more detailed in the following text)

How to compile:

   The code may be compiled using the included Makefile.

Outline of data structure:

>the data structure used in this assignment was a linked list. Each node
of the linked list contained a pointer to card information for that node
and it also contained a pointer to the next node in the list. Using a linked
list meant that indexing algorithms were different from if this project was 
implemented with a dynamic array

Functions Used by List_linked_list: 

List_linked_list();  constructor
~List_linked_list(); destructor 

// copy constructor
List_linked_list(const List_linked_list& source);
// operator= overload
List_linked_list operator =(const List_linked_list& source);

void print_list();
void print_list_int();
bool is_empty() { return head==NULL; }

int cards_in_hand();  returns the number of cards in the hand
void make_empty();  empties the list; head should equal NULL

void insert_at_head(Card c); inserts a card at the head 
void insert_at_tail(Card c); inserts a card at the tail
void insert_at_index(Card c, int index); inserts a card at the given
index
void replace_at_index(Card c, int index);replaces the card at the given
index
Card card_at(int index); determines the card at the index
bool has_card(Card c); determines if the card is in the list
bool remove(Card c); finds the card and removes it
Card remove_from_head(); removes the card from the head 
Card remove_from_tail(); removes the card from the tail
Card remove_from_index(int index);removes the card from the index







































# ReadMe for COMP 15 HW1 
## Dynamic Arrays
//Written by Grant Pemberton (Colaboration with Becky Cutler)
//Date: 9/12/2014
Every assignment you submit you will include a ReadMe file. The name
could be ReadMe, readme, Read-me.txt, readME, ReadMe.md (the “.md”
stands for “markdown,” which allows lightweight formatting) or almost
anything you like that has the word read followed by the word me. Exact
spelling is not important, the contents are.

The purpose of the ReadMe file is the same as the little paper insert
you get in a new appliance -- to give the reader an introduction and
overview of the product.

1.  The purpose of your program
//The purpose of this program is to model how a deck of cards can be made, shuffled, reordered, and
//divided into hands. Complex and simple operations on the deck may also be performed (removing cards at spe-
//cified indicies ...)

2.  List of files with one/or two-line summary
card.cpp
  implementation for the functions that detail how a card can act 
  and different functions that can be performed on a card such as setting 
  suit and setting rank
card.h
  header file for each card, lists the functions for how a card can act 
  and different functions that can be performed on a card such as setting 
  suit and setting rank
hand.cpp
  implementation for each hand, details functions for how a hand can act 
  and different functions that can be performed on a hand such as shuffling
  cards, removing cards
hand.h
  header file for each hand, lists the functions for how a hand can act 
  and different functions that can be performed on a hand such as shuffling
  cards, and removing cards
List_dynamic_array.cpp
  implementation for the list of cards, structure of functions for how a list acts 
  and different functions that can be performed on a lists such as adding cards,
  removing cards, and other operations
List_dynamic_array.h
  header file for the list of cards, lists the functions for how a list acts 
  and different functions that can be performed on a lists such as adding cards,
  removing cards, and other operations  
main.cpp
  interface file: this runs the program by inserting cards into a list and forming
  hands from those cards. main can really be anything
Makefile
  associated Makefile allows a user to build the program (more detailed in the following text)
3.  How to compile it (saying "use included Makefile" is ok)
using the Makefile
  this program comes with a Makefile. to compile the program, type "make" into the
  the terminal
4.  Outline of data structure (depending on the assignment)
Data Structure
  The data structure used in this program is a dynamic array. Its memory is stored in heap
  so that the data inside isn't destroyed when an activation record is deleted. '
5.  Outline of algorithm (depending on the assignment)
N/A

The ReadMe file shows the reader, in a quick glance, what the program is
about and gives a general idea of how it works. For short programs the
readme file will be short, for more complicated programs the readme file
will be longer.

Use outline form rather than long discursive paragraphs. A ReadMe file
is an overview.

There is no correct readme format; within these guidelines, devise your
own style.



