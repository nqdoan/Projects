#include "stdafx.h"
#include "toLowerConverter.h"


void toLowerConverter::convert(string &completeSentence)
{
	transform(completeSentence.begin(), completeSentence.end(), completeSentence.begin(), ::tolower);
}
