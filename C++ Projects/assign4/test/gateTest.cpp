#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Assignment4
{
	TEST_CLASS(gateTest)
	{
	public:
		
		TEST_METHOD(NoGateInputTest)
		{
			andGate testGate;

			vector<bus*> actualInput = testGate.getInput();
			vector<bus*> expectedInput;

			Assert::AreEqual(true, expectedInput == actualInput);
		}

		TEST_METHOD(singleGateInputTest)
		{
			bus testBus;
			andGate testGate;

			testGate.addInput(&testBus);

			vector<bus*> actualInput = testGate.getInput();
			vector<bus*> expectedInput;
			expectedInput.push_back(&testBus);

			Assert::AreEqual(true, expectedInput == actualInput);
		}

		TEST_METHOD(TwoGateInputTest)
		{
			bus testBus;
			andGate testGate;

			testGate.addInput(&testBus);
			testGate.addInput(&testBus);

			vector<bus*> actualInput = testGate.getInput();
			vector<bus*> expectedInput;
			expectedInput.push_back(&testBus);
			expectedInput.push_back(&testBus);

			Assert::AreEqual(true, expectedInput == actualInput);
		}

		TEST_METHOD(ThreeGateInputTest)
		{
			bus testBus;
			bus testBus2;
			andGate testGate;

			testGate.addInput(&testBus);
			testGate.addInput(&testBus);
			testGate.addInput(&testBus2);

			vector<bus*> actualInput = testGate.getInput();
			vector<bus*> expectedInput;
			expectedInput.push_back(&testBus);
			expectedInput.push_back(&testBus);
			expectedInput.push_back(&testBus2);

			Assert::AreEqual(true, expectedInput == actualInput);
		}

		TEST_METHOD(singleSetGateInputTest)
		{
			bus testBus;
			andGate testGate;
			
			vector<bus*> expectedInput;
			expectedInput.push_back(&testBus);

			testGate.setInput(expectedInput);

			vector<bus*> actualInput = testGate.getInput();

			Assert::AreEqual(true, expectedInput == actualInput);
		}

		TEST_METHOD(twoSetGateInputTest)
		{
			bus testBus;
			andGate testGate;
			
			vector<bus*> expectedInput;
			expectedInput.push_back(&testBus);
			expectedInput.push_back(&testBus);

			testGate.setInput(expectedInput);

			vector<bus*> actualInput = testGate.getInput();

			Assert::AreEqual(true, expectedInput == actualInput);
		}

		TEST_METHOD(threeSetGateInputTest)
		{
			bus testBus;
			bus testBus2;
			andGate testGate;

			vector<bus*> expectedInput;
			expectedInput.push_back(&testBus);
			expectedInput.push_back(&testBus);
			expectedInput.push_back(&testBus2);

			Assert::AreEqual(true, testGate.setInput(expectedInput));
			Assert::AreEqual(true, expectedInput == testGate.getInput());
		}

		TEST_METHOD(removeOneGateInputTest)
		{
			bus testBus1;
			bus testBus2;
			andGate testGate;

			vector<bus*> expectedInput;
			expectedInput.push_back(&testBus1);
			expectedInput.push_back(&testBus2);

			testGate.setInput(expectedInput);

			expectedInput.pop_back();
			testGate.removeInput(&testBus2);

			Assert::AreEqual(true, testGate.getInput() == expectedInput);
		}

		TEST_METHOD(removeTwoGateInputTest)
		{
			bus testBus1;
			bus testBus2;
			andGate testGate;

			vector<bus*> expectedInput;
			expectedInput.push_back(&testBus1);
			expectedInput.push_back(&testBus2);

			testGate.setInput(expectedInput);

			expectedInput.pop_back();
			expectedInput.pop_back();
			testGate.removeInput(&testBus1);
			testGate.removeInput(&testBus2);

			Assert::AreEqual(true, testGate.getInput() == expectedInput);
		}

		TEST_METHOD(removeInvalidGateInputTest)
		{
			bus testBus1;
			bus testBus2;
			andGate testGate;

			vector<bus*> expectedInput;
			expectedInput.push_back(&testBus1);
			expectedInput.push_back(&testBus1);

			testGate.setInput(expectedInput);


			Assert::AreEqual(false, testGate.removeInput(&testBus2));
			Assert::AreEqual(true, testGate.getInput() == expectedInput);
		}

		TEST_METHOD(SingleGateOutputTest)
		{
			bus testBus;
			andGate testGate;

			testGate.setOutput(&testBus);

			bus* actualOutput = testGate.getOutput();
			bus* expectedOutput = &testBus;

			Assert::AreEqual(true, expectedOutput == actualOutput);
		}		
		
		TEST_METHOD(TwoGateOutputTest)
		{
			bus testBus;
			bus testBus2;
			andGate testGate;

			testGate.setOutput(&testBus);
			testGate.setOutput(&testBus2);

			bus* actualOutput = testGate.getOutput();
			bus* expectedOutput = &testBus2;

			Assert::AreEqual(true, expectedOutput == actualOutput);
		}

		TEST_METHOD(noInputNoOutputIsValid)
		{
			andGate testGate;

			Assert::AreEqual(false, testGate.isValid());
		}

		TEST_METHOD(oneInputNoOutputIsValid)
		{
			bus testBus;
			andGate testGate;

			testGate.addInput(&testBus);

			Assert::AreEqual(false, testGate.isValid());
		}

		TEST_METHOD(noInputOneOutputIsValid)
		{
			bus testBus;
			andGate testGate;

			testGate.setOutput(&testBus);

			Assert::AreEqual(false, testGate.isValid());
		}

		TEST_METHOD(oneInputOneOutputIsValid)
		{
			bus testBus;
			andGate testGate;

			testGate.addInput(&testBus);
			testGate.setOutput(&testBus);

			Assert::AreEqual(false, testGate.isValid());
		}

		TEST_METHOD(twoInputOneOutputIsValid)
		{
			bus testBus;
			andGate testGate;

			testGate.addInput(&testBus);
			testGate.addInput(&testBus);
			testGate.setOutput(&testBus);

			Assert::AreEqual(true, testGate.isValid());
		}

		TEST_METHOD(oneInputTwoOutputIsValid)
		{
			bus testBus;
			andGate testGate;

			testGate.addInput(&testBus);
			testGate.setOutput(&testBus);
			testGate.setOutput(&testBus);

			Assert::AreEqual(false, testGate.isValid());
		}

		TEST_METHOD(twoInputTwoOutputIsValid)
		{
			bus testBus;
			andGate testGate;

			testGate.addInput(&testBus);
			testGate.addInput(&testBus);
			testGate.setOutput(&testBus);
			testGate.setOutput(&testBus);

			Assert::AreEqual(true, testGate.isValid());
		}

		TEST_METHOD(threeInputOneOutputIsValid)
		{
			bus testBus;
			andGate testGate;

			testGate.addInput(&testBus);
			testGate.addInput(&testBus);
			testGate.addInput(&testBus);
			testGate.setOutput(&testBus);

			Assert::AreEqual(false, testGate.isValid());
		}

		TEST_METHOD(gateRemoveInputTestOneInput)
		{
			andGate testGate;
			bus testBus;

			testGate.addInput(&testBus);
			testGate.removeInput(&testBus);
			vector<bus*> expectedOutput;

			Assert::AreEqual(true, (expectedOutput == testGate.getInput()));
		}

		TEST_METHOD(gateRemoveInputTestTwoInput)
		{
			andGate testGate;
			bus testBus;
			bus testBus2;

			testGate.addInput(&testBus);
			testGate.removeInput(&testBus2);
			vector<bus*> expectedOutput;
			expectedOutput.push_back(&testBus);

			Assert::AreEqual(false, testGate.removeInput(&testBus2));
			Assert::AreEqual(true, (expectedOutput == testGate.getInput()));
		}

		TEST_METHOD(gateRemoveOutputTestOneOutput)
		{
			andGate testGate;
			bus testBus;

			testGate.setOutput(&testBus);
			testGate.removeOutput(&testBus);
			bus* expectedOutput = NULL;

			Assert::AreEqual(true, (expectedOutput == testGate.getOutput()));
		}

		TEST_METHOD(gateRemoveOutputTestTwoOutput)
		{
			andGate testGate;
			bus testBus;
			bus testBus2;

			testGate.setOutput(&testBus);
			testGate.removeOutput(&testBus2);
			bus* expectedOutput = &testBus;

			Assert::AreEqual(false, testGate.removeOutput(&testBus2));
			Assert::AreEqual(true, (expectedOutput == testGate.getOutput()));
		}

	};
}