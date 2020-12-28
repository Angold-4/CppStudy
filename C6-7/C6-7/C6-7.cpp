// C6-7.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 20201228 Jiawei Wang

#include <iostream>
#include <string>

#include "Header.h"

using namespace::std;

bool lengthCompare(const string& c1, const string& c2)
{
    cout << c1 << " " << c2 << endl;
    return true;
    
}

void inLengthCompare(const string& c1, const string& c2, bool (*pf)(const string& c1, const string& c2))
{
    pf(c1, c2);
#ifndef NDEBUG
    cerr << "You are now using pointer function! in " << __func__ << "() , line: " << __LINE__ << endl;
#endif
}

int add(int a, int b)
{
    return a + b;
}

int minus(int a, int b)
{
    return a - b;
}int multiply(int a, int b)
{
    return a * b;
}int divi(int a, int b)
{
    return a / b;
}

void compute(int a, int b, int(*pf)(int, int))
{
    cout << pf(a, b) << endl;
}

int main()
{
    std::cout << "Hello World!\n";

    // C6.7 function pointer
    bool(*pf)(const string&, const string&);
    pf = lengthCompare;
    pf = &lengthCompare; // both are ok

    // the following 3 statements are the same
    bool b1 = pf("Hello", "Goodbye");
    bool b2 = (*pf)("Hello", "Goodbye");
    bool b3 = lengthCompare("Hello", "Goodbye");

    // the lengthCompare will automatically transformed into pointer
    inLengthCompare("World", "Hello", lengthCompare);
    
    compute(2, 3, add);
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
