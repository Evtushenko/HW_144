#pragma once
#include "hashfunction.h"
/**
@brief second hash fucntion = personal class
*/
class HashFunctionSecond :
	public HashFunction
{
public:
	/**
	@brief example function : returns length*2;
	@param text from Hash Interface Class
	*/
	int calcHash(char* text);
	HashFunctionSecond(void);
	~HashFunctionSecond(void);
};

