// COSC 2320 Spring 2014
// Name: Nguyen Doan
// Programming Assignment 3
// This is my own work; I will not post

package programmingassignment3java;

import java.io.IOException;
import java.util.Scanner;

public class ContactInterface
{


    void Menu() throws IOException
    {
        int userinput=0;
        Controller control = new Controller();
        Scanner scan = new Scanner(System.in);
        do
        {
        System.out.println("------------------------ContactList------------------------");
        System.out.println("Please choose what you would like to do:");
        System.out.println("1. Add or Change Entry");
        System.out.println("2. Look Up Entry");
        System.out.println("3. Remove Entry");
        System.out.println("4. Display Contact List");
        System.out.println("5. Save and exit Contact List");
        userinput = scan.nextInt();
            switch(userinput)
            {
                case 1:
                    control.addOrChangeEntry();
                    break;
                case 2:
                    control.lookupEntry();
                    break;
                case 3:
                    control.removeEntry();
                    break;
                case 4:
                    control.display();
                    break;
            }
        }
        while(userinput != 5);
    }
}
