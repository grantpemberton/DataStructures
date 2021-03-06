/*
Written By: Grant Pemberton (9/29/2014)
 * IsisCourse.cpp
 *
 */

#include <iostream>
#include "IsisCourse.h"

using namespace std;

IsisCourse::IsisCourse(){
	class_capacity = 0; // no students allowed in yet
}

IsisCourse::IsisCourse(int init_capacity){
//constructor

	class_capacity = init_capacity;
	
}

IsisCourse::~IsisCourse() {
//destructor
	// nothing to do
}

void IsisCourse::set_class_cap(int cap){

	class_capacity = cap;
	if (roster.size() < class_capacity) {
		update_enrollments();
	}
}

IsisCourse::ENROLLMENT_STATUS IsisCourse::enroll_student(Student s){
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
//4 cases: NONE, ENROLLED, MAJOR_WAITLIST, OTHER_WAITLIST

	bool found_student = false;
	Queue temp_queue;
	Student temp;

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

int IsisCourse::waitlist_position(ENROLLMENT_STATUS status, Student s) {
// returns the waitlist position for a student for a
// particular waitlist (MAJOR_WAITLIST or OTHER_WAITLIST)
//look in the waitlist that is indicated by the enrollment status
//need to loop through the queue until we find the identified student

	Queue temp_queue;
	Student temp;
	int i = 1;
	int position = -1;
	if (status == MAJOR_WAITLIST) {
		
		while (!major_waitlist.is_empty()){
			temp_queue.enqueue(major_waitlist.dequeue());
		}
		
		while (!temp_queue.is_empty()){
			temp = temp_queue.dequeue();
			if (temp.name == s.name){
				position = i;
			}else{
				i++;
			}
			major_waitlist.enqueue(temp);
		}
		
	}
	
	else if (status == OTHER_WAITLIST){
		while (!other_waitlist.is_empty()){
			temp_queue.enqueue(other_waitlist.dequeue());
		}
		
		while (!temp_queue.is_empty()){
			temp = temp_queue.dequeue();
			if (temp.name == s.name){
				position = i;
			}else{
				i++;
			}
			other_waitlist.enqueue(temp);
		}
	}
	
	return position; //student is enrolled or they are none

}
IsisCourse::ENROLLMENT_STATUS IsisCourse::status(Student s) {
// returns the status of a student (NONE, ENROLLED,
// MAJOR_WAITLIST, or OTHER_WAITLIST)

	Queue temp_queue;
	Student temp;
	ENROLLMENT_STATUS state = NONE;
	
	if (roster.is_enrolled(s)){
		state = ENROLLED;
	}
	
	if (s.major){//they are a major
		while (!major_waitlist.is_empty()){
			temp_queue.enqueue(major_waitlist.dequeue());
		}
		
		while (!temp_queue.is_empty()){
			temp = temp_queue.dequeue();
			if (temp.name == s.name){
				state = MAJOR_WAITLIST;
			}
			
			major_waitlist.enqueue(temp);
		}
	}else{//they are not a major
		while (!other_waitlist.is_empty()){
			temp_queue.enqueue(other_waitlist.dequeue());
		}
		
		while (!temp_queue.is_empty()){
			temp = temp_queue.dequeue();
			if (temp.name == s.name){
				state = OTHER_WAITLIST;
			}
			other_waitlist.enqueue(temp);
		}
	}
	
	return state;
}

void IsisCourse::print_list(ENROLLMENT_STATUS status) {
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

	Student temp;
	int i = 1; //human counting, not array counting

	while (!waitlist_queue->is_empty()){
		temp_queue.enqueue(waitlist_queue->dequeue());
	}
	
	while (!temp_queue.is_empty()){
		temp = temp_queue.dequeue();
		cout << i << ". " << temp.name << endl;
		waitlist_queue->enqueue(temp);
		i++;
	}

}

void IsisCourse::update_enrollments() {
// Updates the enrollment for the class up to the capacity.
// This is always executed when the capacity is increased,
// but can also be executed to fill up the class to its
// current capacity.
	
	while (get_roster_size() < class_capacity && !major_waitlist.is_empty()){
		roster.add(major_waitlist.dequeue());
	}
	
	while (get_roster_size() < class_capacity && !other_waitlist.is_empty()){
		roster.add(other_waitlist.dequeue());
	}

}
