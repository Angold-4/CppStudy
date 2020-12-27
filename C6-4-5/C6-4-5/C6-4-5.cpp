// C6-4-5.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 20201226

#include <iostream>
#include <vector>
#include <string>

#include "Header.h"

using namespace::std;

// 6.4 overload functions
// overload x different scope
void print(const string& s)
{
    cout << s << endl;
}

// function in function
void print(double d)
{
    void print(double d);
    // we cannot define a function in function that can do many things
    // print("Jiawei Wang");  error, it cannot be overloaded inside the scope
    
}

// overload functions in the same scope
void ppprint(int i)
{
    double a = 324.3;
    print(a);
    print("This is C++1!!");
}

// 6.5 specical tech in functions

char defg = ' ';

int main()
{
    std::cout << "Hello World!\n";

    // 6.4 overload function

    // notice: we cannot define two functions with the same parameter but different return type

    // The compiler infers which function is used by inferring the type of the parameter

    // The following function declaration were the same
    int calc(int);
    int calc(const int);
    // because the top-level const won't affect the type of parameter
    // when call calc(), the compiler will report error

    int calc1(int*);
    int calc1(const int*);
    // the low-level const will be reserved so these two calc1() functions were overload functions

    // in different scope, we cannot define overload functions
    // see line 11, we define a function print(const string&)
    // in line 17, we define another function dprint(double) and define another print function in it
    // but in lind 26, we can see that the overload function can be used in different scopes when they are in the same scope

    // 6.5 special tech in functions

    /*
    // default arguments
    typedef string::size_type sz;
    string screen(sz ht = 24, sz wid = 80, char backgrnd = ' ');
    string window;
    window = screen();
    window = screen(66);
    window = screen(66, 256);
    window = screen(66, 256, '#');
    // window = screen(, , '#'); error, if you want to cover the value of backgrnd, you must give the arguments to ht and wid
    window = screen('?',80,' '); this is a right expression. because char '?' will be transformed into 63 (ASCII)
    */
    
    string ht();
    char def = ' ';
    // string testscreen(int p = 23, string s = ht(), char c = def; error: local variable (def) cannot be as default parameter
    // but local expression like ht() can be used as dafault parameter
    string testscreen(int p = 23, string s = ht(), char c = defg); 
    // This would be right, because the defg is defined outside the function
    
    // inline function:
    // in Header.h, we define an inline function, which will help the compiler do things faster.
    // for example:
    string s1 = "Wswange";
    string s2 = "Jiawei Wang";
    cout << shorterString(s1, s2) << endl; // output: Wswange
    // the affect is like:
 // cout << (s1.size() < s2.size() ? s1 : s2;
    // the inline function is often used in small size function, and usually not supporte recursion

    // NDEBUG

    const int ary[3] = { 1,2,3 };
    size_t sze = 4;
    printNDE(ary, sze);
    // if the enviroment is release, it won't be print

    printCST();
    // Error: C:\Users\ThinkPad\source\repos\CppStudy\C6-4 -5\C6-4-5\Header.h : in function printCST at line 21
    //        Compiled on Dec 27 2020 at 23:39:10
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
