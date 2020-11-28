// C3-2(Exercises).cpp : This file contains the 'main' function. Program execution begins and ends there.
// 20201118 Jiawei Wang

#include <iostream>
#include <string>
using std::cin;
using std::cout; using std::endl;
using std::string;

int main()
{
    std::cout << "Hello World!\n";

    // Exercise 3.6
    string s1;
    cout << "Please input a string:" << endl;
    getline(cin, s1);
    for (auto& po : s1) // auto type is char
    {
        po = 'X';
    }
    cout << s1 << endl;

    // using while
    string s2;
    cout << "Please input a string: " << endl;
    getline(cin, s2);
    int it = 0;
    while (s2[it] != '\0' && it < s2.size()) // means null oprators
    {
        s2[it] = 'X';
        ++it;
    }
    cout << s2 << endl;

    // compare with range for:
    // In geneal, if wants to deal with every element in the range, using range for

    // Exercise 3.10
    // using range for
    string str1;
    cout << "Please input a string" << endl;
    getline(cin, str1);
    for (auto str2 : str1)
    {
        if (!ispunct(str2))
            cout << str2;
    }
    cout << endl;

    // using normal for
    string str3, result;
    cout << "Please enter a string: " << endl;
    getline(cin, str3);
    for (decltype(str3.size()) i = 0; i < str3.size(); i++)
    {
        if (!ispunct(str3[i]))
            result += str3[i];
    }
    cout << result << endl;
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
