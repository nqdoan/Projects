#include "stdafx.h"
#include "CppUnitTest.h"
#include "stringWriter.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Assignment3Remake
{
	TEST_CLASS(stringWriterTest)
	{
	public:
		TEST_METHOD(stringWriterWriteTest)
		{
			string expectedString = "These should be the same";
			string actualString = "These should be the same";
			stringWriter call;
			call.write(actualString);
			actualString = call.toString();
			Assert::AreEqual(expectedString, actualString);
		}
		TEST_METHOD(stringWriterWriteTestForTwoSections)
		{
			string expectedString = "These should be the same";
			string actualStringFirstSection = "These should ";
			string actualStringSecondSection = "be the same";
			stringWriter call;
			call.write(actualStringFirstSection);
			call.write(actualStringSecondSection);
			call.toString();
			Assert::AreEqual(expectedString, call.toString());
		}

		TEST_METHOD(stringWriterCloseTest)
		{
			string expectedString = "These should";
			string actualStringFirstSection = "These should";
			string actualStringSecondSection = " be the same";
			stringWriter call;
			call.write(actualStringFirstSection);
			call.close();
			call.write(actualStringSecondSection);
			Assert::AreEqual(expectedString, call.toString());
		}

		TEST_METHOD(stringWriterToStringTest)
		{
			string expectedString = "the to string test";
			string actualString = "the to string test";
			stringWriter call;
			call.write(actualString);
			Assert::AreEqual(expectedString, call.toString());
		}
	};
}