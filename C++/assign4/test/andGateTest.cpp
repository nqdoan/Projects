#include "stdafx.h"
#include "CppUnitTest.h"
#include "andGate.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Assignment4
{
	TEST_CLASS(andGateTest)
	{
	public:

		TEST_METHOD(andGateCallOneOne)
		{
			bus testBus1;
			bus testBus2;
			andGate testGate;

			testBus1.setValue(1);
			testBus2.setValue(1);

			testGate.addInput(&testBus2);
			testGate.addInput(&testBus1);
			Assert::AreEqual(true, testGate.compute());
		}


		TEST_METHOD(andGateCallOneZero)
		{
			bus testBus1;
			bus testBus2;
			andGate testGate;

			testBus1.setValue(1);
			testBus2.setValue(0);

			testGate.addInput(&testBus2);
			testGate.addInput(&testBus1);
			Assert::AreEqual(false, testGate.compute());
		}

		TEST_METHOD(andGateCallZeroOne)
		{
			bus testBus1;
			bus testBus2;
			andGate testGate;

			testBus1.setValue(0);
			testBus2.setValue(1);

			testGate.addInput(&testBus2);
			testGate.addInput(&testBus1);
			Assert::AreEqual(false, testGate.compute());
		}

		TEST_METHOD(andGateCallZeroZero)
		{
			bus testBus1;
			bus testBus2;
			andGate testGate;

			testBus1.setValue(0);
			testBus2.setValue(0);

			testGate.addInput(&testBus2);
			testGate.addInput(&testBus1);
			Assert::AreEqual(false, testGate.compute());
		}

		TEST_METHOD(andGateCallZeroNotSet)
		{
			bus testBus1;
			bus testBus2;
			andGate testGate;

			testBus1.setValue(0);
			testBus2.setValue(-1);

			testGate.addInput(&testBus2);
			testGate.addInput(&testBus1);
			Assert::AreEqual(false, testGate.compute());
		}

		TEST_METHOD(andGateCallNotSetZero)
		{
			bus testBus1;
			bus testBus2;
			andGate testGate;

			testBus1.setValue(-1);
			testBus2.setValue(0);

			testGate.addInput(&testBus2);
			testGate.addInput(&testBus1);
			Assert::AreEqual(false, testGate.compute());
		}

	};
}