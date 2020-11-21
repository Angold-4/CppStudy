// C2-2.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 20201121 Jiawei Wang

#include <iostream>

int wi;
int reused = 42;

int main()
{
    std::cout << "Hello World!\n";

    // string:
    std::string book("0-201-78345-X"); std::cout << book << std::endl;

    // initialization:
    // initialization vs assign
    // initialization means assign a value to a object when it is created
    // assign means delete the current value of object and assign a new value at the same time

    int unit1 = 0;
    int unit2 = { 0 };
    int unit3{ 0 };
    int unit4(0);
    // all these 4 statement can initialize object unit but also have difference:
    long double ld = 3.1415926536;
    // int a{ ld }, b = { ld }; -- using {} to initialize will cause narrow conversion error 
    int c(ld), d = ld;
    std::cout << "c = " << c << std::endl;
    std::cout << "d = " << d << std::endl;
    // output: c = 3 and d = 3
    // when not using {} to do narrow-conversion initialization, it will do lose the messages but can be succeed.

    // int un; std::cout << un; -> it will cause undefined error
    // the default initialization which means not assign value when initialization.
    // The built-in type variables inside the function body will not be initialized.
    std::cout << wi << std::endl;    // output: 0
    // But as we can see that. When a varible is initialized outside the function. It is Ok.

    
    // declare vs define
    // separate compilation -- divide a program into separated files
    // declaration made the name was knowned by the compiler
    extern int i;
    // definition helps to create the entity with the name
    int j = 10;
    // both "extern int p = 10" and this are definition, but the former cannot be used inside the function


    // scope
    int unique = 0;
    std::cout << reused << " " << unique << std::endl; // output: 42 0
    int reused = 0;
    std::cout << reused << " " << unique << std::endl; // output: 0
    // because the global scope has no name. "::reused" refer to global variable reused
    std::cout << ::reused << " " << unique << std::endl; // output: 42 0

    return 0;
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
