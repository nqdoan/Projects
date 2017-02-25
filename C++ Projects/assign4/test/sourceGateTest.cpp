#include "stdafx.h"
#include "CppUnitTest.h"
#include "sourceGate.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Assignment4New
{
	TEST_CLASS(sourceGateTest)
	{
	public:

		TEST_METHOD(sourceGateTestAddOneOutput)
		{
			  sourceGate source;
			  bus testBus;


			  source.addOutput(&testBus);

			  vector<bus *> expectedBusses;

			  expectedBusses.push_back(&testBus);

			  Assert::AreEqual(true, expectedBusses == source.getOutputs());
		}

		TEST_METHOD(sourceGateTestAddTwoOutput)
		{
			  sourceGate source;
			  bus testBus1;
			  bus testBus2;

			  source.addOutput(&testBus1);
			  source.addOutput(&testBus2);


			  vector<bus *> expectedBusses;

			  expectedBusses.push_back(&testBus1);
			  expectedBusses.push_back(&testBus2);

			  Assert::AreEqual(true, expectedBusses == source.getOutputs());
		}
		
		TEST_METHOD(sourceGateTestAddThreeOutput)
		{
			sourceGate source;
			bus testBus1;
			bus testBus2;
			bus testBus3;

			source.addOutput(&testBus1);
			source.addOutput(&testBus2);
			source.addOutput(&testBus3);

			vector<bus *> expectedBusses;

			expectedBusses.push_back(&testBus1);
			expectedBusses.push_back(&testBus2);
			expectedBusses.push_back(&testBus3);

			Assert::AreEqual(true, expectedBusses == source.getOutputs());
		}

		TEST_METHOD(sourceGateRemoveOneOutputTest)
		{
			sourceGate source;
			bus testBus;

			source.addOutput(&testBus);
			source.removeOutputs(&testBus);

			vector<bus *> expectedBusses;

			Assert::AreEqual(true, expectedBusses == source.getOutputs());
		}

		TEST_METHOD(sourceGateRemoveTwoOutputTest)
		{
			sourceGate source;
			bus testBus1;
			bus testBus2;

			source.addOutput(&testBus1);
			source.addOutput(&testBus2);
			vector<bus *> expectedBusses;

			source.removeOutputs(&testBus1);
			source.removeOutputs(&testBus2);


			Assert::AreEqual(true, expectedBusses == source.getOutputs());
		}

		TEST_METHOD(sourceGateRemoveTwoOutputTestRemoveOne)
		{
			sourceGate source;
			bus testBus1;
			bus testBus2;

			source.addOutput(&testBus1);
			source.addOutput(&testBus2);
			source.removeOutputs(&testBus1);

			vector<bus *> expectedBusses;

			expectedBusses.push_back(&testBus2);

			Assert::AreEqual(true, expectedBusses == source.getOutputs());
		}

		TEST_METHOD(sourceGateSetOutputTest)
		{
			sourceGate source;
			bus testBus;

			vector<bus*> expectedBusses;

			expectedBusses.push_back(&testBus);
			source.setOutput(expectedBusses);

			Assert::AreEqual(true, expectedBusses == source.getOutputs());
		}

		TEST_METHOD(NoOutputIsValid)
		{
			sourceGate source;

			Assert::AreEqual(false, source.isValid());
		}

		TEST_METHOD(oneOutputIsValid)
		{
			sourceGate source;

			bus testBus;

			source.addOutput(&testBus);

			Assert::AreEqual(true, source.isValid());
		}

		TEST_METHOD(twoOutputIsValid)
		{
			sourceGate source;

			bus testBus;

			source.addOutput(&testBus);

			Assert::AreEqual(true, source.isValid());
		}

		TEST_METHOD(computeTest)
		{
			sourceGate source;

			Assert::AreEqual(true, source.compute());
		}

	};
}