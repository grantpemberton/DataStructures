#
# Makefile for SongSearch, Assignment 6
#
CXX = clang++
FLAGS = -Wall -g3

songsearch: WordList.cpp WordList.h HashTable.cpp HashTable.h hashfunc.cpp hashfunc.h main.cpp Song.h Song.cpp
	${CXX} ${FLAGS} -o songsearch WordList.cpp HashTable.cpp hashfunc.cpp main.cpp Song.cpp
	
clean:
	rm -f songsearch

provide_design:
	provide comp15 hw6_design songsearch_design.txt

provide:
	provide comp15 hw6 Makefile ReadMe.md WordList.cpp WordList.h HashTable.cpp HashTable.h hashfunc.cpp hashfunc.h main.cpp Song.h Song.cpp

