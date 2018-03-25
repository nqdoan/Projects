#include "stdafx.h"
#include "CppUnitTest.h"
#include "stupidRemover.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Assignment3
{
	TEST_CLASS(stupidRemoverTest)
	{
	public:
		TEST_METHOD(stupidRemoverTestForOneStupid)
		{
			string expectedString = "The word s***** should be gone";
			string actualString = "The word stupid should be gone";
			stupidRemover::remove(actualString);
			Assert::AreEqual(expectedString,  actualString);
		}

		TEST_METHOD(stupidRemoverTestForTwoConsecutiveStupid)
		{
			string expectedString = "The word s***** s***** should be gone";
			string actualString = "The word stupid stupid should be gone";
			stupidRemover::remove(actualString);
			Assert::AreEqual(expectedString, actualString);
		}
		
		TEST_METHOD(stupidRemoverTestForStupidInTwoPlaces)
		{
			string expectedString = "The word s***** should be gone s*****";
			string actualString = "The word stupid should be gone stupid";
			stupidRemover::remove(actualString);
			Assert::AreEqual(expectedString, actualString);
		}
	};
}