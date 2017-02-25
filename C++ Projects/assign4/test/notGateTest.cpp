#include "stdafx.h"
#include "CppUnitTest.h"
#include "notGate.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Assignment4
{
	TEST_CLASS(notGateTest)
	{
	public:

		TEST_METHOD(notGateCallNotTrue)
		{
			bus testBus;
			notGate testGate;

			testBus.setValue(1);

			testGate.addInput(&testBus);

			Assert::AreEqual(false, testGate.compute());
		}


		TEST_METHOD(notGateCallNotFalse)
		{
			bus testBus;
			notGate testGate;

			testBus.setValue(0);

			testGate.addInput(&testBus);

			Assert::AreEqual(true, testGate.compute());
		}

		TEST_METHOD(notGateCallNotSet)
		{
			bus testBus;
			notGate testGate;

			testBus.setValue(-1);

			testGate.addInput(&testBus);

			Assert::AreEqual(false, testGate.compute());
		}

		TEST_METHOD(noInputNoOutputIsValid)
		{
			notGate testGate;

			Assert::AreEqual(false, testGate.isValid());
		}

		TEST_METHOD(oneInputNoOutputIsValid)
		{
			bus testBus;
			notGate testGate;

			testGate.addInput(&testBus);

			Assert::AreEqual(false, testGate.isValid());
		}

		TEST_METHOD(noInputOneOutputIsValid)
		{
			bus testBus;
			notGate testGate;

			testGate.setOutput(&testBus);

			Assert::AreEqual(false, testGate.isValid());
		}

		TEST_METHOD(oneInputOneOutputIsValid)
		{
			bus testBus;
			notGate testGate;

			testGate.addInput(&testBus);
			testGate.setOutput(&testBus);

			Assert::AreEqual(true, testGate.isValid());
		}

		TEST_METHOD(twoInputOneOutputIsValid)
		{
			bus testBus;
			notGate testGate;

			testGate.addInput(&testBus);
			testGate.addInput(&testBus);
			testGate.setOutput(&testBus);

			Assert::AreEqual(false, testGate.isValid());
		}

		TEST_METHOD(oneInputTwoOutputIsValid)
		{
			bus testBus;
			notGate testGate;

			testGate.addInput(&testBus);
			testGate.setOutput(&testBus);
			testGate.setOutput(&testBus);

			Assert::AreEqual(true, testGate.isValid());
		}

		TEST_METHOD(twoInputTwoOutputIsValid)
		{
			bus testBus;
			notGate testGate;

			testGate.addInput(&testBus);
			testGate.addInput(&testBus);
			testGate.setOutput(&testBus);
			testGate.setOutput(&testBus);

			Assert::AreEqual(false, testGate.isValid());
		}

	};
}