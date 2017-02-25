#include "stdafx.h"
#include "stringWriter.h"

void stringWriter::write(string givenContent)
{
	if (isClose == false)
	{
		if (!allConverters.empty())
		{
			for (unsigned int converter = 0; converter < allConverters.size(); converter++)
				allConverters[converter](givenContent);
		}

		if (!allRemovers.empty())
		{
			for (unsigned int remover = 0; remover < allRemovers.size(); remover++)
				allRemovers[remover](givenContent);
		}
		content += givenContent;
	}
}

void stringWriter::close()
{
	isClose = true;
}

string stringWriter::toString()
{
	return content;
}


void stringWriter::addConverter(void(*converter)(string&))
{
	allConverters.push_back(converter);
}

void stringWriter::addRemover(void(*remover)(string&))
{
	allRemovers.push_back(remover);
}

vector<void(*)(string&)> stringWriter::getConverter()
{
	return allConverters;
}

vector<void(*)(string&)> stringWriter::getRemover()
{
	return allRemovers;
}