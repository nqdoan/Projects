#pragma once

#include "gate.h"
#include <vector>

using namespace std;

extern class gate;

class bus
{
public:
	bus();
	void setValue(int givenValue);
	int getValue();

	bool setInput(gate*);
	bool removeInput(gate*);

	bool addOutput(gate*);
	bool removeOutput(gate *);

	vector<gate*> getOutput();
	gate* getInput();

	bool isValid();
private:
	int value;
	gate* input;
	vector<gate*> output;
};