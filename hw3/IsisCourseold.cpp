/*
 * IsisCourse.cpp
 *
 */

#include <iostream>
#include "IsisCourse.h"

using namespace std;

IsisCourse::IsisCourse() {
	class_capacity = 0; // no students allowed in yet
}

IsisCourse::IsisCourse(int init_capacity) {
//constructor
	// TODO: Student writes code here
	class_capacity = init_capacity;
	
}

IsisCourse::~IsisCourse() {
//destructor
	// nothing to do
}

void IsisCourse::set_class_cap(int cap) {

	class_capacity = cap;
	if (roster.size() < class_capacity) {
		update_enrollments();
	}
}

IsisCourse::ENROLLMENT_STATUS IsisCourse::enroll_student(Student s) {
	// See the enrollment logic from the assignment handout or
	// the IsisCourse.h file!
	// TODO: Student writes code here
	
	// Attempts to enroll a student into the class.
	// Majors go directly into the class, and non-majors
	// go directly onto the waitlist, even if there is space
	// in the class.
	// Simplification: you do not need to check if a student is
	// on a waitlist already before placing that student onto
	// the appropriate waitlist.
	

	if (s.major){
		if (get_roster_size() < class_capacity){//there's room in the course for majors
			//enroll that student
			roster.add(s);
			return ENROLLED;
		}else{
			major_waitlist.enqueue(s);
			return MAJOR_WAITLIST;
		}
	}else{//student is not a major
		other_waitlist.enqueue(s);
		return OTHER_WAITLIST;
	}
	
	return NONE;
	
	
}

bool IsisCourse::drop_student(Student s) {
	bool found_student = false; // if we find the student to drop
	// TODO: Student writes code here
	
	// Attempts to drop a student from the class AND the waitlists
	// Returns true if student was successfully dropped,
	// false if the student was not on any list
	
	//LOOK INTO THE WAITLIST POSITION METHOD FOR THIS FUNCTION
	Queue temp_queue;
	Student temp;
	//int i = 0;
//use status member function
//4 cases: NONE, ENROLLED, MAJOR_WAITLIST, OTHER_WAITLIST
	if (status(s) == NONE){
		found_student = false;
	}
	if (status(s) == ENROLLED){
		if(roster.drop(s)){
			found_student = true;
		}
	}
	if (status(s) == MAJOR_WAITLIST){
		//requeue routine
		while (!major_waitlist.is_empty()){
			temp_queue.enqueue(major_waitlist.dequeue());
		}
		while (!temp_queue.is_empty()){
			temp = temp_queue.dequeue();
			if (temp.name == s.name){
				found_student = true;
			}else{
				major_waitlist.enqueue(temp);
			}
		}
	}
	if (status(s) == OTHER_WAITLIST){
		//requeue routine
		while (!other_waitlist.is_empty()){
			temp_queue.enqueue(other_waitlist.dequeue());
		}
		while (!temp_queue.is_empty()){
			temp = temp_queue.dequeue();
			if (temp.name == s.name){
				found_student = true;
			}else{
				other_waitlist.enqueue(temp);
			}
		}
		
	}
	// if we dropped a student, there should be room on
	// the roster
	update_enrollments();
	return found_student;

}

int IsisCourse::waitlist_position(ENROLLMENT_STATUS status, Student s) 
{
	// TODO: Student writes code here
	// returns the waitlist position for a student for a
	// particular waitlist (MAJOR_WAITLIST or OTHER_WAITLIST)
	
	//look in the waitlist that is indicated by the enrollment status
	//need to loop through the queue until we find the identified student
		//enqueue whatever is dequeue'd until the student is found
//	int i = 0; //is this out of the scope of the while loops?
//	Queue *waitlist_queue;
	Queue temp_queue;

	if (status == MAJOR_WAITLIST) {
		temp_queue = major_waitlist;
		int i = 0; //see comment a
		while (!temp_queue.is_empty()){
			if ((temp_queue.dequeue()).name == s.name){//other possible comparison?
				return i;
			}else{
				i++;
			}
		}
	}
	else if (status == OTHER_WAITLIST){
		temp_queue = other_waitlist;
		int i = 0; //see comment a
		while (!temp_queue.is_empty()){
			if ((temp_queue.dequeue()).name == s.name){//see ^^
				return i;
			}else{
				i++;
			}
		}
	}
	
	return -1; //student is enrolled or they are none

}
IsisCourse::ENROLLMENT_STATUS IsisCourse::status(Student s) 
{
	// returns an ENROLLMENT_STATUS that says which list
	// (or none) that the student is on.

	// TODO: Student writes code here
	
	// returns the status of a student (NONE, ENROLLED,
	// MAJOR_WAITLIST, or OTHER_WAITLIST)

	Queue temp_queue;
	
	if (s.major){//they are a major
//		int i = 0;
//		for (int i = 0; i < class_capacity; i++){
			if (roster.is_enrolled(s)){
				return ENROLLED;
			}
//		}
		temp_queue = major_waitlist;

		while (!temp_queue.is_empty()){
			if ((temp_queue.dequeue()).name == s.name){
				return MAJOR_WAITLIST;
//			}else{
//				i++;
			}
		}
		return NONE;
	}else{//they are not a major
		
		temp_queue = other_waitlist;
//		int i = 0;
//		for (int i = 0; i < class_capacity; i++){
			if (roster.is_enrolled(s)){
			return ENROLLED;
			}
//		}
		
		while (!temp_queue.is_empty()){
			if ((temp_queue.dequeue()).name == s.name){
				return OTHER_WAITLIST;
//			}else{
//				i++;
			}
		}
		return NONE;
	}
}

void IsisCourse::print_list(ENROLLMENT_STATUS status) 
{
	// prints the roster (ENROLLED) or waitlist
	// (either MAJOR_WAITLIST or OTHER_WAITLIST)
	// in the following form (names should be in priority from
	// the waitlist):
	// 1. student.name
	// 2. student.name
	// 3. student.name
	// etc.
	Queue *waitlist_queue;
	Queue temp_queue;
	
	if (status == ENROLLED) {
		roster.print_class();
		return;
	}
	
	if (status == MAJOR_WAITLIST) {
		waitlist_queue = &major_waitlist;
	}
	
	else {
		waitlist_queue = &other_waitlist;
	}
	// now handle printing the queue

	// TODO: Student writes code here
	Student temp;
	int i = 1;

	while (!waitlist_queue->is_empty()){//need arrow notation???
		temp_queue.enqueue(waitlist_queue->dequeue());//need arrow notation???
	}
	
	while (!temp_queue.is_empty()){
		temp = temp_queue.dequeue();
		cout << i << ". " << temp.name << endl;
		major_waitlist.enqueue(temp);
		i++;
	}

}

void IsisCourse::update_enrollments() 
{
	// put students from the waitlists into the class
	// in priority (majors first, then others), up to
	// the class capacity.

	// TODO: Student writes code here
	
	// Updates the enrollment for the class up to the capacity.
	// This is always executed when the capacity is increased,
	// but can also be executed to fill up the class to its
	// current capacity.
	
	while (roster.size() < class_capacity && !major_waitlist.is_empty()){
		roster.add(major_waitlist.dequeue());
	}
	
	while (roster.size() < class_capacity && !other_waitlist.is_empty()){
		roster.add(other_waitlist.dequeue());
	}

}
