#include "stdafx.h"
#include "notGate.h"


bool notGate::compute()
{
	if (inputs[0]->getValue() == -1)
		return false;
	return !(inputs[0]->getValue());
}

bool notGate::isValid()
{
	if (output != NULL && inputs.size() == 1)
		return true;
	return false;
}