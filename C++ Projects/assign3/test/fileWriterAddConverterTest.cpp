#include "stdafx.h"
#include "CppUnitTest.h"
#include "fileWriter.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Assignment3
{
	TEST_CLASS(fileWriterAddConverterTest)
	{
	public:
		TEST_METHOD(fileWriterAddOneConverterTofileWriter)
		{
			ofstream file("fileWriterOutput.txt", ios_base::out | ios_base::trunc); //This ensures files are empty so that tests do not bleed into each other
			file.close();

			vector<void(*)(string&)> expectedConverters;
			expectedConverters.push_back(&toLowerConverter::convert);

			fileWriter testWriter;
			testWriter.addConverter(&toLowerConverter::convert);
			Assert::AreEqual(true, expectedConverters == testWriter.getConverter());
		}

		TEST_METHOD(fileWriterAddTwoConverterTofileWriter)
		{
			ofstream file("fileWriterOutput.txt", ios_base::out | ios_base::trunc); //This ensures files are empty so that tests do not bleed into each other
			file.close();

			vector<void(*)(string&)> expectedConverters;
			expectedConverters.push_back(&toLowerConverter::convert);
			expectedConverters.push_back(&toUpperConverter::convert);

			fileWriter testWriter;
			testWriter.addConverter(&toLowerConverter::convert);
			testWriter.addConverter(&toUpperConverter::convert);
			Assert::AreEqual(true, expectedConverters == testWriter.getConverter());
		}

		TEST_METHOD(fileWriterAddOneRemoverTofileWriter)
		{
			ofstream file("fileWriterOutput.txt", ios_base::out | ios_base::trunc); //This ensures files are empty so that tests do not bleed into each other
			file.close();

			vector<void(*)(string&)> expectedRemovers;
			expectedRemovers.push_back(&stupidRemover::remove);

			fileWriter testWriter;
			testWriter.addRemover(&stupidRemover::remove);
			Assert::AreEqual(true, expectedRemovers == testWriter.getRemover());
		}
	};
}