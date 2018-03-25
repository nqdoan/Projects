#include "stdafx.h"
#include "CppUnitTest.h"

#include "circuit.h"
#include "andGate.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Assignment4New
{
	TEST_CLASS(circuitConnectTests)
	{
	public:
		


		TEST_METHOD(connectBusIGateOInvalidGate)
		{
			andGate testGate;
			bus testBus;
			circuit testCircuit;

			testCircuit.addGate(&testGate);
			testCircuit.addBus(&testBus);

			Assert::AreEqual(false, testCircuit.connectBusIGateO(5, 0));
		}

		TEST_METHOD(connectBusIGateOInvalidBus)
		{
			andGate testGate;
			bus testBus;
			circuit testCircuit;

			testCircuit.addGate(&testGate);
			testCircuit.addBus(&testBus);

			Assert::AreEqual(false, testCircuit.connectBusIGateO(0, 5));
		}

		TEST_METHOD(connectBusIGateOInvalidSinkIndex)
		{
			andGate testGate;
			bus testBus;
			circuit testCircuit;

			testCircuit.addGate(&testGate);
			testCircuit.addBus(&testBus);

			Assert::AreEqual(false, testCircuit.connectBusIGateO(SINKINDEX, 0));
		}

		TEST_METHOD(connectBusIGateOValidSourceIndex)
		{
			andGate testGate;
			bus testBus;
			circuit testCircuit;

			testCircuit.addGate(&testGate);
			testCircuit.addBus(&testBus);

			Assert::AreEqual(true, testCircuit.connectBusIGateO(SOURCEINDEX, 0));
		}

		TEST_METHOD(connectBusIGateOValid)
		{
			andGate testGate;
			bus testBus;
			circuit testCircuit;

			testCircuit.addGate(&testGate);
			testCircuit.addBus(&testBus);

			Assert::AreEqual(true, testCircuit.connectBusIGateO(0, 0));
			Assert::AreEqual(true, testGate.getOutput() == &testBus);
			Assert::AreEqual(true, testBus.getInput() == &testGate);

		}

		TEST_METHOD(connectGateIBusOInvalidGate)
		{
			andGate testGate;
			bus testBus;
			circuit testCircuit;

			testCircuit.addGate(&testGate);
			testCircuit.addBus(&testBus);

			Assert::AreEqual(false, testCircuit.connectGateIBusO(5, 0));
		}

		TEST_METHOD(connectGateIBusOInvalidBus)
		{
			andGate testGate;
			bus testBus;
			circuit testCircuit;

			testCircuit.addGate(&testGate);
			testCircuit.addBus(&testBus);

			Assert::AreEqual(false, testCircuit.connectGateIBusO(0, 5));
		}

		TEST_METHOD(connectGateIBusOInvalidSourceIndex)
		{
			andGate testGate;
			bus testBus;
			circuit testCircuit;

			testCircuit.addGate(&testGate);
			testCircuit.addBus(&testBus);

			Assert::AreEqual(false, testCircuit.connectGateIBusO(SOURCEINDEX, 0));
		}

		TEST_METHOD(connectGateIBusOValidSinkIndex)
		{
			andGate testGate;
			bus testBus;
			circuit testCircuit;

			testCircuit.addGate(&testGate);
			testCircuit.addBus(&testBus);

			Assert::AreEqual(true, testCircuit.connectGateIBusO(SINKINDEX, 0));
		}

		TEST_METHOD(connectGateIBusOValid)
		{
			andGate testGate;
			bus testBus;
			circuit testCircuit;
			vector<gate*> expectedGates;
			vector<bus*> expectedBusses;

			expectedGates.push_back(&testGate);
			expectedBusses.push_back(&testBus);

			testCircuit.addGate(&testGate);
			testCircuit.addBus(&testBus);

			Assert::AreEqual(true, testCircuit.connectGateIBusO(0, 0));
			Assert::AreEqual(true, testGate.getInput() == expectedBusses);
			Assert::AreEqual(true, testBus.getOutput() == expectedGates);
		}

		TEST_METHOD(disconnectBusIGateOInvalidGate)
		{
			andGate testGate;
			bus testBus;
			circuit testCircuit;

			testCircuit.addGate(&testGate);
			testCircuit.addBus(&testBus);

			Assert::AreEqual(true, testCircuit.connectBusIGateO(0, 0));
			Assert::AreEqual(false, testCircuit.disconnectBusIGateO(5, 0));
		}

		TEST_METHOD(disconnectBusIGateOInvalidBus)
		{
			andGate testGate;
			bus testBus;
			circuit testCircuit;

			testCircuit.addGate(&testGate);
			testCircuit.addBus(&testBus);

			Assert::AreEqual(true, testCircuit.connectBusIGateO(0, 0));
			Assert::AreEqual(false, testCircuit.disconnectBusIGateO(0, 5));
		}

		TEST_METHOD(disconnectBusIGateOInvalidSinkIndex)
		{
			andGate testGate;
			bus testBus;
			circuit testCircuit;

			testCircuit.addGate(&testGate);
			testCircuit.addBus(&testBus);

			Assert::AreEqual(true, testCircuit.connectBusIGateO(0, 0));
			Assert::AreEqual(false, testCircuit.disconnectBusIGateO(SINKINDEX, 0));
		}

		TEST_METHOD(disconnectBusIGateOValidSourceIndex)
		{
			andGate testGate;
			bus testBus;
			circuit testCircuit;

			testCircuit.addGate(&testGate);
			testCircuit.addBus(&testBus);

			Assert::AreEqual(true, testCircuit.connectBusIGateO(SOURCEINDEX, 0));
			Assert::AreEqual(true, testCircuit.disconnectBusIGateO(SOURCEINDEX, 0));
		}

		TEST_METHOD(disconnectBusIGateOValid)
		{
			andGate testGate;
			bus testBus;
			circuit testCircuit;

			testCircuit.addGate(&testGate);
			testCircuit.addBus(&testBus);

			Assert::AreEqual(true, testCircuit.connectBusIGateO(0, 0));
			Assert::AreEqual(true, testCircuit.disconnectBusIGateO(0, 0));
			Assert::AreEqual(true, testGate.getOutput() == NULL);
			Assert::AreEqual(true, testBus.getInput() == NULL);

		}

		TEST_METHOD(disconnectGateIBusOInvalidGate)
		{
			andGate testGate;
			bus testBus;
			circuit testCircuit;

			testCircuit.addGate(&testGate);
			testCircuit.addBus(&testBus);

			Assert::AreEqual(true, testCircuit.connectGateIBusO(0, 0));
			Assert::AreEqual(false, testCircuit.disconnectGateIBusO(5, 0));
		}

		TEST_METHOD(disconnectGateIBusOInvalidBus)
		{
			andGate testGate;
			bus testBus;
			circuit testCircuit;

			testCircuit.addGate(&testGate);
			testCircuit.addBus(&testBus);

			Assert::AreEqual(true, testCircuit.connectGateIBusO(0, 0));
			Assert::AreEqual(false, testCircuit.disconnectGateIBusO(0, 5));
		}

		TEST_METHOD(disconnectGateIBusOInvalidSourceIndex)
		{
			andGate testGate;
			bus testBus;
			circuit testCircuit;

			testCircuit.addGate(&testGate);
			testCircuit.addBus(&testBus);

			Assert::AreEqual(true, testCircuit.connectGateIBusO(0, 0));
			Assert::AreEqual(false, testCircuit.disconnectGateIBusO(SOURCEINDEX, 0));
		}

		TEST_METHOD(disconnectGateIBusOValidSinkIndex)
		{
			andGate testGate;
			bus testBus;
			circuit testCircuit;

			testCircuit.addGate(&testGate);
			testCircuit.addBus(&testBus);

			Assert::AreEqual(true, testCircuit.connectGateIBusO(SINKINDEX, 0));
			Assert::AreEqual(true, testCircuit.disconnectGateIBusO(SINKINDEX, 0));
		}

		TEST_METHOD(disconnectGateIBusOValid)
		{
			andGate testGate;
			bus testBus;
			circuit testCircuit;
			vector<gate*> expectedGates;
			vector<bus*> expectedBusses;

			testCircuit.addGate(&testGate);
			testCircuit.addBus(&testBus);

			Assert::AreEqual(true, testCircuit.connectGateIBusO(0, 0));
			Assert::AreEqual(true, testCircuit.disconnectGateIBusO(0, 0));
			Assert::AreEqual(true, testGate.getInput() == expectedBusses);
			Assert::AreEqual(true, testBus.getOutput() == expectedGates);
		}
	};
}