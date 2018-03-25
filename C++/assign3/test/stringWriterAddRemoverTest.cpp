#include "stdafx.h"
#include "CppUnitTest.h"
#include "stringWriter.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Assignment3
{
	TEST_CLASS(stringWriterAddRemoverTest)
	{
	public:
		TEST_METHOD(stringWriterAddOneRemoverToStringWriter)
		{
			vector<void(*)(string&)> expectedRemovers;
			expectedRemovers.push_back(&stupidRemover::remove);

			stringWriter testWriter;
			testWriter.addRemover(&stupidRemover::remove);
			Assert::AreEqual(true, expectedRemovers == testWriter.getRemover());
		}

		TEST_METHOD(stringWriterAddTwoRemoverToStringWriter)
		{
			vector<void(*)(string&)> expectedRemovers;
			expectedRemovers.push_back(&stupidRemover::remove);
			expectedRemovers.push_back(&duplicateRemover::remove);

			stringWriter testWriter;
			testWriter.addRemover(&stupidRemover::remove);
			testWriter.addRemover(&duplicateRemover::remove);
			Assert::AreEqual(true, expectedRemovers == testWriter.getRemover());
		}
	};
}