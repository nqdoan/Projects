#pragma once
#include <string>

using namespace std;

class remover 
{
public:
	virtual void remove(string &completeSentence) = 0;
};