#include "stdafx.h"
#include "duplicateRemover.h"

void duplicateRemover::remove(string &content)
{
	
	stringstream sscontent(content);
	string currentWord = "", nextWord = "", whitespace = "" , newContent = "";

	while (!sscontent.eof())
	{
		sscontent >> nextWord;
		while (sscontent.peek() == ' ' || sscontent.peek() == '\t' || sscontent.peek() == '\n')
		{
			whitespace += (char)sscontent.get();
		}
		if (nextWord != currentWord)
		{
			newContent = newContent + nextWord + whitespace;
			currentWord = nextWord;
		}
		whitespace = "";
	}
	content = newContent;
}
