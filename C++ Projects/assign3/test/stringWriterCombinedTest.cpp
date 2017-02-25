#include "stdafx.h"
#include "CppUnitTest.h"
#include "stringWriter.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Assignment3
{
	TEST_CLASS(stringWriterCombinedConverterTest)
	{
	public:
		TEST_METHOD(stringWriterWriteLowerFirstTest)
		{
			string expectedString = "this part IS BIG";
			string actualStringFirstSection = "THIS PART ";
			string actualStringSecondSection = "is big";
			stringWriter call;
			call.addConverter(&toLowerConverter::convert);
			call.write(actualStringFirstSection);
			call.addConverter(&toUpperConverter::convert);
			call.write(actualStringSecondSection);
			Assert::AreEqual(expectedString, call.toString());
		}

		TEST_METHOD(stringWriterWriteUpperFirstTest)
		{
			string expectedString = "THIS PART is small";
			string actualStringFirstSection = "this part ";
			string actualStringSecondSection = "IS SMALL";
			stringWriter call;
			call.addConverter(&toUpperConverter::convert);
			call.write(actualStringFirstSection);
			call.addConverter(&toLowerConverter::convert);
			call.write(actualStringSecondSection);
			Assert::AreEqual(expectedString, call.toString());
		}

		TEST_METHOD(stringWriterDuplicateFirstTest)
		{
			string expectedString = "the word s***** should be hidden";
			string actualStringFirstSection = "the word word ";
			string actualStringSecondSection = "stupid should be hidden";
			stringWriter call;
			call.addRemover(&duplicateRemover::remove);
			call.write(actualStringFirstSection);
			call.addRemover(&stupidRemover::remove);
			call.write(actualStringSecondSection);
			Assert::AreEqual(expectedString, call.toString());
		}
		TEST_METHOD(stringWriterStupidFirstTest)
		{
			string expectedString = "the word s***** should be hidden";
			string actualStringFirstSection = "the word stupid ";
			string actualStringSecondSection = "should be hidden";
			stringWriter call;
			call.addRemover(&stupidRemover::remove);
			call.write(actualStringFirstSection);
			call.addRemover(&duplicateRemover::remove);
			call.write(actualStringSecondSection);
			Assert::AreEqual(expectedString, call.toString());
		}

		TEST_METHOD(stringWriterTestForAll)
		{
			string expectedString = "the word s***** SHOULD BE HIDDEN";
			string actualStringFirstSection = "the word stupid ";
			string actualStringSecondSection = "should be be hidden";
			stringWriter call;
			call.addConverter(&toLowerConverter::convert);
			call.addRemover(&stupidRemover::remove);
			call.write(actualStringFirstSection);
			call.addRemover(&duplicateRemover::remove);
			call.addConverter(&toUpperConverter::convert);
			call.write(actualStringSecondSection);
			Assert::AreEqual(expectedString, call.toString());
		}
	};
}