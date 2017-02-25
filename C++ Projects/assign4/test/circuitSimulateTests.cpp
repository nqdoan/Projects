#include "stdafx.h"
#include "CppUnitTest.h"

#include "circuit.h"
#include "andGate.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Assignment4New
{
	TEST_CLASS(circuitSimulateTests)
	{
	public:

		TEST_METHOD(twoAndGateCircuitTest)
		{
			circuit testCircuit;
			andGate gate0;
			andGate gate1;
			bus bus0;
			bus bus1;
			bus bus2;
			bus bus3;
			bus bus4;

			testCircuit.addBus(&bus2);
			testCircuit.addBus(&bus1);
			testCircuit.addBus(&bus0);
			testCircuit.addBus(&bus3);
			testCircuit.addBus(&bus4);

			testCircuit.addGate(&gate0);
			testCircuit.addGate(&gate1);

			testCircuit.connectBusIGateO(SOURCEINDEX, 0);
			testCircuit.connectBusIGateO(SOURCEINDEX, 1);
			testCircuit.connectBusIGateO(0, 2);
			testCircuit.connectBusIGateO(SOURCEINDEX, 3);
			testCircuit.connectBusIGateO(1, 4);

			testCircuit.connectGateIBusO(0, 0);
			testCircuit.connectGateIBusO(0, 1);
			testCircuit.connectGateIBusO(1, 2);
			testCircuit.connectGateIBusO(1, 3);
			testCircuit.connectGateIBusO(SINKINDEX, 4);


			bool expectedState[5] = { true, true, true, true, true };

			vector<bool> userInputs(3, true);
			testCircuit.simulate(userInputs);

			for (int index = 0; index < 5; index++)
			{
				Assert::AreEqual(expectedState[index], (bool)testCircuit.getBusses()[index]->getValue());
			}

		}

		TEST_METHOD(twoAndGateCircuitTestDifferentInputs)
		{
			circuit testCircuit;
			andGate gate0;
			andGate gate1;
			bus bus0;
			bus bus1;
			bus bus2;
			bus bus3;
			bus bus4;

			testCircuit.addBus(&bus2);
			testCircuit.addBus(&bus1);
			testCircuit.addBus(&bus0);
			testCircuit.addBus(&bus3);
			testCircuit.addBus(&bus4);

			testCircuit.addGate(&gate0);
			testCircuit.addGate(&gate1);

			testCircuit.connectBusIGateO(SOURCEINDEX, 0);
			testCircuit.connectBusIGateO(SOURCEINDEX, 1);
			testCircuit.connectBusIGateO(0, 2);
			testCircuit.connectBusIGateO(SOURCEINDEX, 3);
			testCircuit.connectBusIGateO(1, 4);

			testCircuit.connectGateIBusO(0, 0);
			testCircuit.connectGateIBusO(0, 1);
			testCircuit.connectGateIBusO(1, 2);
			testCircuit.connectGateIBusO(1, 3);
			testCircuit.connectGateIBusO(SINKINDEX, 4);


			bool expectedState[5] = { true, true, true, false, false };

			vector<bool> userInputs(3, true);
			userInputs[2] = false;
			testCircuit.simulate(userInputs);

			for (int index = 0; index < 5; index++)
			{
				Assert::AreEqual(expectedState[index], (bool)testCircuit.getBusses()[index]->getValue());
			}

		}

		TEST_METHOD(twoAndGateCircuitTestInvalidUserInput)
		{
			circuit testCircuit;
			andGate gate0;
			andGate gate1;
			bus bus0;
			bus bus1;
			bus bus2;
			bus bus3;
			bus bus4;

			testCircuit.addBus(&bus2);
			testCircuit.addBus(&bus1);
			testCircuit.addBus(&bus0);
			testCircuit.addBus(&bus3);
			testCircuit.addBus(&bus4);

			testCircuit.addGate(&gate0);
			testCircuit.addGate(&gate1);

			testCircuit.connectBusIGateO(SOURCEINDEX, 0);
			testCircuit.connectBusIGateO(SOURCEINDEX, 1);
			testCircuit.connectBusIGateO(0, 2);
			testCircuit.connectBusIGateO(SOURCEINDEX, 3);
			testCircuit.connectBusIGateO(1, 4);

			testCircuit.connectGateIBusO(0, 0);
			testCircuit.connectGateIBusO(0, 1);
			testCircuit.connectGateIBusO(1, 2);
			testCircuit.connectGateIBusO(1, 3);
			testCircuit.connectGateIBusO(SINKINDEX, 4);


			int expectedState[5] = { -1, -1, -1, -1, -1 };

			vector<bool> userInputs(2, true);
			testCircuit.simulate(userInputs);

			for (int index = 0; index < 5; index++)
			{
				Assert::AreEqual(expectedState[index], testCircuit.getBusses()[index]->getValue());
			}

		}

	};
}