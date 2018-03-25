#pragma once

#include "gate.h"

class sinkGate : public gate
{
public:
	bool compute();
	bool isValid();
};

