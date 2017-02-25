// COSC 2320 Spring 2014
// Name: Nguyen Doan
// Programming Assignment 3
// This is my own work; I will not post

package programmingassignment3java;


import java.io.IOException;
import java.io.FileInputStream;
import java.util.Scanner;



public class Controller
{
    int STRLEN = 10;
    Scanner scan = new Scanner(System.in);
    String[] information = new String[STRLEN];

    void addOrChangeEntry() throws IOException
    {
        AddNewEntry adder = new AddNewEntry();
        adder.add();
    }

    void lookupEntry() throws NullPointerException
    {
        String firstName;
        System.out.println("Input the first name of who you are looking for:");
        firstName = scan.nextLine();

        for(int x = 0;x<information.length;x++)
        {
            if (information[x].contains(firstName));
            {
                System.out.println(information[x]);
            }
        }
    
    }

    void removeEntry() throws NullPointerException
    {
        String firstName;
        boolean found = false;
        System.out.println("Input the first name of who you want to remove:");
        firstName = scan.nextLine();

        for(int x = 0;x<information.length;x++)
        {
            found = information[x].contains(firstName);
            if (found = true);
            {
                information[x] = null;
            }
        }


    }

    void display() throws IOException
    {
    Scanner input = new Scanner(new FileInputStream("Programming Assignment 3 Data.txt"));

    while(input.hasNext() == true)
    {
        for(int i = 0; i<information.length;i++)
        {
            information[i] = input.nextLine();
            System.out.println(information[i]);
        }
    }
    input.close();
    }

}
