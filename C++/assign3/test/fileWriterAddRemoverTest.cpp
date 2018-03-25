#include "stdafx.h"
#include "CppUnitTest.h"
#include "fileWriter.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Assignment3
{
	TEST_CLASS(fileWriterAddRemoverTest)
	{
	public:
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

		TEST_METHOD(fileWriterAddTwoRemoverTofileWriter)
		{
			ofstream file("fileWriterOutput.txt", ios_base::out | ios_base::trunc); //This ensures files are empty so that tests do not bleed into each other
			file.close();

			vector<void(*)(string&)> expectedRemovers;
			expectedRemovers.push_back(&stupidRemover::remove);
			expectedRemovers.push_back(&duplicateRemover::remove);

			fileWriter testWriter;
			testWriter.addRemover(&stupidRemover::remove);
			testWriter.addRemover(&duplicateRemover::remove);
			Assert::AreEqual(true, expectedRemovers == testWriter.getRemover());
		}
	};
}