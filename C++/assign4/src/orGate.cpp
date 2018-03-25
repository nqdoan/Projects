#include "stdafx.h"
#include "orGate.h"


bool orGate::compute()
{
	if (inputs[0]->getValue() == -1 || inputs[1]->getValue() == -1)
		return false;
	return (inputs[0]->getValue() || inputs[1]->getValue());
}
