# ReadMe for COMP 15 HW6
## Song Search 
Written by Grant Pemberton
12/9/2014

1.  The purpose of your program
	the purpose of this program is to read in a data file of songs
and organize that file into a database of songs that can be searched through
the lyrics of a given song. The user will input a word, and the program will
output where the lyric appears in each of the songs that it appears in

2.  List of files with one/or two-line summary

//Song.h
	defines the Song class to be used in both the hash table and 
	in the LSV
//Song.cpp
	member functions of a Song class
//WordList.h
	declares the WordList class and sets up the aggregate data structure
	that is used to make the database
//WordList.cpp
	member functions of the WordList class. This collection of functions
	brings all of the previous classes together
//HashTable.h
	defines a hash table (from C.Gregg hash table video)
//HashTable.cpp
	member functions of a hash table. The goal of building the hash table
	was to have a "pure" hash table.
//main.cpp
	Where the program is run, it reads in the file, and then it allows the
	user to search for a lyric

3.  How to compile it
	use included makefile

4.  Outline of data structure (depending on the assignment)
	
a song is comprised of a vector of lyrics, an artist, and a title. This song
is a part of the LSV (large song vector) that gets referenced for things like
the top ten vector and the Context operations. Each word is stored in a hash
table that hashes on that word. Each "bucket" of the hash table contains the
word that was hashed, and an array of Songs in which that word appears most
frequently.

5.  Outline of algorithm
Insertion sort algorithm was used for the sort portion of the top ten vector

	//1) for each index in the array, look at that index and its previous
	//   index
	//2) compare the value of the index to the value of the previous index
	//3) if the value of the previous index is larger than the value of the
	//   index, then swap the two
	//4) repeat this process now starting at that previous index


6.  A list of people who materially helped you on the assignment
	Becky Cutler
	Owen Elliot (designing the database)


//NOTE: for some reason it is getting really hung up on the rick database and
the big database (TIMEOUT 15). I was tinkering a little bit with it and can't 
figure out where I went wrong, but I've been working on it for far too long, 
so I'm gonna sign out of this project, I don't see where I'm messing up :( Thanks

