// Written by Grant Pemberton 12/5/2014
// Hashtable.cpp



#include <iostream>
#include "Song.h"
#include <string>
#include <vector>
#include "hashfunc.h"
#include "HashTable.h"

using namespace std;

//constructor vv
//set all data equal to "" for every element in the array make every 
//alpha_only_word equal to ""
HashTable::HashTable()
{
	//create table using new with initial capacity
	table = new HashedItems[HASH_INIT_CAPACITY];
	//set initial capacity and initial count
	table_capacity = HASH_INIT_CAPACITY;
	table_count = 0;
	
	//walk through entire array and set alpha_only_word to ""
	for (int i = 0; i < table_capacity; i++){
		table[i].alpha_only_word = "";
	}
}

//destructor
//walk through the whole array and delete that pointer if it's not equal to ""
HashTable::~HashTable()
{
	
	for (int i = 0; i < table_capacity; i++){//do we need this???
		if (table[i].alpha_only_word != ""){
			table[i].alpha_only_word = "";
			delete [] table[i].songs;
		}
	}
	delete [] table;
}

//insert function
void HashTable::insert(string word, SongInfo wordInfo)
{
	//check the loadfactor because we might have to expand
		
	if (load_factor() >= MAX_LOADFACTOR){
		expand();
	}
	
	//hash the actual thing
	unsigned int hash_value = hash_string(word);
	//mod this to the table size to get our index
	
	int table_position;
	bool done_inserting = false;
	
	
	int attempt = 0;
	while (!done_inserting){
		//check to see if we're in the right spot
		
		//if there is something in the spot, then we need to linear 
		//probe
		
		//determine table_position
			//hint: use hashvalue and attempt and dont forget to 
			//mod with table-capacity
		
		//linear probing
		table_position = (hash_value+attempt) % table_capacity;
		
		if (table[table_position].alpha_only_word != ""){
			//bucket is taken
			//increase attempt
			attempt ++;
		}else{
			//the bucket is free
			
			//we can put the word into alpha_only_word and the 
			//songs into songs in our struct at that position
			
			table[table_position].alpha_only_word = word;
			//give an identity to the bucket
			
			SongInfo *temp = new SongInfo[11];
			//pointer to a song frequency array
			
			
			table[table_position].songs = temp;
			//bucket now points at that frequency array
			
			temp = NULL;
			//repoint temp for memory management
			
			delete [] temp;
			//recycle the pointer
			
			table[table_position].songs[0].wordCount = 1;
			
			table[table_position].songs[0].songIndex = 
			wordInfo.songIndex;
			
			//since it is a new word, we give it a count of 1
			//the songIndex that it should reference is the same as
			//the songIndex of the SongInfo passed in
			
			done_inserting = true;
		}
	}
}

SongInfo *HashTable::find(string word)
{
	//hash the string to an integer
	//search fo the entry in the hashtable, using a linear probe
	
	unsigned int hash_value = hash_string(word);
	//mod this to the table size to get our index
	
	int table_position;
	
	int attempt = 0;
	
	bool done_searching = false;
	bool found_word = false;
	
	
	while (!done_searching){
		//determine table position
		table_position = (hash_value+attempt) % table_capacity;
		//check table posistions alpha_only_word
		if (table[table_position].alpha_only_word == ""){
		//the word isn't in the table
			done_searching = true;
		//if it is "" then we're done searching because the word isnt 
		//in the table
		
		
		}else if (table[table_position].alpha_only_word != word){
		//the word in the hashed spot isn't our word
			attempt ++;//continue the linear probe
		}else{//we have found the word
			done_searching = true;
			found_word = true;
		}
	}
	
	//if we found the word, return the songs pointer at that posisiton, 
	//otherwise return NULL
	
	if (found_word){
		return table[table_position].songs;
	}else{
		return NULL;
	}
}



void HashTable::expand(){
	//1. create a new table with twice the capacity
	HashedItems* newTable = new HashedItems[table_capacity*2];
	
	//2. initialize the new table with aows set to ""
	for (int i = 0; i < table_capacity*2; i++){
		newTable[i].alpha_only_word = "";
	}
	
	//3. swap the new table pointer and the old table pointers, using a
	//temp pointer
	HashedItems* temp;
	
	temp = newTable;
	newTable = table;
	table = temp;
	
	
	//4. change the table capacity to twice the capacity
	table_capacity = table_capacity*2;
	
	//5. make the table count = 0;
	table_count = 0;
	
	//6. re-hash all of the old keys (aow) which we get by walking the old 
	//table (new table name)
	
	//note: you determine whether you have to rehash if the 
	//alpha_only_word is != ""
	for (int i = 0; i < table_capacity/2; i++){
		if(newTable[i].alpha_only_word != ""){
			//if there is a word in the bucket
			
			int num_songs = 0;
			while (temp[i].songs[num_songs].songIndex != -9){
				num_songs ++;
				if (num_songs == 10){
					break;
				}
			}
				//basically a copy of insert, for some reason
				//the insert function that is commented out
				//below was not functioning correctly
				
				unsigned int hash_value = hash_string(newTable[i].alpha_only_word);
				int table_position;
				int attempt = 0;
				
				table_position = (hash_value + attempt) % table_capacity;
				
				if (table[table_position].alpha_only_word != "" && table[table_position].alpha_only_word != newTable[i].alpha_only_word){
					attempt++;
				}else{
					table[table_position].alpha_only_word = newTable[i].alpha_only_word;
					
					SongInfo *temp = new SongInfo [11];
					table[table_position].songs = temp;
					for (int j = 0; j < num_songs; j++){
						table[table_position].songs[j].wordCount = newTable[i].songs[j].wordCount;
						table[table_position].songs[j].songIndex = newTable[i].songs[j].songIndex;
						table_count++;
						temp = NULL;
						delete temp;
					}
				}
		}
	}
	//		insert(newTable[i].alpha_only_word, newTable[i].songs);
	//	}
	//}
	
	
	//7. delete[] the old table
	delete [] newTable;
	
}

//Insertion sort on array of top ten songs
void HashTable::sort(SongInfo *songs)
{
//Standard insertion sort comparing the wordcounts of each index
//note: this was taken from hw 5 in terms of algorithm

	int num_songs = 0;
	//there will not always be 10 songs in the top ten
	
	while (songs[num_songs].songIndex != -9){
		num_songs++;
		if (num_songs == 11){
			break;
		}
	}
	//we now know how many songs are in the array
	
	for (int i = 1; i < num_songs; i++){
		for (int j = i; j > 0; j--){
			if (songs[j].wordCount > songs[j-1].wordCount){
				//swap the items
				SongInfo temp;
				temp.wordCount = songs[j].wordCount;
				temp.songIndex = songs[j].songIndex;
				
				songs[j].wordCount = songs[j-1].wordCount;
				songs[j].songIndex = songs[j-1].songIndex;
				
				songs[j-1].wordCount = temp.wordCount;
				songs[j-1].songIndex = temp.songIndex;
			}else{
				break;
			}
		}
	}
}




