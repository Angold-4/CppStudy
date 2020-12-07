// C5-5.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 20201206 Jiawei Wang

#include <iostream>
#include <string>
#include <vector>

using namespace :: std;

int main()
{
    std::cout << "Hello World!\n";

    // Chapter 5.4: Interative statement
    // while loop
    // Using while loop: 
    // 1. not sure the interation time
    // 2. we want to use the variables which in the conditional statement

    // Exercise 5.14
    string currString, preString = "", maxString;
    int currCnt = 1, maxCnt = 0;
    /*
    while (cin >> currString)
    {
        if (currString == preString)
        {
            ++currCnt;
            if (currCnt > maxCnt)
            {
                maxCnt = currCnt;
                maxString = currString;
            }
        }
        // if not, reset currCnt
        else
        {
            currCnt = 1;
        }
        preString = currString;
    }
    if (maxCnt > 1)
    {
        cout << "The string which appears most is : " << maxString << endl;
        cout << "Which appearss: " << maxCnt << " times" << endl;
    }
    else
        cout << "No repeat string" << endl;
    */
    // for statement

    // format:
    // for (initializer; condition; expression)
    //    statement;
    // 1. initializer can define multiple objects, but need to be the same type
    // that is because a for statement only can have one init-statement
    for (decltype(currString.size()) i = 0, sz = currString.size(); i != sz; ++i) break;
    // 2. omit some parts 
    // you can ignore any or multiple part(s), in different circumstances
    // ignore condition --> condition always be true --> the statement inside the for-loop helps to terminate the cycle
    // ignore expression --> add statement inside the for-loop to terminate the cycle
    /*
    for (int i; cin >> i;) break; 
    */
    // in this statement, the cin helps both change i and check i, so we do not need to add any statement inside the loop

    // in most cases, we can transfer "for-loop" into "while-loop", but if only one statement can be used
    // I think "for-loop" is better, because using ""for-loop" made the control-flow clear

    // range for
    // format:
    // for (declaration : expression)
    //     statement;
    // notice: expression must be a sequence (vector, array, string.etc)
    // which can return a iterator (end() and begin() member)
    // we cannot use range for to add/delete elements in these container 
    // In the rf statement, the value of e is prestored. 
    // Once an element is added to the sequence, the value of e may become invalid.

    // Exercise 5.17
    vector<int> v1{ 1,2,3,4,5,6,7 };
    vector<int> v2{ 1,2,3,5,6 };
    vector<int> v3{ 1,2,3,4,5 };

    auto it1 = v1.cbegin();
    auto it3 = v3.cbegin();

    // i1 and i3
    while (it1 != v1.cend() && it3 != v3.cend())
    {
        if (*it1 != *it3)
        {
            cout << "No prefix relationship between it1 and it3" << endl;
            break;
        }
        it1++;
        it3++;
    }
    if (it1 == v1.cend()) {
        cout << "v1 is a prefix of v3" << endl;
    }
    if (it3 == v3.cend()) {
        cout << "v3 is a prefix of v1" << endl;
    }

    // v3 is a prefix of v1


    // do-while
    // difference between "while" and "do-while"
    // 1. do-while at least do once, before check the condition
    // 2. condition cannot be null in "do-while", and cannot define a variable in condition
    // notice: the variable in condition must be defined outside the loop
    int ival = 0;
    do {
        ival++;  // cannot be int ival = 0; ival++; and without line 82
    } while (ival == 9);


    // jump statement (break continue goto return)
    // break -- terminating the nearest while, do while, for of switch, and continue after the end of these statements
    // only inside iteration or switch statements can use break

    // continue -- terminating the current iteration but continue the loop (also nearest)
    /*
    string buf;
    while (cin >> buf && !buf.empty()) {
        if (buf[0] != '_')
            continue;
        // we only need to deal with the string with begin '_'
        // deal with
    }
    */

    // goto statement
    // labeled statement:
begin:
    int sz = 3;
    if (sz <= 0) {
        goto begin;
    }

    // try-catch statement
    // In real situations: we usually write User-iteraction code and Function code separatly
    int item1, item2;

    while (cin >> item1 >> item2)
    {
        try {
            if (item1 != item2)
                throw runtime_error("Data must refer to the same!");
            cout << item1 + item2 << endl;
        }
        catch (runtime_error err) {
            cout << err.what()  // runtime_error.what() member function return the string when initialized the object
                << "\nTry again? Enter y or n" << endl;
            char c;
            cin >> c;
            if (!cin || c == 'n')
                break;
        }
    }
    // when error:
    // Data must refer to the same!
    // Try again ? Enter y or n

    float i1, i2;

    while (cin >> i1 >> i2) {
        try {

            if (i2 == 0)
                throw runtime_error("zero division error!!");
            cout << i1 / i2 << endl;
        }
        catch (runtime_error e) {
            cout << e.what()
                << "\nagain? (y or n)";
            char c1;
            cin >> c1;
            if (!cin || c1 == 'n')
                break; // jump out of while loop
        }
    }
    // when i2 == 0, it will output "inf"


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
