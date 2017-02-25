
#include "stdafx.h"
#include "stocks.h"

void stocksClass::retrieveShareInfo(string userName, vector<string> &stockSymbols, vector<int> &shares)
{
	ifstream assetsFile(userName + "StockFile.txt");
	if (assetsFile.is_open())
	{
		string symbol;
		int share;
		while (!assetsFile.eof())
		{
			assetsFile >> symbol >> share;
			stockSymbols.push_back(symbol);
			shares.push_back(share);
		}
		assetsFile.close();
	}

	return;
}

double stocksClass::calculateNetStock(string stockSymbol, int shares)
{
	double share_price = cURL::retrieveStockPrice(stockSymbol);

	if (share_price == INVALID_SYMBOL_ERROR)
		return INVALID_SYMBOL_ERROR;

	return shares*share_price;
}

double stocksClass::calculateTotals(static vector<string> &stockSymbols, static vector<int> &shares, vector<double> &netStock)
{
	double totalAssetValue = 0.0;
	int size = (int)stockSymbols.size();

	for (int c = 0; c < size; c++)
	{
		netStock.push_back(calculateNetStock(stockSymbols[c], shares[c]));
		if (netStock[c] != INVALID_SYMBOL_ERROR)
			totalAssetValue += netStock[c];
	}

	return totalAssetValue;
}

string stocksClass::stocks(string username)
{
	vector<string> stockSymbols;
	vector<int> shares;
	vector<double> netStock;

	retrieveShareInfo(username, stockSymbols, shares);
	if(stockSymbols.empty())
		return "User file does not exist.";

	double totalAssetValue = calculateTotals(stockSymbols, shares, netStock);

	return formattedTable(stockSymbols, shares, netStock, totalAssetValue);
}


string stocksClass::formattedTable(vector<string> stockSymbols, vector<int> shares, vector<double> netStock, double totalAssetValue)
{
	vector<int> invalidSymbols;

	stringstream formattedTable;

	formattedTable  << setw(10) << "Symbol" << (char)179 << setw(10) << "Shares" << (char)179 << setw(15) << "Asset Value" << "\n"
					<< setw(11) << setfill((char)196) << (char)197 << setw(11) << (char)197 << setw(16) << "\n" << setfill(' ');

	for (int c = 0; c < (int)stockSymbols.size(); c++)
	{
		if (netStock[c] == INVALID_SYMBOL_ERROR)
			invalidSymbols.push_back(c);
		else
			formattedTable  << setw(10) << stockSymbols[c] << (char)179 << setw(10) << shares[c] << (char)179 << setw(15) << setprecision(2) << fixed << netStock[c] << "\n";
	}
	
	formattedTable  << setw(12) << " " << setw(10) << "Totals" << setw(15) << totalAssetValue << endl; 

	if (!invalidSymbols.empty())
	{
		formattedTable << "\nInvalid Symbols\n" << setw(20) << setfill(char(196)) << "\n" << setfill(' ');
		for (int c = 0; c < (int)invalidSymbols.size(); c++)
		{
			formattedTable << setw(6) << left << stockSymbols[invalidSymbols[c]] << right;
			if (netStock[invalidSymbols[c]] == INVALID_SYMBOL_ERROR)
				formattedTable << "Symbol is Invalid\n";
		}
	}

	return formattedTable.str();
}

double cURL::retrieveStockPrice(string stockSymbol)
{
	if (stockSymbol == "GOOG")
		return GOOG_PRICE;
	else if (stockSymbol == "YHOO")
		return YHOO_PRICE;
	else if (stockSymbol == "YTBE")
		return YTBE_PRICE;
	else if (stockSymbol == "BLCK")
		return BLCK_PRICE;
	else if (stockSymbol == "WHTE")
		return WHTE_PRICE;
	else if (stockSymbol == "PRPL")
		return PRPL_PRICE;
	else
		return INVALID_SYMBOL_ERROR;
}