#include "stdafx.h"
#include "CppUnitTest.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Assignment4
{
	TEST_CLASS(busTest)
	{
	public:
		
		TEST_METHOD(setValueToTrue)
		{
			bus testBus;
			testBus.setValue(1);

			Assert::AreEqual(1, testBus.getValue());
		}

		TEST_METHOD(setValueToFalse)
		{
			bus testBus;
			testBus.setValue(0);

			Assert::AreEqual(0, testBus.getValue());
		}

		TEST_METHOD(doNotSetValueTest)
		{
			bus testBus;

			Assert::AreEqual(-1, testBus.getValue());
		}

		TEST_METHOD(singleOutputBusTest)
		{
			andGate testGate;
			bus testBus;

			testBus.addOutput(&testGate);
			vector<gate*> expectedOutput;  
			expectedOutput.push_back(&testGate);

			Assert::AreEqual(true, (expectedOutput == testBus.getOutput()));
		}

		TEST_METHOD(TwoOutputBusTest)
		{
			andGate testGate;
			bus testBus;

			testBus.addOutput(&testGate);
			testBus.addOutput(&testGate);
			vector<gate*> expectedOutput;  
			expectedOutput.push_back(&testGate);
			expectedOutput.push_back(&testGate);

			Assert::AreEqual(true, (expectedOutput == testBus.getOutput()));
		}

		TEST_METHOD(ThreeOutputBusTest)
		{
			andGate testGate;
			bus testBus;

			testBus.addOutput(&testGate);
			testBus.addOutput(&testGate);
			testBus.addOutput(&testGate);
			vector<gate*> expectedOutput;  
			expectedOutput.push_back(&testGate);
			expectedOutput.push_back(&testGate);
			expectedOutput.push_back(&testGate);

			Assert::AreEqual(true, (expectedOutput == testBus.getOutput()));
		}

		TEST_METHOD(removeSingleOutputBusTest)
		{
			andGate testGate1;
			andGate testGate2;
			andGate testGate3;
			bus testBus;

			testBus.addOutput(&testGate1);
			testBus.addOutput(&testGate2);
			testBus.addOutput(&testGate3);
			testBus.removeOutput(&testGate2);
			vector<gate*> expectedOutput;  
			expectedOutput.push_back(&testGate1);
			expectedOutput.push_back(&testGate3);

			Assert::AreEqual(true, (expectedOutput == testBus.getOutput()));
		}

		TEST_METHOD(removeDoubleOutputBusTest)
		{
			andGate testGate1;
			andGate testGate2;
			andGate testGate3;
			bus testBus;

			testBus.addOutput(&testGate1);
			testBus.addOutput(&testGate2);
			testBus.addOutput(&testGate3);
			testBus.removeOutput(&testGate1);
			testBus.removeOutput(&testGate2);
			vector<gate*> expectedOutput;
			expectedOutput.push_back(&testGate3);

			Assert::AreEqual(true, (expectedOutput == testBus.getOutput()));
		}

		TEST_METHOD(removeInvalidOutputBusTest)
		{
			andGate testGate1;
			andGate testGate2;
			andGate testGate3;
			bus testBus;

			testBus.addOutput(&testGate1);
			testBus.addOutput(&testGate3);

			Assert::AreEqual(false, testBus.removeOutput(&testGate2));
		}

		TEST_METHOD(SingleInputBusTest)
		{
			andGate testGate;
			bus testBus;

			testBus.setInput(&testGate);
			gate* expectedOutput = &testGate;

			Assert::AreEqual(true, (expectedOutput == testBus.getInput()));
		}

		TEST_METHOD(TwoInputBusTest)
		{
			andGate testGate;
			andGate testGate2;
			bus testBus;

			testBus.setInput(&testGate);
			testBus.setInput(&testGate2);

			gate* expectedOutput;  
			expectedOutput = &testGate2;

			Assert::AreEqual(true, (expectedOutput == testBus.getInput()));
		}

		TEST_METHOD(noInputNoOutputIsValid)
		{
			bus testBus;

			Assert::AreEqual(false, testBus.isValid());
		}

		TEST_METHOD(oneInputNoOutputIsValid)
		{
			bus testBus;
			andGate testGate;

			testBus.setInput(&testGate);

			Assert::AreEqual(false, testBus.isValid());
		}

		TEST_METHOD(noInputOneOutputIsValid)
		{
			bus testBus;
			andGate testGate;

			testBus.addOutput(&testGate);

			Assert::AreEqual(false, testBus.isValid());
		}

		TEST_METHOD(oneInputOneOutputIsValid)
		{
			bus testBus;
			andGate testGate;

			testBus.setInput(&testGate);
			testBus.addOutput(&testGate);

			Assert::AreEqual(true, testBus.isValid());
		}

		TEST_METHOD(twoInputOneOutputIsValid)
		{
			bus testBus;
			andGate testGate;

			testBus.setInput(&testGate);
			testBus.setInput(&testGate);
			testBus.addOutput(&testGate);

			Assert::AreEqual(true, testBus.isValid());
		}

		TEST_METHOD(oneInputTwoOutputIsValid)
		{
			bus testBus;
			andGate testGate;

			testBus.setInput(&testGate);
			testBus.addOutput(&testGate);
			testBus.addOutput(&testGate);

			Assert::AreEqual(true, testBus.isValid());
		}

		TEST_METHOD(twoInputTwoOutputIsValid)
		{
			bus testBus;
			andGate testGate;

			testBus.setInput(&testGate);
			testBus.setInput(&testGate); 
			testBus.addOutput(&testGate);
			testBus.addOutput(&testGate);

			Assert::AreEqual(true, testBus.isValid());
		}

		TEST_METHOD(busRemoveInputTestOneInput)
		{
			andGate testGate;
			bus testBus;

			testBus.setInput(&testGate);
			testBus.removeInput(&testGate);
			gate* expectedOutput = NULL;

			Assert::AreEqual(true, (expectedOutput == testBus.getInput()));
		}

		TEST_METHOD(busRemoveInputTestInvalidInput)
		{
			andGate testGate;
			bus testBus;
			andGate testGate2;

			testBus.setInput(&testGate);
			testBus.removeInput(&testGate2);
			gate* expectedOutput = &testGate;

			Assert::AreEqual(false, testBus.removeInput(&testGate2));
			Assert::AreEqual(true, (expectedOutput == testBus.getInput()));
		}
	};
}