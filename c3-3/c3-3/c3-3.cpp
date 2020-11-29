// c3-3.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 20201129 Jiawei Wang

#include <iostream>
#include <vector>

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
