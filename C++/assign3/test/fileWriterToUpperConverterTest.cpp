#include "stdafx.h"
#include "CppUnitTest.h"
#include "fileWriter.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Assignment3
{
	TEST_CLASS(fileWriterToUpperConverterTest)
	{
	public:
		TEST_METHOD(fileWriterWriteTestWithToUpperConverter)
		{
			ofstream file("fileWriterOutput.txt", ios_base::out | ios_base::trunc); //This ensures files are empty so that tests do not bleed into each other
			file.close();

			string expectedString = "THE TO UPPER TEST";
			string actualString = "the to upper test";
			fileWriter call;
			call.addConverter(&toUpperConverter::convert);
			call.write(actualString);
			Assert::AreEqual(expectedString, call.toString());
		}
	};
}