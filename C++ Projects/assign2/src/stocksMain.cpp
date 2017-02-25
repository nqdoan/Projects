 
#include "stdafx.h"
#include "stocks.h"

#include <iostream>

using namespace std;

int main()
{

	cout << "Please enter a user name " << endl;
	string username;
	bool finished = false; 
	while(!finished)
	{
		cin >> username;
		cout << stocksClass::stocks(username) << endl << endl << "Would you like to try another username? (Y/N)" << endl;
		cin >> username;
		if(username == "N" || username == "No") 
			finished = true; 
	}
	return 0;
}