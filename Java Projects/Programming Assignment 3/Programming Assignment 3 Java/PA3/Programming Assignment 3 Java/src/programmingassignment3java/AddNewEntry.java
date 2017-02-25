// COSC 2320 Spring 2014
// Name: Nguyen Doan
// Programming Assignment 3
// This is my own work; I will not post

package programmingassignment3java;
import java.io.BufferedWriter;
import java.io.File;
import java.io.IOException;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.Writer;
import java.util.Scanner;


public class AddNewEntry
{

    void add() throws IOException
    {
        String name, phonenumber1, phonenumber2, full;
        Scanner scan = new Scanner(System.in);

        System.out.println("What is the new person's name?");
        name = scan.nextLine();
        System.out.println("What is the new person's first phone number?");
        phonenumber1 = scan.nextLine();
        System.out.println("What is the new person's second phone number?");
        phonenumber2 = scan.nextLine();


        FileWriter fileWriter = new FileWriter("Programming Assignment 3 Data.txt", true);
        BufferedWriter write = new BufferedWriter(fileWriter);
        write.write(name + ": " + phonenumber1 + " " + phonenumber2);
        write.close();

        Scanner in = new Scanner(new FileInputStream("Programming Assignment 3 Data.txt"));
        while(in.hasNextLine() == true)
        {
            System.out.println(in.nextLine());
        }

    }
}
