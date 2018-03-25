#include "stdafx.h"
#include "CppUnitTest.h"
#include "stringWriter.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Assignment3
{
	TEST_CLASS(stringWriterDuplicateRemoverTest)
	{
	public:
		TEST_METHOD(stringWriterWriteDuplicateRemoverTest)
		{
			string expectedString = "This should look normal";
			string actualString = "This should look look normal";
			stringWriter call;
			call.addRemover(&duplicateRemover::remove);
			call.write(actualString);
			Assert::AreEqual(expectedString, call.toString());
		}
	};
}