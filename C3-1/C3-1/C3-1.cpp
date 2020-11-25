// C3-1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using std::cin;
int main()
{
    std::cout << "Hello World!\n";
    // The Built-in types which is introduced in chapter 2 like number and char.
    // These reflect the capabilities of the computer hardware itself. In this chapter 
    // we want to introduce the types in standard library which is not achieved directly into computer hardware

    // using
    int i;
    cin >> i;
    // cout << i; would be error
    std::cout << i;

    // note: 
    // 1.Each using declaration introduces only a member of the namespace
    // 2.do not use "using" statement in header files, which will used in all include files and causes mistake
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
