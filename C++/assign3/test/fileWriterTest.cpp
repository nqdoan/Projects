#include "stdafx.h"
#include "CppUnitTest.h"
#include "fileWriter.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Assignment3
{
	TEST_CLASS(fileWriterTest)
	{
	public:
		TEST_METHOD(fileWriterTestForWrite)
		{
			ofstream file("fileWriterOutput.txt", ios_base::out | ios_base::trunc); //This ensures files are empty so that tests do not bleed into each other
			file.close();

			string expectedString = "These should be the same";
			string actualString = "These should be the same";
			fileWriter call;
			call.write(actualString);
			actualString = call.toString();
			Assert::AreEqual(expectedString, actualString);
		}

		TEST_METHOD(fileWriterCloseTest)
		{
			ofstream file("fileWriterOutput.txt", ios_base::out | ios_base::trunc); //This ensures files are empty so that tests do not bleed into each other
			file.close();

			string expectedString = "These should";
			string actualStringFirstSection = "These should";
			string actualStringSecondSection = " be the same";
			fileWriter call;
			call.write(actualStringFirstSection);
			call.close();
			call.write(actualStringSecondSection);
			Assert::AreEqual(expectedString, call.toString());
		}

		TEST_METHOD(fileWriterToStringTest)
		{
			ofstream file("fileWriterOutput.txt", ios_base::out | ios_base::trunc); //This ensures files are empty so that tests do not bleed into each other
			file.close();

			string expectedString = "the to string test";
			string actualString = "the to string test";
			fileWriter call;
			call.write(actualString);
			Assert::AreEqual(expectedString, call.toString());
		}
	};
}