// COSC 2320 Spring 2014 
// Name: Nguyen Doan
// Programming Assignment 4
// This is my own work; I will not post
#include "Viewer.h"
#include "Driver.h"

Viewer::Viewer(void)
{
}


Viewer::~Viewer(void)
{
}

void Choose()
{
	Driver drive;
	int input = 0;
	cout<<"Click 1 to start"<<endl;
	cout<<"Click 2 to exit"<<endl;
	cin>>input;

	if(input = 1)
	{
		drive.Open();
		drive.Encode();
		drive.Decode();
		drive.Print();
		system("PAUSE");
	}
	else if(input = 2)
	{
		system("PAUSE");
	}
}