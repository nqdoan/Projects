#include "stdafx.h"
#include "CppUnitTest.h"
#include "fileWriter.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Assignment3
{
	TEST_CLASS(fileWriterStupideRemoverTest)
	{
	public:
		TEST_METHOD(fileWriterWriteStupidRemoverTest)
		{
			ofstream file("fileWriterOutput.txt", ios_base::out | ios_base::trunc); //This ensures files are empty so that tests do not bleed into each other
			file.close();

			string expectedString = "What is this word: s*****";
			string actualString = "What is this word: stupid";
			fileWriter call;
			call.addRemover(&stupidRemover::remove);
			call.write(actualString);
			Assert::AreEqual(expectedString, call.toString());
		}


	};
}