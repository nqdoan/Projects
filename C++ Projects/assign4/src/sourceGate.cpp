#include "stdafx.h"
#include "sourceGate.h"


bool sourceGate::addOutput(bus* newBus)
{
	userInputs.push_back(newBus);
	return true;
}

bool sourceGate::setOutput(vector<bus*> newOutput)
{
	userInputs = newOutput;
	return true;
}


vector<bus*> sourceGate::getOutputs()
{
	return userInputs;
}

bool sourceGate::removeOutputs(bus * oldBus)
{
	bool found = false;
	vector<bus*> newInputs;

	for(unsigned int index = 0; index < userInputs.size(); index++)
	{
		if(userInputs[index] == oldBus)
		{
			found = true;
			continue;
		}
		newInputs.push_back(userInputs[index]);
	}

	userInputs = newInputs;
	return found;
}

bool sourceGate::compute()
{
	return true;
}

bool sourceGate::isValid()
{
	if(userInputs.size() > 0)
		return true;
	return false;
}