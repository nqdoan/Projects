// COSC 2320 Spring 2014 
// Name: Nguyen Doan
// Programming Assignment 4
// This is my own work; I will not post
#pragma once
#include <iostream>
#include <fstream>
#include <istream>
#include <sstream>
#include <string>
#include <iostream>
#include "MorseCodeController.h"

using namespace std;

class Driver
{
public:
	Driver(void);
	~Driver(void);
	void Open();
	string message;
	string morseCode[100];
	int Encode();
	int Decode();
	int Print();
	MorseCodeController control;
};


