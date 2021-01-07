// C7-5.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 20210107 Jiawei Wang

#include <iostream>

#include "Sales_data2.h"
#include "NoDefault.h"

using namespace::std;

int main()
{
    std::cout << "Hello World!\n";

    // P258-259 read when review

    // delegating constructor
    // Example, let's rewrite the class (Sales_data) in C7-1
    // Test Sales_data2:
    Sales_data2 first("978-7-121-15535-2", 85, 128, 109);
    cout << "\n";
    Sales_data2 second;
    cout << "\n";
    Sales_data2 third("978-7-121-15535-2");
    cout << "\n";
    Sales_data2 fourth(cin);
    /*
    Create a Sales_data2 obj with four arguments

    Create a Sales_data2 obj with four arguments
    Create a Sales_data2 obj with no argument

    Create a Sales_data2 obj with four arguments
    Create a Sales_data2 obj with 1 argument

    Create a Sales_data2 obj with four arguments
    Create a Sales_data2 obj with no argument
    */

    C c;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
