#pragma once

#include <iostream>
#include <cstdlib>
#include <string.h>

namespace expression {

	const int maxBufferSize = 100;

	bool isSign(char a);
	bool isDigit(char a);
	bool isEnd(char a);
	bool isExp(char a);
	bool isDot(char a);
	bool checkFloat(char string [], int &position);
	bool isCorrect(int &position, char string []);
	bool ruleT(int &position, char string []);
	bool ruleTouchE(int &position, char string []);
	bool ruleF(int &position, char string []);
	bool ruleTouchT(int &position, char string []);
	bool ruleE(int &position, char string []);
}