#include "stdafx.h"
#include "CppUnitTest.h"
#include "orGate.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Assignment4
{
	TEST_CLASS(orGateTest)
	{
	public:

		TEST_METHOD(orGateCallOneOne)
		{
			bus testBus1;
			bus testBus2;
			orGate testGate;

			testBus1.setValue(1);
			testBus2.setValue(1);

			testGate.addInput(&testBus2);
			testGate.addInput(&testBus1);
			Assert::AreEqual(true, testGate.compute());
		}


		TEST_METHOD(orGateCallOneZero)
		{
			bus testBus1;
			bus testBus2;
			orGate testGate;

			testBus1.setValue(1);
			testBus2.setValue(0);

			testGate.addInput(&testBus2);
			testGate.addInput(&testBus1);
			Assert::AreEqual(true, testGate.compute());
		}

		TEST_METHOD(orGateCallZeroOne)
		{
			bus testBus1;
			bus testBus2;
			orGate testGate;

			testBus1.setValue(0);
			testBus2.setValue(1);

			testGate.addInput(&testBus2);
			testGate.addInput(&testBus1);
			Assert::AreEqual(true, testGate.compute());
		}

		TEST_METHOD(orGateCallZeroZero)
		{
			bus testBus1;
			bus testBus2;
			orGate testGate;

			testBus1.setValue(0);
			testBus2.setValue(0);

			testGate.addInput(&testBus2);
			testGate.addInput(&testBus1);
			Assert::AreEqual(false, testGate.compute());
		}

		TEST_METHOD(orGateCallZeroNotSet)
		{
			bus testBus1;
			bus testBus2;
			orGate testGate;

			testBus1.setValue(0);
			testBus2.setValue(-1);

			testGate.addInput(&testBus2);
			testGate.addInput(&testBus1);
			Assert::AreEqual(false, testGate.compute());
		}

		TEST_METHOD(orGateCallNotSetZero)
		{
			bus testBus1;
			bus testBus2;
			orGate testGate;

			testBus1.setValue(-1);
			testBus2.setValue(0);

			testGate.addInput(&testBus2);
			testGate.addInput(&testBus1);
			Assert::AreEqual(false, testGate.compute());
		}

	};
}