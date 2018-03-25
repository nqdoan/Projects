// COSC 2320 Spring 2014 
// Name: Nguyen Doan
// Programming Assignment 4
// This is my own work; I will not post
#include "Driver.h"



Driver::Driver(void)
{
}
Driver::~Driver(void)
{
}

void Driver::Open()
{
	//message File 
	ifstream messageFile;
	messageFile.open("Programming Assignment 4 Data.txt");
	while(messageFile.good())
	{
		getline(messageFile, message);
	}
	messageFile.close();
	
	
	//morseCode File
	ifstream morseFile;
	morseFile.open("Morse_Code_Text.txt");
	int x = 0;
	while(morseFile.good())
	{
		getline(morseFile, morseCode[x]);
		x++;
	}
	morseFile.close();

	
}

int Driver::Encode()
{
	control.Encode();
	return 0;
}

int Driver::Decode()
{
	control.Decode();
	return 0;
}

int Driver::Print()
{
	control.Print();
	return 0;
}
