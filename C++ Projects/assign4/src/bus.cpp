#include "stdafx.h"

bus::bus()
{
	if (input != NULL)
		input = NULL;
	value = -1;
}

void bus::setValue(int givenValue)
{
	value = givenValue;
}

int bus::getValue ()
{
	return value;
}

bool bus::setInput(gate* inputGate)
{
	input = inputGate;
	return true;
}

bool bus::addOutput(gate* outputGate)
{
	output.push_back(outputGate);
	return true;
}

bool bus::removeInput(gate* oldGate)
{
	if (oldGate != input)
		return false;
	input = NULL;
	return true;
}

bool bus::removeOutput(gate* oldGate)
{
	bool found = false;
	vector<gate*> newOutput;

	for(int index = 0; index < output.size(); index++)
	{
		if(output[index] == oldGate)
		{
			found = true;
			continue;
		}
		newOutput.push_back(output[index]);
	}

	output = newOutput;
	return found;
}

vector<gate*> bus::getOutput()
{
	return output;
}

gate* bus::getInput()
{
	return input;
}


bool bus::isValid()
{
	if(input != NULL && output.size() >= 1)
		return true;
	return false;
}


