#include "stdafx.h"
#include "CppUnitTest.h"
#include "fileWriter.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Assignment3
{
	TEST_CLASS(fileWriterCombinedConverterTest)
	{
	public:
		TEST_METHOD(fileWriterWriteLowerFirstTest)
		{
			ofstream file("fileWriterOutput.txt", ios_base::out | ios_base::trunc); //This ensures files are empty so that tests do not bleed into each other
			file.close();

			string expectedString = "this part IS BIG";
			string actualStringFirstSection = "THIS PART ";
			string actualStringSecondSection = "is big";
			fileWriter call;
			call.addConverter(&toLowerConverter::convert);
			call.write(actualStringFirstSection);
			call.addConverter(&toUpperConverter::convert);
			call.write(actualStringSecondSection);
			Assert::AreEqual(expectedString, call.toString());
		}

		TEST_METHOD(fileWriterWriteUpperFirstTest)
		{
			ofstream file("fileWriterOutput.txt", ios_base::out | ios_base::trunc); //This ensures files are empty so that tests do not bleed into each other
			file.close();

			string expectedString = "THIS PART is small";
			string actualStringFirstSection = "this part ";
			string actualStringSecondSection = "IS SMALL";
			fileWriter call;
			call.addConverter(&toUpperConverter::convert);
			call.write(actualStringFirstSection);
			call.addConverter(&toLowerConverter::convert);
			call.write(actualStringSecondSection);
			Assert::AreEqual(expectedString, call.toString());
		}

		TEST_METHOD(fileWriterDuplicateFirstTest)
		{
			ofstream file("fileWriterOutput.txt", ios_base::out | ios_base::trunc); //This ensures files are empty so that tests do not bleed into each other
			file.close();

			string expectedString = "the word s***** should be hidden";
			string actualStringFirstSection = "the word word ";
			string actualStringSecondSection = "stupid should be hidden";
			fileWriter call;
			call.addRemover(&duplicateRemover::remove);
			call.write(actualStringFirstSection);
			call.addRemover(&stupidRemover::remove);
			call.write(actualStringSecondSection);
			Assert::AreEqual(expectedString, call.toString());
		}
		TEST_METHOD(fileWriterStupidFirstTest)
		{
			ofstream file("fileWriterOutput.txt", ios_base::out | ios_base::trunc); //This ensures files are empty so that tests do not bleed into each other
			file.close();

			string expectedString = "the word s***** should be hidden";
			string actualStringFirstSection = "the word stupid ";
			string actualStringSecondSection = "should be hidden";
			fileWriter call;
			call.addRemover(&stupidRemover::remove);
			call.write(actualStringFirstSection);
			call.addRemover(&duplicateRemover::remove);
			call.write(actualStringSecondSection);
			Assert::AreEqual(expectedString, call.toString());
		}

		TEST_METHOD(fileWriterTestForAll)
		{
			ofstream file("fileWriterOutput.txt", ios_base::out | ios_base::trunc); //This ensures files are empty so that tests do not bleed into each other
			file.close();

			string expectedString = "the word s***** SHOULD BE HIDDEN";
			string actualStringFirstSection = "the word stupid ";
			string actualStringSecondSection = "should be be hidden";
			fileWriter call;
			call.addConverter(&toLowerConverter::convert);
			call.addRemover(&stupidRemover::remove);
			call.write(actualStringFirstSection);
			call.addRemover(&duplicateRemover::remove);
			call.addConverter(&toUpperConverter::convert);
			call.write(actualStringSecondSection);
			Assert::AreEqual(expectedString, call.toString());
		}
	};
}