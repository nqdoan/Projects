#include "stdafx.h"
#include "stocks.h"
#include "CppUnitTest.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Assignment2
{
	TEST_CLASS(stockTest)
	{
	public:

		TEST_METHOD(retriveStockPriceForGOOG)
		{
			Assert::AreEqual(GOOG_PRICE, cURL::retrieveStockPrice("GOOG"), .009);
		}

		TEST_METHOD(retriveStockPriceForYHOO)
		{
			Assert::AreEqual(YHOO_PRICE, cURL::retrieveStockPrice("YHOO"), .009);
		}

		TEST_METHOD(retriveStockPriceForYTBE)
		{
			Assert::AreEqual(YTBE_PRICE, cURL::retrieveStockPrice("YTBE"), .009);
		}

		TEST_METHOD(retriveStockPriceForBLCK)
		{
			Assert::AreEqual(BLCK_PRICE, cURL::retrieveStockPrice("BLCK"), .009);
		}

		TEST_METHOD(retriveStockPriceForWHTE)
		{
			Assert::AreEqual(WHTE_PRICE, cURL::retrieveStockPrice("WHTE"), .009);
		}

		TEST_METHOD(retriveStockPriceForPRPL)
		{
			Assert::AreEqual(PRPL_PRICE, cURL::retrieveStockPrice("PRPL"), .009);
		}

		TEST_METHOD(retriveStockPriceForInvalidSymbol)
		{
			Assert::AreEqual(INVALID_SYMBOL_ERROR, cURL::retrieveStockPrice("INVAL"), .009);
		}

		TEST_METHOD(NetAssetValueTestForGOOG_1000Shares)
		{
			Assert::AreEqual(GOOG_PRICE * 1000, stocksClass::calculateNetStock("GOOG", 1000));
		}

		TEST_METHOD(NetAssetValueTestForYHOO_1000Shares)
		{
			Assert::AreEqual(YHOO_PRICE * 1000, stocksClass::calculateNetStock("YHOO", 1000));
		}

		TEST_METHOD(NetAssetValueTestForYTBE_1000Shares)
		{
			Assert::AreEqual(YTBE_PRICE * 1000, stocksClass::calculateNetStock("YTBE", 1000));
		}

		TEST_METHOD(NetAssetValueTestForBLCK_1000Shares)
		{
			Assert::AreEqual(BLCK_PRICE * 1000, stocksClass::calculateNetStock("BLCK", 1000));
		}

		TEST_METHOD(NetAssetValueTestForWHTE_1000Shares)
		{
			Assert::AreEqual(WHTE_PRICE * 1000, stocksClass::calculateNetStock("WHTE", 1000));
		}

		TEST_METHOD(NetAssetValueTestForPRPL_1000Shares)
		{
			Assert::AreEqual(PRPL_PRICE * 1000, stocksClass::calculateNetStock("PRPL", 1000));
		}

		TEST_METHOD(NetAssetValueTestForInvalid_1000Shares)
		{
			Assert::AreEqual(INVALID_SYMBOL_ERROR, stocksClass::calculateNetStock("INVAL", 1000));
		}

		TEST_METHOD(NetAssetValueTestForGOOG_20000Shares)
		{
			Assert::AreEqual(2000000.00, stocksClass::calculateNetStock("GOOG", 20000));
		}

		TEST_METHOD(User1SharesRetrievalTest)
		{
			vector<int> expectedShares;
			vector<int> actualShares;
			vector<string> expectedSymbols;
			vector<string> actualSymbols;
			expectedShares.push_back(1000);
			expectedSymbols.push_back("GOOG");


			stocksClass::retrieveShareInfo("user1", actualSymbols, actualShares);

			bool compare = false;

			if (actualSymbols == expectedSymbols)
			{
				if (actualShares == expectedShares)
				{
					compare = true;
				}
			}
			Assert::AreEqual(true, compare);
		}

		TEST_METHOD(User2SharesRetrievalTest)
		{
			vector<int> expectedShares;
			vector<int> actualShares;
			vector<string> expectedSymbols;
			vector<string> actualSymbols;

			expectedShares.push_back(2000);
			expectedShares.push_back(3000);

			expectedSymbols.push_back("YHOO");
			expectedSymbols.push_back("YTBE");

			stocksClass::retrieveShareInfo("user2", actualSymbols, actualShares);

			bool compare = false;

			if (actualSymbols == expectedSymbols)
			{
				if (actualShares == expectedShares)
				{
					compare = true;
				}
			}
			Assert::AreEqual(true, compare);
		}

		TEST_METHOD(User3SharesRetrievalTest)
		{
			vector<int> expectedShares;
			vector<int> actualShares;
			vector<string> expectedSymbols;
			vector<string> actualSymbols;

			expectedShares.push_back(400);
			expectedShares.push_back(30000);
			expectedShares.push_back(50);

			expectedSymbols.push_back("BLCK");
			expectedSymbols.push_back("WHTE");
			expectedSymbols.push_back("PRPL");

			stocksClass::retrieveShareInfo("user3", actualSymbols, actualShares);

			bool compare = false;

			if (actualSymbols == expectedSymbols)
			{
				if (actualShares == expectedShares)
				{
					compare = true;
				}
			}
			Assert::AreEqual(true, compare);
		}

		TEST_METHOD(User4SharesRetrievalTest)
		{
			vector<int> expectedShares;
			vector<int> actualShares;
			vector<string> expectedSymbols;
			vector<string> actualSymbols;

			expectedShares.push_back(100);
			expectedShares.push_back(200);
			expectedShares.push_back(300);

			expectedSymbols.push_back("GOOG");
			expectedSymbols.push_back("YHOO");
			expectedSymbols.push_back("TSLA");

			stocksClass::retrieveShareInfo("user4", actualSymbols, actualShares);

			bool compare = false;

			if (actualSymbols == expectedSymbols)
			{
				if (actualShares == expectedShares)
				{
					compare = true;
				}
			}
			Assert::AreEqual(true, compare);
		}

		TEST_METHOD(InvalidUserSharesRetrievalTest)
		{
			vector<int> expectedShares;
			vector<string> expectedSymbols;
			vector<int> actualShares;
			vector<string> actualSymbols;

			stocksClass::retrieveShareInfo("invalidUser", actualSymbols, actualShares);

			bool compare = false;

			if (actualSymbols == expectedSymbols)
			{
				if (actualShares == expectedShares)
				{
					compare = true;
				}
			}

			Assert::AreEqual(true, compare);
		}

		TEST_METHOD(calculateNetStockForUser1)
		{
			vector<int> actualShares;
			vector<string> actualSymbols;
			vector<double> actualNet;

			stocksClass::retrieveShareInfo("User1", actualSymbols, actualShares);

			Assert::AreEqual(GOOG_PRICE * 1000, stocksClass::calculateTotals(actualSymbols, actualShares, actualNet));
		}

		TEST_METHOD(calculateNetStockForUser2)
		{
			vector<int> actualShares;
			vector<string> actualSymbols;
			vector<double> actualNet;

			stocksClass::retrieveShareInfo("User2", actualSymbols, actualShares);

			Assert::AreEqual(YHOO_PRICE * 2000 + YTBE_PRICE * 3000, stocksClass::calculateTotals(actualSymbols, actualShares, actualNet));
		}

		TEST_METHOD(calculateNetStockForUser3)
		{
			vector<int> actualShares;
			vector<string> actualSymbols;
			vector<double> actualNet;

			stocksClass::retrieveShareInfo("User3", actualSymbols, actualShares);

			Assert::AreEqual(BLCK_PRICE * 400 + WHTE_PRICE * 30000 + PRPL_PRICE * 50, stocksClass::calculateTotals(actualSymbols, actualShares, actualNet));
		}

		TEST_METHOD(calculateNetStockForUser4)
		{
			vector<int> actualShares;
			vector<string> actualSymbols;
			vector<double> actualNet;

			stocksClass::retrieveShareInfo("User4", actualSymbols, actualShares);

			Assert::AreEqual((GOOG_PRICE * 100) + (YHOO_PRICE * 200), stocksClass::calculateTotals(actualSymbols, actualShares, actualNet));
		}

		TEST_METHOD(retriveFormattedTableForUser1)
		{
			vector<string> stockSymbols;
			vector<int> shares;
			vector<double> netStock;
			stocksClass::retrieveShareInfo("user1", stockSymbols, shares);
			double totalAssetValue = stocksClass::calculateTotals(stockSymbols, shares, netStock);

			string actualTable = stocksClass::formattedTable(stockSymbols, shares, netStock, totalAssetValue);

			stringstream expectedTable; 
			expectedTable  << setw(10) << "Symbol" << (char)179 << setw(10) << "Shares" << (char)179 << setw(15) << "Asset Value" << "\n"
							<< setw(11) << setfill((char)196) << (char)197 << setw(11) << (char)197 << setw(16) << "\n" << setfill(' ')
							<< setw(10) << "GOOG" << (char)179 << setw(10) << 1000 << (char)179 << setw(15) << setprecision(2) << fixed << GOOG_PRICE * 1000 << "\n"
							<< setw(12) << " " << setw(10) << "Totals" << setw(15) << GOOG_PRICE * 1000 << endl; 

			Assert::AreEqual(expectedTable.str(), actualTable);
		}

		TEST_METHOD(retriveFormattedTableForUser2)
		{
			vector<string> stockSymbols;
			vector<int> shares;
			vector<double> netStock;
			stocksClass::retrieveShareInfo("user2", stockSymbols, shares);
			double totalAssetValue = stocksClass::calculateTotals(stockSymbols, shares, netStock);

			string actualTable = stocksClass::formattedTable(stockSymbols, shares, netStock, totalAssetValue);

			stringstream expectedTable; 
			expectedTable  << setw(10) << "Symbol" << (char)179 << setw(10) << "Shares" << (char)179 << setw(15) << "Asset Value" << "\n"
							<< setw(11) << setfill((char)196) << (char)197 << setw(11) << (char)197 << setw(16) << "\n" << setfill(' ')
							<< setw(10) << "YHOO" << (char)179 << setw(10) << 2000 << (char)179 << setw(15) << setprecision(2) << fixed << YHOO_PRICE * 2000 << "\n"
							<< setw(10) << "YTBE" << (char)179 << setw(10) << 3000 << (char)179 << setw(15) << setprecision(2) << fixed << YTBE_PRICE * 3000 << "\n"
							<< setw(12) << " " << setw(10) << "Totals" << setw(15) << YHOO_PRICE * 2000 + YTBE_PRICE * 3000 << endl; 

			Assert::AreEqual(expectedTable.str(), actualTable);
		}

		TEST_METHOD(retriveFormattedTableForUser3)
		{
			vector<string> stockSymbols;
			vector<int> shares;
			vector<double> netStock;
			stocksClass::retrieveShareInfo("user3", stockSymbols, shares);
			double totalAssetValue = stocksClass::calculateTotals(stockSymbols, shares, netStock);

			string actualTable = stocksClass::formattedTable(stockSymbols, shares, netStock, totalAssetValue);

			stringstream expectedTable; 
			expectedTable  << setw(10) << "Symbol" << (char)179 << setw(10) << "Shares" << (char)179 << setw(15) << "Asset Value" << "\n"
							<< setw(11) << setfill((char)196) << (char)197 << setw(11) << (char)197 << setw(16) << "\n" << setfill(' ')
							<< setw(10) << "BLCK" << (char)179 << setw(10) << 400 << (char)179 << setw(15) << setprecision(2) << fixed << BLCK_PRICE * 400 << "\n"
							<< setw(10) << "WHTE" << (char)179 << setw(10) << 30000 << (char)179 << setw(15) << setprecision(2) << fixed << WHTE_PRICE * 30000 << "\n"
							<< setw(10) << "PRPL" << (char)179 << setw(10) << 50 << (char)179 << setw(15) << setprecision(2) << fixed << PRPL_PRICE * 50 << "\n"
							<< setw(12) << " " << setw(10) << "Totals" << setw(15) << BLCK_PRICE * 400 + WHTE_PRICE * 30000 + PRPL_PRICE * 50 << endl; 

			Assert::AreEqual(expectedTable.str(), actualTable);
		}

		TEST_METHOD(retriveFormattedTableForUser4)
		{
			vector<string> stockSymbols;
			vector<int> shares;
			vector<double> netStock;
			stocksClass::retrieveShareInfo("user4", stockSymbols, shares);
			double totalAssetValue = stocksClass::calculateTotals(stockSymbols, shares, netStock);

			string actualTable = stocksClass::formattedTable(stockSymbols, shares, netStock, totalAssetValue);

			stringstream expectedTable; 
			expectedTable  << setw(10) << "Symbol" << (char)179 << setw(10) << "Shares" << (char)179 << setw(15) << "Asset Value" << "\n"
							<< setw(11) << setfill((char)196) << (char)197 << setw(11) << (char)197 << setw(16) << "\n" << setfill(' ')
							<< setw(10) << "GOOG" << (char)179 << setw(10) << 100 << (char)179 << setw(15) << setprecision(2) << fixed << GOOG_PRICE * 100 << "\n"
							<< setw(10) << "YHOO" << (char)179 << setw(10) << 200 << (char)179 << setw(15) << setprecision(2) << fixed << YHOO_PRICE * 200 << "\n"
							<< setw(12) << " " << setw(10) << "Totals" << setw(15) << GOOG_PRICE * 100 + YHOO_PRICE * 200 << endl
							<< "\nInvalid Symbols\n" << setw(20) << setfill(char(196)) << "\n" << setfill(' ')
							<< setw(6) << left << "TSLA" << right << "Symbol is Invalid\n";


			Assert::AreEqual(expectedTable.str(), actualTable);
		}

		TEST_METHOD(StocksTestForInvalidUser)
		{
			string actualStocks = stocksClass::stocks("INVAL");

			string expectedStocks = "User file does not exist.";

			Assert::AreEqual(expectedStocks, actualStocks);
		}

		TEST_METHOD(StocksTestForUser1)
		{
			string actualStocks = stocksClass::stocks("user1");

			vector<string> stockSymbols;
			vector<int> shares;
			vector<double> netStock;
			stocksClass::retrieveShareInfo("user1", stockSymbols, shares);
			double totalAssetValue = stocksClass::calculateTotals(stockSymbols, shares, netStock);

			string expectedStocks = stocksClass::formattedTable(stockSymbols, shares, netStock, totalAssetValue);

			Assert::AreEqual(expectedStocks, actualStocks);
		}

		TEST_METHOD(StocksTestForUser2)
		{
			string actualStocks = stocksClass::stocks("user2");

			vector<string> stockSymbols;
			vector<int> shares;
			vector<double> netStock;
			stocksClass::retrieveShareInfo("user2", stockSymbols, shares);
			double totalAssetValue = stocksClass::calculateTotals(stockSymbols, shares, netStock);

			string expectedStocks = stocksClass::formattedTable(stockSymbols, shares, netStock, totalAssetValue);

			Assert::AreEqual(expectedStocks, actualStocks);
		}

		TEST_METHOD(StocksTestForUser3)
		{
			string actualStocks = stocksClass::stocks("user3");

			vector<string> stockSymbols;
			vector<int> shares;
			vector<double> netStock;
			stocksClass::retrieveShareInfo("user3", stockSymbols, shares);
			double totalAssetValue = stocksClass::calculateTotals(stockSymbols, shares, netStock);

			string expectedStocks = stocksClass::formattedTable(stockSymbols, shares, netStock, totalAssetValue);

			Assert::AreEqual(expectedStocks, actualStocks);
		}

		TEST_METHOD(StocksTestForUser4)
		{
			string actualStocks = stocksClass::stocks("user4");

			vector<string> stockSymbols;
			vector<int> shares;
			vector<double> netStock;
			stocksClass::retrieveShareInfo("user4", stockSymbols, shares);
			double totalAssetValue = stocksClass::calculateTotals(stockSymbols, shares, netStock);

			string expectedStocks = stocksClass::formattedTable(stockSymbols, shares, netStock, totalAssetValue);

			Assert::AreEqual(expectedStocks, actualStocks);
		}
	};
}