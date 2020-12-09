// C6-1.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 20201209 Jiawei Wang

#include <iostream>
#include <string>
#include <vector>
#include "C6.h"

using namespace :: std;

// first function:
int fact(int val) // val is called the "parameter"
{
    int ret = 1;
    while (val > 1)
        ret *= val--;
    return ret;
}

// automatic object and local static object
size_t as()
{
    size_t ctr = 0;
    static size_t sctr = 0; // create a local static object 
    // (it will automatically ignored by the compiler after the first call)
    // because it will not be destroied, no need to be initialized again

    return sctr++;
}
int main()
{
    std::cout << "Hello World!\n";
    // functions
    // fact() (line 11)
    int f = fact(5);  // the 5 inside call operator "()" is called argument
    cout << "fact(5): 5! is: " << f << endl;  // fact(5): 5! is: 120

    // Whenever using call oprator to call a function, the calling function do two things:
    // 1. using argument which inside () to initilaze the parameter
    // 2. make the control flow to the called function
    // which makes the calling function is interrupt temporately and the called function start

    // notice: no matter how long the function is: it must have "{}"
    // double td(double d1)
    //     return d1 * d1;  wrong experssion

    // automatic object and local static object
    // Please check function as() in line 20
    as(); as(); as(); as();
    size_t s = as(); cout << "call as() times: " << s + 1 << endl;



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
