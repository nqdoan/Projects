#include "stdafx.h"


gate::gate()
{
	if (output != NULL)
		output = NULL;
}

bool gate::addInput(bus * inputBus)
{
	inputs.push_back(inputBus);
	return true;
}

bool gate::setInput(vector<bus*> newInput)
{
	inputs = newInput;
	return true;
}

bool gate::removeInput(bus* oldBus)
{
	bool found = false;
	vector<bus*> newInputs;

	for(int index = 0; index < inputs.size(); index++)
	{
		if(inputs[index] == oldBus)
		{
			found = true;
			continue;
		}
		newInputs.push_back(inputs[index]);
	}

	inputs = newInputs;
	return found;
}

bool gate::setOutput(bus * outputBus)
{
	output = outputBus;
	return true;
}

bool gate::removeOutput(bus* oldBus)
{
	if (oldBus != output)
		return false;
	output = NULL;
	return true;
}

vector<bus*> gate::getInput() const
{
	return inputs;
}

bus * gate::getOutput() const
{
	return output;
}

bool gate::isValid()
{
	if(output != NULL && inputs.size() == 2)
		return true;
	return false;
}
