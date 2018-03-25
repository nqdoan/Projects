#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "toLowerConverter.h"
#include "toUpperConverter.h"
#include "duplicateRemover.h"
#include "stupidRemover.h"

using namespace std;

class stringWriter
{
public:
	void write(string content);
	void close();
	string toString();
	void addConverter(void (*converter)(string&));
	void addRemover(void (*remover)(string&));
	vector<void(*)(string&)> getConverter();
	vector<void(*)(string&)> getRemover();
private:
	string content;
	bool isClose = false;
	vector<void (*)(string&)> allConverters;
	vector<void(*)(string&)> allRemovers;
};

