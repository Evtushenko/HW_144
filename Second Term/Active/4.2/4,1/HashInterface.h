#include "hashFunctionFirst.h"
#include "hashFunctionSecond.h"
#include "hashFunction.h"
#include <iostream>
#include <stdio.h>


/**
@brief max length of words which can be keeped
*/
int const maxLengthWord = 30;


class TestHashInterface;

/**
@brief general class for user using
*/
class HashInterface {
    friend class TestHashInterface;
public:
    HashInterface ();
    ~HashInterface ();
    /**
    @brief add to hash table word from keyboard
    @detailed reading inside
    */
    void addHT(char *text);
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

private:
    /**
    @brief for keeping words
    */
    struct Words{
        char word[maxLengthWord];
        Words *next;
    };
    /**
    @brief for calling calc hash functions
    */
    HashFunction *hashFunctionPointer;
    /**
    @brief keep result of searching
    */
    Words *slotWords;
    /**
    @brief support for searchHT
    @detailed moving along list of one cell of arrayWords and search this word from keyboard
    */
    bool itWasHere(Words *slot, char *text);
    /**
    @brief range of lists of words
    */
    Words *arrayWords[amountElements];
    /**
    @brief swithes different hash functions
    */
    int calcHash(char *text);
};
