#pragma once

#include <vector>

#include "gate.h"
#include "bus.h"
#include "sinkGate.h"
#include "sourceGate.h"

#define SOURCEINDEX -1
#define SINKINDEX -2

class circuit
{
public:
	int addBus(bus* newBus);
	bool removeBus(int busNumber);
	vector<bus*> getBusses();

	int addGate(gate* newGate);
	bool removeGate(int gateNumber);
	vector<gate*> getGates();

	bool connectBusIGateO(int gateIndex, int busIndex);
	bool connectGateIBusO(int gateIndex, int busIndex);
	bool disconnectBusIGateO(int gateIndex, int busIndex);
	bool disconnectGateIBusO(int gateIndex, int busIndex);

	int getNumberOfUserInputs();
	void simulate(vector<bool> userInputs);

	bool isValid();
private:
	vector<bus *> busses;
	vector<gate *> gates;

	sourceGate source;
	sinkGate sink;
};

