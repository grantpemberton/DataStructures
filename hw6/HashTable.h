//Written by Grant Pemberton 12/5/2014
//Hashtable.h

#ifndef HASHTABLE_H_

#define HASHTABLE_H_
#include "Song.h"
#include <vector>
#include <string>
//#include <iostream> DOOOOOO WE NEED THIS>>>>>??????
#include <fstream>

//#include "WordList.h"

#define MAX_LOADFACTOR 0.7
#define HASH_INIT_CAPACITY 5

using namespace std;

struct SongInfo {
	
	SongInfo(){
		wordCount = 0;
		songIndex = -9;//later used to print out the 5b4 and 5after
	}
	
	int songIndex;//index of song in LSV
	
	
	int wordCount;//going to go into vector that is going into hashtable
	//how many times does a word appear in a song
};


struct HashedItems{
	
	HashedItems(){//constructor
		songs = NULL;
	}
	
	~HashedItems(){//destructor
		delete songs;//do we need this? there is no new?????????????????????????
	}
	
	string alpha_only_word;//what were hashing on
	
	SongInfo *songs; //this is a pointer to an array of the top ten songs for each word
};

class HashTable{
	public:
		HashTable();//set all data equal to "" for every element in the array make every alpha_only_word equal to ""
		~HashTable();//walk through the whole array and delete that pointer if it's not equal to ""
		
		void insert(string word, SongInfo info);
		//hash the word
		//look at our table to see if it's the empty string. if it is "", then we can put the word there
		//if it's not the empty string, then linear probe
		//run find before trying to insert. this will prevent the same word from being inserted twice
		
		
		SongInfo *find(string word);
		
		float load_factor() {return (float)table_count/table_capacity;}
		
		void sort (SongInfo *songs);
	private:
		HashedItems *table;//points to the hash table
		void expand();//expands the array by rehashing indicies
		int table_capacity;//how large our table is
		int table_count;//how many items are in our table
		
};



#endif /* HASHTABLE_H_ */

