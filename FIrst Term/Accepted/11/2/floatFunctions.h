#pragma once

#include <iostream>
#include <cstdlib>

namespace fuctionsFloat {

	int const maxBufferSize = 20;

	bool isSign(char a);
	bool isDigit(char a);
	bool isEnd(char a);
	bool isExp(char a);
	bool isDot(char a);
	bool checkFloat(char str []);
}