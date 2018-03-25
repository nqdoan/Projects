#include "stdafx.h"
#include "CppUnitTest.h"
#include "stringWriter.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Assignment3
{
	TEST_CLASS(stringWriterAddConverterTest)
	{
	public:
		TEST_METHOD(stringWriterAddOneConverterToStringWriter)
		{
			vector<void(*)(string&)> expectedConverters;
			expectedConverters.push_back(&toLowerConverter::convert);

			stringWriter testWriter;
			testWriter.addConverter(&toLowerConverter::convert);
			Assert::AreEqual(true, expectedConverters == testWriter.getConverter());
		}

		TEST_METHOD(stringWriterAddTwoConverterToStringWriter)
		{
			vector<void(*)(string&)> expectedConverters;
			expectedConverters.push_back(&toLowerConverter::convert);
			expectedConverters.push_back(&toUpperConverter::convert);

			stringWriter testWriter;
			testWriter.addConverter(&toLowerConverter::convert);
			testWriter.addConverter(&toUpperConverter::convert);
			Assert::AreEqual(true, expectedConverters == testWriter.getConverter());
		}

		TEST_METHOD(stringWriterAddOneRemoverToStringWriter)
		{
			vector<void(*)(string&)> expectedRemovers;
			expectedRemovers.push_back(&stupidRemover::remove);

			stringWriter testWriter;
			testWriter.addRemover(&stupidRemover::remove);
			Assert::AreEqual(true, expectedRemovers == testWriter.getRemover());
		}
	};
}