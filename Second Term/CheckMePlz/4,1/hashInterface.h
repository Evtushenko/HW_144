#include "hashfunctionFirst.h"
#include "hashfunctionSecond.h"
#include <iostream>

/**
@brief amount elements witch can be keep in the range of HashTable
*/
int const amountElements = 1000;
/**
@brief max length of words which can be keeped
*/
int const maxLengthWord = 30;


/**
@brief general class for user using
*/
class HashInterface {
public:
	HashInterface ();
    ~HashInterface ();
	/**
	@brief swithes different hash functions
	*/
	int calcHash(char *text);
	/**
	@brief add to hash table word from keyboard
	@detailed reading inside
	*/
	void addHT();
	/**
	@brief search this word in HashTable
	@param text from keyboar during general cycle in main.cpp
	@return index of range cell of hash Table ( index of ArrayWords)
	@throw -1 cause not found
	*/
	int searchHT(char *buffer);
	/**
	@brief delete this word from HashTable
	@detailed unsing searchHT and consider result
	@param text from keyboar during general cycle in main.cpp
	@throw error signal from searchHT
	*/
	void deleteHT(char *buffer);
	/**
	@brief print static of hash Table
	@detailed amount elements, clashes, loadfactor, ...
	*/
	void staticHT();
	/**
	@brief current number of hash fucntion
	*/
	int numberHF;
	//void test();
private:
	/**
	@brief for keeping words
	*/
	struct Words{
		char word[maxLengthWord];
		Words *next;
	};
	/**
	@brief range of lists of words
	*/
Words *arrayWords[amountElements];
	/**
	@brief support for searchHT
	@detailed moving along list of one cell of arrayWords and search this word from keyboard
	*/
bool itWasHere(Words *slot, char *text);

private:
	/**
	@brief variable of First Hash Funtion class
	*/
	HashFunctionFirst firstHF;
	/**
	@brief variable of Second Hash Funtion class
	*/
	HashFunctionSecond secondHF;
	/**
	@brief keep result of searching
	*/
	Words *slotWords;
};