#include "stdafx.h"
#include "CppUnitTest.h"
#include "toUpperConverter.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Assignment3
{
	TEST_CLASS(toUpperConverterTest)
	{
	public:
		TEST_METHOD(changeTextToUpperInitialUpper)
		{
			string expectedString = "THESE SHOULD BE THE SAME";
			string actualString = "THESE SHOULD BE THE SAME";
			toUpperConverter::convert(actualString);
			Assert::AreEqual(actualString, expectedString);
		}
		TEST_METHOD(changeTextToUpperInitialMix)
		{
			string expectedString = "THESE SHOULD BE THE SAME";
			string actualString = "these SHOULD be THE same";
			toUpperConverter::convert(actualString);
			Assert::AreEqual(actualString, expectedString);
		}
		TEST_METHOD(changeTextToUpperInitialLower)
		{
			string expectedString = "THESE SHOULD BE THE SAME";
			string actualString = "these should be the same";
			toUpperConverter::convert(actualString);
			Assert::AreEqual(actualString, expectedString);
		}

	};
}