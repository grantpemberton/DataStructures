//Written by Grant Pemberton 12/5/2014
//WordList.cpp

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include "hashfunc.h"
#include "HashTable.h"
#include "Song.h"
#include "WordList.h"

using namespace std;


//constructor
WordList::WordList()
{
	LSV_capacity = WORD_INIT_CAPACITY;
	LSV_count = 0;
}

WordList::~WordList(){
	
}

//read_lyrics
void WordList::read_lyrics(const char * filename, bool show_progress)
{
	ifstream in(filename);			// creates an input stream
	int song_count = 0;			// for progress indicator
	string artist;
	string title;
	string word;
	
	// -- While more data to read...
	while ( ! in.eof() ) 
	{
		
		// -- First line is the artist
		getline(in, artist);
		if (in.fail()) break;
		
		
		// -- Second line is the title
		getline(in, title);
		if (in.fail()) break;
		
		
		if ( show_progress )
		{
			song_count++;
			if (song_count % 10000 == 0) {
				cout << "At "       << song_count << 
				" Artist: " << artist     << 
				" Title:"   << title << endl;
			}
		}
		
		
		insertSong(word, artist, title);
		
		//put song into LSV
		int LSVindex = song_count-1;
		//song_count is decremented because of array counting in LSV
		
		// -- Then read all words until we hit the 
		// -- special <BREAK> token
		
		
		while ( in >> word && word != "<BREAK>" ){
			
			insert_lyric(word, LSVindex);
			//place word into the lyric vector of the song that 
			//we're working in in the LSV
			
			word = alpha_only(word);
			//make the punctuated word into something that the 
			//hash table can handle
			
			update(word, LSVindex);
			//update the hash table to reflect the inserted word
			
		}
		// -- Important: skip the newline left behind
		in.ignore();
	}
}

void WordList::update(string word, int LSVindex)
{
	
	if (word == ""){
		
		return;
	}
	
	if (searcher.find(word) == NULL){
		SongInfo theSong;
		
		theSong.wordCount = 1;
		//this is the first time we are seeing it
		
		theSong.songIndex = LSVindex;
		//where in the LSV the lyric's song is
		searcher.insert(word, theSong);
		
		return;
	}else{//word has been inserted before
		for (int i = 0; i < 10; i++){
		//check through the array
			if(LSVindex == searcher.find(word)[i].songIndex){
			//if the LSVindex matches the index of any of the songs
			//in the top ten, then increment that wordCount
				searcher.find(word)[i].wordCount++;
				searcher.sort(searcher.find(word));
				return;//the wordCount of some song has been ++
			}
		}
		
		
		if(searcher.find(word)[10].songIndex == LSVindex){
		//it's possible that the 11th song in the top ten array is tied
		//with a song that is higher on the list, so we should check it
		//against the other songs in the index (what sort does)
			searcher.find(word)[10].wordCount++;
			searcher.sort(searcher.find(word));
			return;//the wordCount of the 11th song has been ++'d
		}
	}
	return;
}

//put this song into the LSV and populate that song's lyric vector
void WordList::insertSong (string word, string artist, string title)
{
	Song* newSong = new Song;
	//create a pointer to a new Song class
	
	newSong->artist = artist;
	newSong->title = title;
	newSong->lyric_count++;
	//set member variables for that Song class
	
	newSong->lyrics.push_back(word);
	//put the lyric of the song into its lyrics vector
	
	LSV.push_back(*newSong);//thinks that its a song pointer...
	//put the actual song into LSV
	
	delete newSong;
	//memory management
}

void WordList::insert_lyric(string word, int index)//where is this used
{
	LSV[index].lyrics.push_back(word);
}
	
//printing helper function
void WordList::print(int i, int j, string word)
{
	
	cout << "Title: " << LSV[searcher.find(word)[i].songIndex].title << endl;
	
	cout << "Artist: " << LSV[searcher.find(word)[i].songIndex].artist << endl;
	
	int begin = j-5;
	if (begin < 0){
		begin = 0;
	}
	
	int end = j+5;
	if (end > LSV[searcher.find(word)[i].songIndex].lyrics.size()-1){
		end = LSV[searcher.find(word)[i].songIndex].lyrics.size()-1;
	}
	
	cout << "Context: ";
	
	for (int g = begin; g <=end; g++){
		cout << LSV[searcher.find(word)[i].songIndex].lyrics[g] << " ";
	}
	
	cout << endl;
}

//search function: this is the meat of the program
void WordList::search()
{
	
	string word = "";
	
	while (word != "<BREAK>"){
	//we have not read in the stop token
		cin >> word;
		//read in the word
		string hashinput = alpha_only(word);
		//make that word into something that can be hashed
		
		if(searcher.find(hashinput) == NULL){
		//if that word isn't in the hashtable, then it's not in a song
			cout << "<END OF REPORT>" << endl;
			
		}
		
		else{
			int num_songs = 0;
			//counter for how many songs are in frequency array
			
			while (searcher.find(hashinput)[num_songs].songIndex != -9){
			//find out how many songs are actually in frequency arr
				num_songs++;
				if(num_songs == 11){
					//max songs is 11
					break;
				}
			}
			for (int i = 0; i < num_songs; i++){
			//for each song in the frequency array
				int x = LSV[searcher.find(hashinput)[i].songIndex].lyrics.size();
				//size of the lyrics vector for song "i"
				for (int j = 0; j < x; j++){
				//for all of the lyrics in song "i"
					if (alpha_only(LSV[searcher.find(hashinput)[i].songIndex].lyrics[j])== hashinput){
					//if the lyric matches the input word
					//we found an instance of the word!!
					//print out its credentials
					
					print (i, j, hashinput);
					}
				}
			}
			cout << "<END OF REPORT>" << endl;
		}
	}
}
	


string WordList::alpha_only(string s)
{
	ostringstream ss;
	for (size_t i=0;i<s.length();i++) {
		if (isalnum(s[i])){
			ss << (char)(tolower(s[i]));
		}
	}
	return ss.str();
}















