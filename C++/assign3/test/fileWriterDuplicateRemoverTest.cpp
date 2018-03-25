#include "stdafx.h"
#include "CppUnitTest.h"
#include "fileWriter.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Assignment3
{
	TEST_CLASS(fileWriterDuplicateRemoverTest)
	{
	public:
		TEST_METHOD(fileWriterWriteDuplicateRemoverTest)
		{
			ofstream file("fileWriterOutput.txt", ios_base::out | ios_base::trunc); //This ensures files are empty so that tests do not bleed into each other
			file.close();

			string expectedString = "This should look normal";
			string actualString = "This should look look normal";
			fileWriter call;
			call.addRemover(&duplicateRemover::remove);
			call.write(actualString);
			Assert::AreEqual(expectedString, call.toString());
		}
	};
}