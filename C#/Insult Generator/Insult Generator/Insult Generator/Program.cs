using System;

namespace Insult_Generator
{
    class Program
    {
        static void Main(string[] args)
        {
            int numberInsults, adjecNum;
            string victimName;
            Console.WriteLine("How many insults would you like to generate?");
            numberInsults = Console.Read();
            Console.WriteLine("What is the victim's name?");
            Console.ReadLine();
            victimName = Console.ReadLine();
            Console.WriteLine("How many adjectives should be included in the insult?");
            adjecNum = Console.Read();
             Console.WriteLine(numberInsults);
            Console.WriteLine(adjecNum);
            Console.WriteLine(victimName);
            Console.ReadKey();
        }
    }
}
