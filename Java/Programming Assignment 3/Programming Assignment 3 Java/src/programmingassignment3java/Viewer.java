// COSC 2320 Spring 2014
// Name: Nguyen Doan
// Programming Assignment 3
// This is my own work; I will not post

package programmingassignment3java;

import java.io.IOException;

public class Viewer
{
    void callMenu() throws IOException
    {
        ContactInterface intfac = new ContactInterface();
        intfac.Menu();
    }
}
