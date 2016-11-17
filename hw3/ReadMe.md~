Written By: Grant Pemberton (10/12/2014)
# ReadMe for COMP 15 HW3
## ISIS Course Roster and Waitlists


[Purpose]
	The purpose of this program is to model an online class registration software using sets and queues

2.  List of files with one/or two-line summary
[List of files]
>IsisCourse.h
	This is the description and declaration file for how an IsisCourse acts. IsisCourses have several functions
	including enrolling students, dropping students, and printing enrollments/waitlists
>IsisCourse.cpp
	This is the implementation of an IsisCourse. Function definitions exist in this file, and these functions
	correspond to the functions outlined in the IsisCourse.h file above
>Queue.h
	This is the description and declaration file for how a Queue is modeled by a Dynamic array. Queues have
	associated functions which follow the First in First out behavior of Queues.
>Queue.cpp
	This is the implementation of a Queue. The Queues used in this assignment were circular (see % notation)
	Both front and back indicies are kept track of in the Queue, and they reference the orientation and the
	members of the queue as other functions loop through the queue. Functions associated with Queues are 
	enqueue(item), dequeue(), and is_empty()
>Set.h
	This is the description and declaration file for how a Set is modeled by a Dynamic array. Sets contain
	unique elements, and the order of the set does not matter.
>Set.cpp
	This is the implementation of a Set. Since sets are not sorted, many of the member functions use search
	algorithms to find the members of the set to remove or replace.
>Student.h
	This is the declaration and definition of the struct, Student. Students are identified by their name, and
	they are allocated a major status (false if they are not a major for the IsisCourse and true if they are a 
	major for the IsisCourse)

[How to Compile]
>Use provided Makefile to compile this program

[Outline of Data Structure]
>IsisCourse
	The IsisCourse is a conglomerate data structure made from one Set (roster) and two Queues (major_waitlist
	and other_waitlist) both the Set and the Queues are implemented through dynamic arrays. The Set is linear
	whereas the Queues are circular.

[Algorithm Used]
	The main algorithm used in this project was the dequeuing of a waitlist into a temporary Queue, and then 
	re-enqueueing the temporary Queue back into the waitlist. Tests were run on the data that was being 
	re-enqueued through the use of a temporary variable which matched the type of the data in the waitlists.
	The entire temporary queue was placed into the old waitlist unless the drop function was used.

[Helpers]
	Rebecca Cutler helped me on this assignment