#include "stdafx.h"
#include "CppUnitTest.h"

#include "circuit.h"
#include "andGate.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Assignment4New
{
	TEST_CLASS(circuitIsValidTests)
	{
	public:
		
		TEST_METHOD(validCircuitIsValid)
		{
			circuit testCircuit;
			andGate gate0;
			andGate gate1;
			bus bus0;
			bus bus1;
			bus bus2;

			testCircuit.addBus(&bus0);
			testCircuit.addBus(&bus1);
			testCircuit.addBus(&bus2);

			testCircuit.addGate(&gate0);

			testCircuit.connectBusIGateO(SOURCEINDEX, 0);
			testCircuit.connectBusIGateO(SOURCEINDEX, 1);
			testCircuit.connectBusIGateO(0, 2);

			testCircuit.connectGateIBusO(0, 0);
			testCircuit.connectGateIBusO(0, 1);
			testCircuit.connectGateIBusO(SINKINDEX, 2);

			Assert::AreEqual(true, testCircuit.isValid());
		}

		TEST_METHOD(invalidCircuitIsValid)
		{
			circuit testCircuit;
			andGate gate0;
			andGate gate1;
			bus bus0;
			bus bus1;
			bus bus2;

			testCircuit.addBus(&bus0);
			testCircuit.addBus(&bus1);
			testCircuit.addBus(&bus2);

			testCircuit.addGate(&gate0);

			Assert::AreEqual(false, testCircuit.isValid());
		}
	};
}