using System;
using Interop;


class Program
{
    static void Main(string[] args)
    {
        var example = Example.New(); // Assuming Example has a public constructor

        var bytes = new byte[20];
        example.DoSomething(bytes); // Assuming DoSomething modifies the byte array in some way

        example.Dispose(); // Correct if Example implements IDisposable

        //print bytes as utf8
        Console.WriteLine(System.Text.Encoding.UTF8.GetString(bytes));
        
    }
}
