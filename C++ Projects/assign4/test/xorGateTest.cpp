#include "stdafx.h"
#include "CppUnitTest.h"
#include "xorGate.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Assignment4
{
	TEST_CLASS(xorGateTest)
	{
	public:

		TEST_METHOD(xorGateCallOneOne)
		{
			bus testBus1;
			bus testBus2;
			xorGate testGate;

			testBus1.setValue(1);
			testBus2.setValue(1);

			testGate.addInput(&testBus2);
			testGate.addInput(&testBus1);
			Assert::AreEqual(false, testGate.compute());
		}


		TEST_METHOD(xorGateCallOneZero)
		{
			bus testBus1;
			bus testBus2;
			xorGate testGate;

			testBus1.setValue(1);
			testBus2.setValue(0);

			testGate.addInput(&testBus2);
			testGate.addInput(&testBus1);
			Assert::AreEqual(true, testGate.compute());
		}

		TEST_METHOD(xorGateCallZeroOne)
		{
			bus testBus1;
			bus testBus2;
			xorGate testGate;

			testBus1.setValue(0);
			testBus2.setValue(1);

			testGate.addInput(&testBus2);
			testGate.addInput(&testBus1);
			Assert::AreEqual(true, testGate.compute());
		}

		TEST_METHOD(xorGateCallZeroZero)
		{
			bus testBus1;
			bus testBus2;
			xorGate testGate;

			testBus1.setValue(0);
			testBus2.setValue(0);

			testGate.addInput(&testBus2);
			testGate.addInput(&testBus1);
			Assert::AreEqual(false, testGate.compute());
		}

		TEST_METHOD(xorGateCallZeroNotSet)
		{
			bus testBus1;
			bus testBus2;
			xorGate testGate;

			testBus1.setValue(0);
			testBus2.setValue(-1);

			testGate.addInput(&testBus2);
			testGate.addInput(&testBus1);
			Assert::AreEqual(false, testGate.compute());
		}

		TEST_METHOD(xorGateCallNotSetZero)
		{
			bus testBus1;
			bus testBus2;
			xorGate testGate;

			testBus1.setValue(-1);
			testBus2.setValue(0);

			testGate.addInput(&testBus2);
			testGate.addInput(&testBus1);
			Assert::AreEqual(false, testGate.compute());
		}

	};
}