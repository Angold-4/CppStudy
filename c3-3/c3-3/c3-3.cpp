// c3-3.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 20201129 Jiawei Wang

#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;
using std::cin; using std::cout; using std::endl;

int main()
{
    std::cout << "Hello World!\n";

    // vector -- class template

    // template in C++
    // There are two templates - class and function template
    // We can treat template as a manual which helps compiler to generate the class we need 

    // Define a vector:
    vector<string> svec;

    vector<string> svec1(svec);  // copy value in svec to svec1
    vector<string> svec2 = svec; // same as the statement above
    // vector<int> ivec = svec;  error

    // initialize
    vector<string> articles = { "a", "an", "the" };
    vector<int> ivec(10, -1); 
    vector<string> svec3(10, "Hi!");
    // value initialized
    vector<int> ivec1(10);  // 10 elements all of them are 0 (default initialized by the compiler)
    // (int is build-in type) which means it can be initialized successfully by the compiler anytime
    vector<string> ivec2(10); // 10 elements all of them are null (defined in string) (string is class type)
    // if it is a class type which means had probability by yourself
    // if you do not define the initial value in your class type, it will not be initialized successfully

    // construct and list initialized 

    vector<int> v1(10);  // v1 has 10 elements, each of them were 0
    vector<int> v2{ 10 }; // v2 has 1 element, which is 10
    
    vector<int> v3(10, 1); // v3 has 10 elements, each of them were 1
    vector<int> v4{ 10, 1 }; // v4 has 2 elements, which is 10 and 2

    // (the main reason to causes this difference is because the 10 and 1 can be explained as integer or argument)

    // using "( )" means "construct" a vector object with arguments' value
    // using "{ }" means "list initialize a vector object
    // but this conclution just suitable in some cases, in different situations, it may be different
    vector<string> v5{ "hi" };  // v5 has 1 element, which is "hi" (list initialized)
    // vector<string> v6("hi"); error cannot using string to "construct" a string object
    vector<string> v7{ 10 };  // v7 has 10 different elements, all of them were the (default initialized) value
    vector<string> v8 = { 10, "hi" }; // v8 has 10 different elements, all of them were "hi"
  
    // conclution:
    // if using "{ }", but the value inside "{ }" are different type with the object
    // then the compiler will initialized with "construct" instead of report error

    // Add elements to vector
    vector<int> v9;
    for (int i = 0; i != 100; ++i)
        v9.push_back(i);  // push the value at the end of v9 in turn
    for (auto i1 : v9)
        cout << i1 << endl;
    // v9 has 100 elements, value from 0 to 99

    /*
    vector<string> v10;
    string word;
    while (cin >> word)
    v10.push_back(word);
    */

    vector<int> v11{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    for (auto& i2 : v11)
        i2 *= i2;
    for (auto i3 : v11)
        cout << i3 << " ";
    cout << endl;

    /*
    // application (caculation)
    vector<unsigned> scores(11, 0);
    unsigned grade;
    while (cin >> grade) {
        if (grade <= 100)
            ++scores[grade / 10];
    }
    for (auto& g : scores)
        cout << g << " ";
    cout << endl;
    */
    
    // Exercise 3.20
    vector<int> vInt;
    int iVal;
    cout << "Please input a set of number: " << endl;
    while (cin >> iVal)
        vInt.push_back(iVal);
    if (vInt.size() == 0)
    {
        cout << "No elements!" << endl;
        return -1;
    }
    cout << "The result is: " << endl;
    for (decltype(vInt.size()) i4 = 0; i4 < vInt.size(); i4++)
    {
        cout << vInt[i4] + vInt[vInt.size() - i4 - 1] << " ";
        if ((i4 + 1) % 5 == 0)
            cout << endl;
    }
    if (vInt.size() % 2 != 0)
        cout << vInt[vInt.size() / 2];

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
