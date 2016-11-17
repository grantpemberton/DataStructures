//Written by Grant Pemberton 12/8/2014
//Song.h
//


#ifndef SONG_H_
#define SONG_H_

#include <string>
#include <iostream>
#include <vector>


#define SONG_INIT_CAPACITY 5

using namespace std;

class Song{
	public:
		Song();//constructor
		
		~Song();//destructor
		
		int find_lyric(string word);
		
		//string get_artist() {return artist;}
		
		//string get_title() {return title;}
		
		//vector <string> get_lyrics() {return lyrics;}//is this ok???
		
		//int get_lyric_count() {return lyric_count;}
		
		vector <string> lyrics;
		string artist;
		string title;
		int lyric_count;
		
	private:
		
		

		
};



#endif /* SONG_H_ */
























