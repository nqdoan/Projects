#pragma once
#include <sstream>
#include <string>
#include "remover.h"

using namespace std;

class duplicateRemover: public remover
{
public:
	static void remove(string &content);
};

