// C7-5.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 20210107 Jiawei Wang

#include <iostream>
#include <vector>

#include "Sales_data2.h"
#include "NoDefault.h"
#include "Debug.h"
#include "Agg.h"
#include "Account.h"

using namespace::std;

double Account::interestRate = 0.002359; // must be defined at the global scope

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

    // converting consturctor
    string aBook = "978-7-121-15535-2";
    third.combine(aBook);
    // if the contructor of class only had one parameter
    // we can use converting constructor by only gave a parameter of specific type 
    // let the compiler help us to create a temporary class instance

    // but in all cases, the compiler will only help us do auto-transformation once
    // which means if we do third.combine("978-7-121-15535-2"), it will cause error
    // ("978-7-121-15535-2" -> string -> Sales_data2)

    // if you do not want to use this -- adding explicit in class:
 // explicit Sales_data2(const std::string &s) : bookNo(s)

    // for the parameters type of combine function must be const ref:
    // the reason is in the book page 55  (I also write down in Chapter2 notes (temporary variables))

    // aggregate class
    Data vall = { 2, "Jiawei", 83.3 };
 // Data vall2 = {"Jiawei" 2, 83.3};  error
 
 // constexpr Sales_data2 SSD2("9302-2"); error because Sales_data2 is not a const-expression
    constexpr Debug D(true, false, true);


    // static member of class
    Account TACT;
    TACT.rate(0.002379);
    Account ACT("Angold", 900000000.00);
    Account* ACT2 = &ACT;
    ACT.caculate();

    
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
