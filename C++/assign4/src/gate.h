#pragma once
#include "bus.h"
#include <vector>

using namespace std;

class gate 
{
public:
	gate();
	bool addInput(bus*);
	bool setInput(vector<bus*>);
	bool removeInput(bus*);

	bool setOutput(bus*);
	bool removeOutput(bus*);

	vector<bus*> getInput() const;
	bus* getOutput() const;
	virtual bool isValid(); 
	virtual bool compute() = 0;
protected:
	bus* output;
	vector<bus*> inputs;
};