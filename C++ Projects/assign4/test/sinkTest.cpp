#include "stdafx.h"
#include "CppUnitTest.h"

#include "sinkGate.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Assignment4
{
	TEST_CLASS(sinkTest)
	{
	public:
		
		TEST_METHOD(computeTest)
		{
			sinkGate sink;

			Assert::AreEqual(true, sink.compute());
		}

		TEST_METHOD(noInputIsValid)
		{
			sinkGate sink;

			Assert::AreEqual(false, sink.isValid());
		}

		TEST_METHOD(OneInputIsValid)
		{
			sinkGate sink;

			bus testBus;

			sink.addInput(&testBus);

			Assert::AreEqual(true, sink.isValid());
		}

		TEST_METHOD(twoInputIsValid)
		{
			sinkGate sink;

			bus testBus1;
			bus testBus2;

			sink.addInput(&testBus1);
			sink.addInput(&testBus2);

			Assert::AreEqual(true, sink.isValid());
		}

		TEST_METHOD(threeInputIsValid)
		{
			sinkGate sink;

			bus testBus1;
			bus testBus2;
			bus testBus3;

			sink.addInput(&testBus1);
			sink.addInput(&testBus2);
			sink.addInput(&testBus3);

			Assert::AreEqual(true, sink.isValid());
		}

	};
}