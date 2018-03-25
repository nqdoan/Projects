#include "stdafx.h"
#include "sinkGate.h"


bool sinkGate::compute()
{
	return true;
}

bool sinkGate::isValid()
{
	if(inputs.size() > 0)
		return true;
	return false;
}
