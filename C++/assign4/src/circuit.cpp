#include "stdafx.h"
#include "circuit.h"


int circuit::addBus(bus* newBus)
{
	busses.push_back(newBus);
	return busses.size()-1;
}

int circuit::addGate(gate* newGate)
{
	gates.push_back(newGate);
	return busses.size()-1;
}

bool circuit::removeBus(int busNumber)
{
	if (busNumber > busses.size())
		return false;

	vector<bus*> newBusses;

	for (int index = 0; index < busses.size(); index++)
	{
		if(index == busNumber)
			continue;
		newBusses.push_back(busses[index]);
	}

	busses = newBusses;

	return true;
}

bool circuit::removeGate(int gateNumber)
{
	if (gateNumber > gates.size() || gateNumber < 0)
		return false;

	vector<gate*> newGates;

	for (int index = 0; index < gates.size(); index++)
	{
		if(index == gateNumber)
			continue;
		newGates.push_back(gates[index]);
	}

	gates = newGates;

	return true;
}

vector<gate*> circuit::getGates()
{
	return gates;
}

vector<bus*> circuit::getBusses()
{
	return busses;
}

bool circuit::connectBusIGateO(int gateIndex, int busIndex)
{
	int gateSize = gates.size();
	if (gateIndex >= gateSize || busIndex >= busses.size() || gateIndex == SINKINDEX)
	{
		return false;
	}

	if (gateIndex == SOURCEINDEX)
	{
		source.addOutput(busses[busIndex]);
	    busses[busIndex]->setInput(&source);
	}
	else
	{
	    gates[gateIndex]->setOutput(busses[busIndex]);
	    busses[busIndex]->setInput(gates[gateIndex]);
	}
	
	return true;
}

bool circuit::connectGateIBusO(int gateIndex, int busIndex)
{
	int gateSize = gates.size();
	if (gateIndex >= gateSize || busIndex >= busses.size() || gateIndex == SOURCEINDEX)
	{
		return false;
	}

	if (gateIndex == SINKINDEX)
	{
		sink.addInput(busses[busIndex]);
	    busses[busIndex]->addOutput(&sink);
	}
	else
	{
	    gates[gateIndex]->addInput(busses[busIndex]);
	    busses[busIndex]->addOutput(gates[gateIndex]);
	}

	return true;
}

bool circuit::disconnectBusIGateO(int gateIndex, int busIndex)
{
	int gateSize = gates.size();
	if (gateIndex >= gateSize || busIndex >= busses.size() || gateIndex == SINKINDEX)
		return false;

	if (gateIndex == SOURCEINDEX)
	{
		source.removeOutputs(busses[busIndex]);
	    busses[busIndex]->removeInput(&source);
	}
	else
	{
	    gates[gateIndex]->removeOutput(busses[busIndex]);
	    busses[busIndex]->removeInput(gates[gateIndex]);
	}

	return true;
}

bool circuit::disconnectGateIBusO(int gateIndex, int busIndex)
{
	int gateSize = gates.size();
	if (gateIndex >= gateSize || busIndex >= busses.size() || gateIndex == SOURCEINDEX)
		return false;

	if (gateIndex == SINKINDEX)
	{
		sink.removeInput(busses[busIndex]);
	    busses[busIndex]->removeOutput(&sink);
	}
	else
	{
	    gates[gateIndex]->removeInput(busses[busIndex]);
	    busses[busIndex]->removeOutput(gates[gateIndex]);
	}
	return true;
}

bool circuit::isValid()
{
	for(int index = 0; index < gates.size(); index++)
	{
		if (!gates[index]->isValid())
			return false;
	}

	for(int index = 0; index < busses.size(); index++)
	{
		if (!busses[index]->isValid())
			return false;
	}

	return true;
}

int circuit::getNumberOfUserInputs()
{
	return source.getOutputs().size();
}

void circuit::simulate(vector<bool> userInputs)
{
	if (userInputs.size() != getNumberOfUserInputs() || !isValid())
		return;

	for(int index = 0; index < busses.size(); index++)
	{
		busses[index]->setValue(-1);
	}
	
	for(int index = 0; index < userInputs.size(); index++)
	{
		source.getOutputs()[index]->setValue(userInputs[index]);
	}

	vector<gate *> currentState = gates;

	bool finished = false;

	for(int currentGate = 0; !finished; currentGate++)
	{
		if(currentGate >= currentState.size())
		{
			finished = true;
			currentGate = 0;
		}

		if (currentState[currentGate]->getInput()[0]->getValue() == -1 || gates[currentGate]->getInput()[1]->getValue() == -1)
		{
			finished = false;
			continue;
		}
		currentState[currentGate]->getOutput()->setValue(currentState[currentGate]->compute());
	}

	return;
}
