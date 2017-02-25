#include "stdafx.h"
#include "toUpperConverter.h"

void toUpperConverter::convert(string &completeSentence)
{
	transform(completeSentence.begin(), completeSentence.end(), completeSentence.begin(), ::toupper);
}