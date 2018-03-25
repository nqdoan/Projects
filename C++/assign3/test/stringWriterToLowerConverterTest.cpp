#include "stdafx.h"
#include "CppUnitTest.h"
#include "stringWriter.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Assignment3
{
	TEST_CLASS(stringWriterToLowerConverterTest)
	{
	public:
		TEST_METHOD(stringWriterWriteTestWithToLowerConverter)
		{
			string expectedString = "the to lower test";
			string actualString = "THE TO LOWER TEST";
			stringWriter call;
			call.addConverter(&toLowerConverter::convert);
			call.write(actualString);
			Assert::AreEqual(expectedString, call.toString());
		}


	};
}