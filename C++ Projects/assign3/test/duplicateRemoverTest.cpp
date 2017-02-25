#include "stdafx.h"
#include "CppUnitTest.h"
#include "duplicateRemover.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Assignment3
{
	TEST_CLASS(duplicateRemoverTest)
	{
	public:
		TEST_METHOD(duplicateRemoverTestForOneDuplicate)
		{
			string expectedString = "These should be the same";
			string actualString = "These should be be the same";
			duplicateRemover::remove(actualString);
			Assert::AreEqual(expectedString, actualString);
		}

		TEST_METHOD(duplicateRemoverTestForTwoDuplicate)
		{
			string expectedString = "These should be the same";
			string actualString = "These These should be be the same";
			duplicateRemover::remove(actualString);
			Assert::AreEqual(expectedString, actualString);
		}

		TEST_METHOD(duplicateRemoverTestFOrTripleDuplicate)
		{
			string expectedString = "These should be the same";
			string actualString = "These These should be be be the same";
			duplicateRemover::remove(actualString);
			Assert::AreEqual(expectedString, actualString);
		}
	};
}