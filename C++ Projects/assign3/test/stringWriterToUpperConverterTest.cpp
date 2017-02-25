#include "stdafx.h"
#include "CppUnitTest.h"
#include "stringWriter.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Assignment3
{
	TEST_CLASS(stringWriterToUpperConverterTest)
	{
	public:
		TEST_METHOD(stringWriterWriteTestWithToUpperConverter)
		{
			string expectedString = "THE TO UPPER TEST";
			string actualString = "the to upper test";
			stringWriter call;
			call.addConverter(&toUpperConverter::convert);
			call.write(actualString);
			Assert::AreEqual(expectedString, call.toString());
		}
	};
}