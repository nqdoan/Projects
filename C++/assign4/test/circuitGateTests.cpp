#include "stdafx.h"
#include "CppUnitTest.h"

#include "circuit.h"
#include "andGate.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Assignment4New
{
	TEST_CLASS(circuitGateTests)
	{
	public:

		TEST_METHOD(addOneGateTest)
		{
			andGate testGate1;
			circuit testCircuit;
			vector<gate*> expectedBusses;

			testCircuit.addGate(&testGate1);

			expectedBusses.push_back(&testGate1);

			Assert::AreEqual(true, expectedBusses == testCircuit.getGates());
		}

		TEST_METHOD(addTwoGateTest)
		{
			andGate testGate1;
			andGate testGate2;
			circuit testCircuit;
			vector<gate*> expectedBusses;

			testCircuit.addGate(&testGate1);
			testCircuit.addGate(&testGate2);

			expectedBusses.push_back(&testGate1);
			expectedBusses.push_back(&testGate2);

			Assert::AreEqual(true, expectedBusses == testCircuit.getGates());
		}

		TEST_METHOD(addThreeGateTest)
		{
			andGate testGate1;
			andGate testGate2;
			andGate testGate3;
			circuit testCircuit;
			vector<gate*> expectedBusses;

			testCircuit.addGate(&testGate1);
			testCircuit.addGate(&testGate2);
			testCircuit.addGate(&testGate3);

			expectedBusses.push_back(&testGate1);
			expectedBusses.push_back(&testGate2);
			expectedBusses.push_back(&testGate3);

			Assert::AreEqual(true, expectedBusses == testCircuit.getGates());
		}

		TEST_METHOD(removeOneGateTest)
		{
			andGate testGate;
			circuit testCircuit;
			vector<gate*> expectedGates;

			testCircuit.addGate(&testGate);

			testCircuit.removeGate(0);

			Assert::AreEqual(true, expectedGates == testCircuit.getGates());
		}

		TEST_METHOD(removeTwoGateTest)
		{
			andGate testGate1;
			andGate testGate2;
			circuit testCircuit;
			vector<gate*> expectedGates;

			testCircuit.addGate(&testGate1);
			testCircuit.addGate(&testGate2);

			testCircuit.removeGate(0);
			testCircuit.removeGate(0);

			Assert::AreEqual(true, expectedGates == testCircuit.getGates());
		}

		TEST_METHOD(removeInvalidGateIndexTest)
		{
			andGate testGate1;
			andGate testGate2;
			circuit testCircuit;
			vector<gate*> expectedGates;

			testCircuit.addGate(&testGate1);
			testCircuit.addGate(&testGate2);

			expectedGates.push_back(&testGate1);
			expectedGates.push_back(&testGate2);

			Assert::AreEqual(false, testCircuit.removeGate(5));
			Assert::AreEqual(true, expectedGates == testCircuit.getGates());
		}
	};
}