#include "stdafx.h"
#include "CppUnitTest.h"
#include "fileWriter.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Assignment3
{
	TEST_CLASS(fileWriterToLowerConverterTest)
	{
	public:
		TEST_METHOD(fileWriterWriteTestWithToLowerConverter)
		{
			ofstream file("fileWriterOutput.txt", ios_base::out | ios_base::trunc); //This ensures files are empty so that tests do not bleed into each other
			file.close();

			string expectedString = "the to lower test";
			string actualString = "THE TO LOWER TEST";
			fileWriter call;
			call.addConverter(&toLowerConverter::convert);
			call.write(actualString);
			Assert::AreEqual(expectedString, call.toString());
		}


	};
}