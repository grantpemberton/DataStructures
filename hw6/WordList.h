//Written by Grant Pemberton 12/5/2014
//WordList.h

#ifndef WORDLIST_H_
#define WORDLIST_H_

#include "Song.h"
#include <vector>
#include <string>
//#include <iostream>//Necessary
#include <fstream>
//#include "hashfunc.h"
#include "HashTable.h"

#define WORD_INIT_CAPACITY 5

using namespace std;

/* This is implemented in Song.cpp
struct SongforLSV {
	string title;//index of where this word came from in the songVector
	string artist;
	vector <string> *lyrics;
};
*/

class WordList{
	public:
		WordList();
		~WordList();
		void read_lyrics(const char * filename, bool show_progress);
		string alpha_only(string s);
		void print (int i, int j, string word);
		void search();
		void insertSong (string word, string artist, string title);
		void insert_lyric (string word, int index); 
		
		
	private:
		HashTable searcher;
		void update (string word, int LSVindex);
		vector<Song> LSV;
		//LSV = Large Song Vector where all of the songs are being
		//stored
		
		int LSV_capacity;//needed?
		int LSV_count;//needed?
		
		
		
		int wordFreq (string word, Song cantation);
		
};



#endif /* WORDLIST_H_ */

