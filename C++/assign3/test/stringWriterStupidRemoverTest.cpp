#include "stdafx.h"
#include "CppUnitTest.h"
#include "stringWriter.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Assignment3
{
	TEST_CLASS(stringWriterStupideRemoverTest)
	{
	public:
		TEST_METHOD(stringWriterWriteStupidRemoverTest)
		{
			string expectedString = "What is this word: s*****";
			string actualString = "What is this word: stupid";
			stringWriter call;
			call.addRemover(&stupidRemover::remove);
			call.write(actualString);
			Assert::AreEqual(expectedString, call.toString());
		}


	};
}