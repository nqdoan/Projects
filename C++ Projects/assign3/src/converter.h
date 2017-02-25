#pragma once
#include <string>

using namespace std;

class converter {
public:
	virtual void convert(string &completeSentence) = 0;
};