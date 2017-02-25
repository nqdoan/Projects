#include "stdafx.h"
#include "fileWriter.h"

fileWriter::fileWriter(string userFilePath)
{
	filePath = userFilePath;
}

void fileWriter::write(string givenContent)
{
	string content = toString();
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
	ofstream writeFile(filePath, ios_base::out | ios_base::trunc);
	writeFile << content;
	writeFile.close();
}

void fileWriter::close()
{
	isClose = true;
}

string fileWriter::toString()
{
	string content;
	ifstream writeFile(filePath);
	if (writeFile.is_open())
	{
		getline(writeFile, content, (char)EOF);
		writeFile.close();
	}
	return content;
}

void fileWriter::addConverter(void(*converter)(string&))
{
	allConverters.push_back(converter);
}

void fileWriter::addRemover(void(*remover)(string&))
{
	allRemovers.push_back(remover);
}

vector<void(*)(string&)> fileWriter::getConverter()
{
	return allConverters;
}

vector<void(*)(string&)> fileWriter::getRemover()
{
	return allRemovers;
}