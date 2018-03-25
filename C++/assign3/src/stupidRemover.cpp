#include "stdafx.h"
#include "stupidRemover.h"


void stupidRemover::remove(string &content)
{
	stringstream sscontent(content);
	string nextWord = "", whitespace = "", newContent = "";

	while(!sscontent.eof())
	{
		sscontent >> nextWord;
		while (sscontent.peek() == ' ' || sscontent.peek() == '\t' || sscontent.peek() == '\n')
        {
            whitespace += (char)sscontent.get();
        }
		if (nextWord != "stupid") 
        {
            newContent = newContent + nextWord + whitespace;
        }
		else
		{
			newContent = newContent + nextWord[0] + "*****" + whitespace;
		}
        whitespace = "";
	}
	content = newContent;
}