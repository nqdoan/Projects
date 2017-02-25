#include "stdafx.h"
#include "CppUnitTest.h"
#include "toLowerConverter.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Assignment3
{		
	TEST_CLASS(toLowerConverterTest)
	{
	public:
		TEST_METHOD(changeTextToLowerInitialLower)
		{
			string expectedString = "these should be the same";
			string actualString = "these should be the same";
			toLowerConverter::convert(actualString);
			Assert::AreEqual(expectedString, actualString);
		}

		TEST_METHOD(changeTextToLowerInitialMix)
		{
			string expectedString = "these should be the same";
			string actualString = "THESE should BE the SAME";
			toLowerConverter::convert(actualString);
			Assert::AreEqual(expectedString, actualString);
		}
		TEST_METHOD(changeTextToLowerInitialUpper)
		{
			string expectedString = "these should be the same";
			string actualString = "THESE SHOULD BE THE SAME";
			toLowerConverter::convert(actualString);
			Assert::AreEqual(expectedString, actualString);
		}
	};
}