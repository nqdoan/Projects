#pragma once

#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <iomanip>
#include <http.h>

#define INVALID_SYMBOL_ERROR -1.0

#define GOOG_PRICE 100.00
#define YHOO_PRICE 85.93
#define YTBE_PRICE 256.39
#define BLCK_PRICE 198.32
#define WHTE_PRICE 356.12
#define PRPL_PRICE 85.33


using namespace std;

class stocksClass
{
public:
	static void retrieveShareInfo(string userName, vector<string> &stockSymbols, vector<int> &shares);
	static double calculateNetStock(string stockSymbol, int shares);
	static double calculateTotals(static vector<string> &stockSymbols, static vector<int> &shares, vector<double> &netStock);
	static string formattedTable(vector<string> stockSymbols, vector<int> shares, vector<double> netStock, double totalAssetValue);
	static string stocks(string username);
};

class cURL
{
public:
	static double retrieveStockPrice(string stockSymbol);

};