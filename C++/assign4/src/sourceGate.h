#pragma once

#include "gate.h"

class sourceGate : public gate
{
public:
	bool addOutput(bus*);
	bool setOutput(vector<bus*>);
	vector<bus*> getOutputs();
	bool removeOutputs(bus *);

	bool compute();
	bool isValid();
private:
	vector<bus*> userInputs;
};

