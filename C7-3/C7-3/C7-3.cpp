// C7-3.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 20210105 Jiawei Wang

#include <iostream>
#include <string>


#include "Screen.h"
#include "Window_mgr.h"

using namespace::std;


int main()
{
    std::cout << "Hello World!\n";


    // Test Screen
    Screen myScreen(5, 5, 'X');
    cout << "myScreen1: " << endl;
    myScreen.move(4,0).set('#').display(cout);

    cout << '\n' << endl;

    const Screen myScreen2(5, 5, 'X');
    cout << "myScreen2: " << endl;
    myScreen2.display(cout);

    cout << '\n' << endl;
    // output:
//  myScreen1:
//  XXXXXXXXXXXXXXXXXXXX#XXXX

//  myScreen2 :
//  XXXXXXXXXXXXXXXXXXXXXXXXX

    Window_mgr w;
    w.clear(0);
    w.addScreen(myScreen);


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
