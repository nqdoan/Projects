#pragma once
#include <algorithm>
#include <string>
#include "converter.h"

using namespace std;

class toUpperConverter: public converter
{
public:
	static void convert(string &completeSentence);
};

