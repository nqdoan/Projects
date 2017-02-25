#pragma once
#include <string>
#include "remover.h"

using namespace std;

class stupidRemover: public remover
{
public:
	static void remove(string &content);
};

