// C5.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 20201205 Jiawei Wang

#include <iostream>
#include <vector>
#include <string>

using namespace :: std;


int main()
{
    std::cout << "Hello World!\n";

    // Statement


    // 5.1 Simple statement
    // expression statement
    int ival = 0;
    ival = ival + 5;  // "Meaningless" statement 
    // (Although the addition is performed, it doesn¡¯t make much sense if it cannot be output directly or indirectly£©

    cout << ival << endl;  // "Meaningful" statement

    // null statement
    ;  // a null statement, it is used in when there needs a statament in syntax but not need in logic
    ival = ival + 3;; // an expression statement and a null statement

    // miss to write and write too much (X)
    // while (ival < 20); // null statement belongs to the while loop
    //    ival++;  // but this expression statement does not belong to the loop
    // it will be an "endless loop"

    // compound statement
    // while (ival < 20){} // end with "}", not with ";"


    // 5.2 Statement Scope


    // 5.3 Conditional Statements
    // if statement
    const vector<string> scores = { "F", "D", "C", "B", "A", "A++" };
    vector<int> marks = { 21,32,66,89,99,65,54,22,78,70,99,100,56,78,59 };
    vector<string> lettermarks(marks.size());
    string lettergrade;
    int i = 0;

    for (auto mark : marks) 
    {
        if (mark > 100) lettermarks[i] = "Undefined";
        else if (mark < 60) lettermarks[i] = scores[0];
        else 
        {
            lettermarks[i] = scores[(mark - 50) / 10];
            if (mark != 100) 
            {
                if (mark % 10 > 7)
                    lettermarks[i] += '+';
                else if (mark % 10 < 3)
                    lettermarks[i] += '-';
            }
        }
        i++;
    }

    for (auto grade : lettermarks) {
        cout << grade << " ";
    }
    // output: F F D B+ A+ D F F C+ C- A+ A++ F C+ F

    // dangling else
    // In real cases, the number of "if" and "else" are usually not equal
    // How can we find the "if" for each "else"? 
    // This problem usually called "dangling else":
    // C++ stipulates that "else" matches the nearest "if" that has not yet been matched

    // in the grade case above, there are four "if" but only two "else"
    // The actual excute way is not like the indentation format
    int g = 78;
    string lgrade = scores[(g - 50) / 10];
    if (g % 10 >= 3)
        if (g % 10 > 7)
            lgrade += '+';
    else // this else if corresponding to the latest if (line 84)
    // if you want to let this else statement correspond to line 83 statement, you can use "{}" to divide scope
        lgrade += '-';
    cout << lgrade << endl; // C+ 

    if (g % 10 <= 3) lgrade += '+'; lgrade += '-'; // C+-
    cout << lgrade << endl;


    // switch statement
    unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
    char ch;
    /*
    while (cin >> ch) 
    {
        switch (ch)
        {
            case 'a':
                ++aCnt;
                break; // interrupt the switch statement

            case 'e':
                ++eCnt;
                break;

            case 'i':
                ++iCnt;
                break;

            case 'o':
                ++oCnt;
                break;

            case 'u':
                ++uCnt;
                break;
        }
    }

    cout << "Number of vowel a: \t" << aCnt << '\n';
    cout << "Number of vowel e: \t" << eCnt << '\n';
    cout << "Number of vowel i: \t" << iCnt << '\n';
    cout << "Number of vowel o: \t" << oCnt << '\n';
    cout << "Number of vowel u: \t" << uCnt << '\n';
    */


    // case label --> must be an integer(when number) constant expression:
    int ic = 42;
    double di = 3.14;
//  switch (di), the statement inside switch must be enum or integral type
//  {
    //  case ic: must be a const value
    //      break;
    //  case 3.14:  must be a integer when number
    //      break;
    //  case cVal:
    //      break;
    //  case cval:  Error cannot be repeated
    //      break;
//  }

    // Control flow inside switch
    // notice: 
    // If a case tag matches successfully, all case branches will be executed sequentially from the tag.
    // Unless the program explicitly terminates the process, it will stop until the end of switch.


    aCnt = eCnt = iCnt = oCnt = uCnt = 0;
    char cr = 'e';
    switch (cr)
    {
    case 'a':
        ++aCnt;
    case 'e':
        ++eCnt;
    case 'i':
        ++iCnt;
    case 'o':
        ++oCnt;
    case 'u':
        ++uCnt;
    }

    cout << "aCnt: " << aCnt << '\n';
    cout << "eCnt: " << eCnt << '\n';
    cout << "iCnt: " << iCnt << '\n';
    cout << "oCnt: " << oCnt << '\n';
    cout << "uCnt: " << uCnt << '\n';

    // output: 
    // aCnt: 0
    // eCnt: 1
    // iCnt: 1
    // oCnt: 1
    // uCnt: 1

    unsigned Cnt = 0;

    /*
    // understand
    char chr;
    while (cin >> chr) {
        switch (chr)
        {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            ++Cnt;
         // break (can be ignored)
        }
    }

    cout << "Cnt: " << Cnt << endl; // count the number of vowels   
    */

    // default label
    unsigned otherCnt = 0;
    char ch1 = 'j';

    switch (ch1)
    {
    case 'a': case 'e': case 'i': case 'o': case 'u':
        ++Cnt;
    default:
        ++otherCnt;
        break;
    }

    // scope inside switch
    int ch2 = 9;
    switch (ch2)
    {
    case 9:
        int jval;  // correct because jval has not been initialized
     // string str;  error: Implict initialization 
     // int ival = 0;  error: Explicit initialization
     // the control flow may skip the case 9, (even through in this case it won't)
    default: 
        break;
    }

    // if we want to initialize a variable inside a specific case
    // using "{}" to cut the scope
    switch (ch2)
    {
    case 9: 
    {
        string str = "dhjsahdajksh";
        int ival = 0;
    }
    case 10:
    {
     // str += "dhsajd";  error: str is not defined
    }
    default:
        break;
    }

    // Exercise 5.12
    unsigned int ffCnt = 0, flCnt = 0, fiCnt = 0;
    char ch3, prech = '\0';
    cout << "Please input a text: " << endl;
    while (cin >> ch3)
    {
        bool bl = true;
        if (prech == 'f')
        {
            switch (ch3)
            {
            case 'f':
                ++ffCnt;
                bl = false;
                break;
            case 'l':
                ++flCnt;
                break;
            case 'i':
                ++fiCnt;
                break;
            default:
                break;
            }
        }
        if (!bl)
            prech = '\0';
        else
            prech = ch3;
    }

    cout << "number of ff: " << ffCnt << endl;
    cout << "number of fi: " << fiCnt << endl;
    cout << "number of fl: " << flCnt << endl;

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
