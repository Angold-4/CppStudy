// C3-2.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 20201125 Jiawei Wang

#include <iostream>
#include <string>

using std::string;
using std::cout; using std::cin;
using std::endl;

int main()
{
    std::cout << "Hello World!\n";

    // string
    // initialization

    // 1. ways to initialize
    string s1;
    string s2(s1); // s2 is a copy of s1 (only name and addr are difference)
    string s3 = s1;
    string s4("value");
    string s5(10, 'c');

    cout << "s1 = " << s1 << endl << "s2 = " << s2 << endl
        << "s3 = " << s3 << endl << "s4 = " << s4 << endl << "s5 = " << s5 << endl;
    // output:
    // s1 =
    // s2 =
    // s3 =
    // s4 = value
    // s5 = cccccccccc

    // 2. direct and copy initialzation
    string s6 = "hiya"; // copy initialzation
    // means the compiler copy the value on the left of "=" to the object on the right of "=" directly
    string s7("hiya");  // direct initialzation
    // when the number of initial value above than 1, we need to use direct initialzation in most case
    string s8(10, 'c'); // direct initialzation

    // 3. Introduce "<<"
    string s;
    cin >> s;
    cout << s << endl; // if input is "   Hello World!   ", the output will be "Hello"
    // the "<<" oprator would ignore the blank "\n" "Tab" in the begining 
    // and start reading from the first real character until it meets the next blank

    /*
    string word;
    while (cin >> word) // object cin will automatically check the value of word baced on the type of word
        cout << word << endl;
    // if the type of word is string, means any input is legal except "Ctrl-Z" in Windows which is the "Terminator"
    
    
    int integer;
    while (cin >> integer)
    // if type is int, means any input is illegal except integer input
        cout << integer << endl;
    */

    // 4. getline
    /*
    string line;
    while (getline(cin, line))
        cout << line << endl
    */
    

    // 5. empty
    // empty is a member function in string. 
    // which return a corresponding boolean value according to whether string is empty
    string line1;
    /*
    while (getline(cin, line1))
        if (!line1.empty())
            cout << line1 << endl;
    */
    string a = "";
    string b = " ";
    string c;
    cout << "a " << a.empty() << endl << "b " << b.empty() << endl << "c " << c.empty() << endl;
    // output:
    // a 1; b 0; c 1;

    // 6. size
    /*
    string line2;
    while (getline(cin, line2))
        if (line2.size() > 80) // return the size of string
            cout << line2 << endl;
    */

    // remember the return type of size() is not unsigned, is a type called: size_type
    cout << a.size() << b.size() << c.size(); // output: 010
    string::size_type len = 9;

    // 7. compare
    // note: case sensitive and the uppercase number is smaller than lowercase
    string str = "Hello";
    string phrase = "Hello World";
    string slang = "hiya";
    string Slang = "Hiya";

    cout << (slang > Slang) << (slang > phrase) << endl;  // output: 11

    // 8. plus in string
    // 1. two string
    string s9 = "Hello, ", 
        s10 = "World!";
    s9 += s10;
    cout << s9 << endl; // Hello, World
    
    // 2. string with value(literal)
    // make sure that both sides of every "+" must have at least a string variable
    string s11 = "Hello", s12 = "World";
    string s13 = s11 + ", " + s12 + '\n'; cout << s13 << endl;
    // string s14 = "Hello" + "World";  error, both object were not string variable
    string s15 = s11 + ", " + "World"; cout << s15 << endl;  // correct from l to r
    // that is because of some historical reasons, string type in C++ is not as same as string(literal) value


    // single quote with double qoute
    // In C and in C++ single quotes identify a single character, while double quotes create a string literal. 
    // 'a' is a single a character literal, while "a" is a string literal containing an 'a' and a null terminator (that is a 2 char array).

    
    // Exercise 3.5

    // 1. connect string
    char cont = 'y';
    string s16, result;
    cout << "Please input the first string: " << endl;
    while (cin >> s16) {
        result += s16;
        cout << "Continue(y or n)?" << endl;
        cin >> cont;
        if (cont == 'y' || cont == 'Y')
            cout << "Please enter next string: " << endl;
        else
            break;
    }
    cout << "The total string is that: " << result << endl;

    // 2. blank
    char cont1 = 'y';
    string s17, result1;
    cout << "Please input the first string: " << endl;
    while (cin >> s17) {
        if (!result1.size())  // no need to have blank before the first string
            result1 += s17;
        else
            result1 = result1 + " " + s17; // after input a string, always do this
        cout << "Continue(y or n)?" << endl;
        cin >> cont1;
        if (cont1 == 'y' || cont1 == 'Y')
            cout << "Please enter next string: " << endl;
        else
            break;
    }
    cout << "The total string is that: " << result1 << endl;


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
