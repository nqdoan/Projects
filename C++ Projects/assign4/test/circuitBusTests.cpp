#include "stdafx.h"
#include "CppUnitTest.h"

#include "circuit.h"
#include "andGate.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Assignment4New
{
	TEST_CLASS(circuitBusTests)
	{
	public:
		
		TEST_METHOD(addOneBusTest)
		{
			bus testBus;
			circuit testCircuit;
			vector<bus*> expectedBusses;

			testCircuit.addBus(&testBus);

			expectedBusses.push_back(&testBus);

			Assert::AreEqual(true, expectedBusses == testCircuit.getBusses());
		}

		TEST_METHOD(addTwoBusTest)
		{
			bus testBus1;
			bus testBus2;
			circuit testCircuit;
			vector<bus*> expectedBusses;

			testCircuit.addBus(&testBus1);
			testCircuit.addBus(&testBus2);

			expectedBusses.push_back(&testBus1);
			expectedBusses.push_back(&testBus2);

			Assert::AreEqual(true, expectedBusses == testCircuit.getBusses());
		}

		TEST_METHOD(addThreeBusTest)
		{
			bus testBus1;
			bus testBus2;
			bus testBus3;
			circuit testCircuit;
			vector<bus*> expectedBusses;

			testCircuit.addBus(&testBus1);
			testCircuit.addBus(&testBus2);
			testCircuit.addBus(&testBus3);

			expectedBusses.push_back(&testBus1);
			expectedBusses.push_back(&testBus2);
			expectedBusses.push_back(&testBus3);

			Assert::AreEqual(true, expectedBusses == testCircuit.getBusses());
		}

		TEST_METHOD(removeOneBusTest)
		{
			bus testBus;
			circuit testCircuit;
			vector<bus*> expectedBusses;

			int busIndex = testCircuit.addBus(&testBus);
			testCircuit.removeBus(busIndex);

			Assert::AreEqual(true, expectedBusses == testCircuit.getBusses());
		}

		TEST_METHOD(removeTwoBusTest)
		{
			bus testBus1;
			bus testBus2;
			circuit testCircuit;
			vector<bus*> expectedBusses;

			testCircuit.addBus(&testBus1);
			testCircuit.addBus(&testBus2);

			testCircuit.removeBus(0);
			testCircuit.removeBus(0);

			Assert::AreEqual(true, expectedBusses == testCircuit.getBusses());
		}

		TEST_METHOD(removeInvalidBusIndexTest)
		{
			bus testBus1;
			bus testBus2;
			circuit testCircuit;
			vector<bus*> expectedBusses;

			testCircuit.addBus(&testBus1);
			testCircuit.addBus(&testBus2);

			expectedBusses.push_back(&testBus1);
			expectedBusses.push_back(&testBus2);

			Assert::AreEqual(false, testCircuit.removeBus(5));
			Assert::AreEqual(true, expectedBusses == testCircuit.getBusses());
		}

	};
}