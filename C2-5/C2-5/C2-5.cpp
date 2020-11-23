// C2-5.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 20201123 Jiawei Wang

#include <iostream>

int main()
{
    std::cout << "Hello World!\n";

    // type alias
    // 1. use typedef to make alias
    typedef double wages;  // wages is a alias of double
    typedef wages base, * p;  // use it, base is same as double, and p is same as double*

    // 2. use using to make alias (C++11 added) (alias declaration)
    using wage = double;  // wage is a alias of double
    using ptr = double*;  // ptr is a alias of double*

    // 3. understand the pointer with typedef
    typedef char* pstring;
    // what is the difference betweem cstr1 and cstr2?
    const pstring cstr1 = 0;  // ctr1 is a const pointer which point to a char
    const char* cstr2 = 0;    // ctr2 is a pointer which point to a const char
    // when meet a statement which contains type alias. many programmers would try to understand it by transform it by replace the alias.
    // like in line 22, but this is the wrong method (cstr1 and cstr2 are difference)

    // in this example (line22), the "pstring" is not equal to "char*", we need to say the "char" is equal to "*pstring"
    // the pstring is need to be represent as a pointer which point to a char

    // about "int* ptr": many programmers would understand in this way: ptr is a pointer which type is int*
    // but when we define mutiple pointers like: "int* ptr1, *ptr2" or "int* ptr3, ptr4" the ptr4 is a integer
    // in other words the "*" is only used to decorate the ptr. the type(s) on the left of "*" define the which type of value the pointer is point to


    // auto
    // 1. basic
    int i1 = 1, i2 = 2;
    auto a1 = i1 + i2;
    // in programming, usually we need to assign a expression to a variable. but in complex system, it is very hard to know the type of expression
    // auto means the compiler would automatically caculate the statement know the type then give to the variable
    auto a2 = 0, * p1 = &i1; // legal: both a2 and p1 are integer
    // auto sz = 0, f = 3.14;  illergal: sz is an integer but f is a double
    
    // 2. compound type
    int i3 = 3, & p2 = i3;
    auto a3 = p2;  // a3 is an integer
    
    const int ci = i3, & cr = ci, const& ccr = ci;
    auto b = ci;  // b is an int instead of const int as ci, that is because the top-level const is ignored by the compiler
    auto c = cr;  // samely, c is also an integer
    auto d = &i3; // if gave a addr of a variable, then the compiler would treat auto as pointer
    auto e = &ci; // e is a pointer which is point to a const int
    auto f = &ccr; 
    f++; // as same as e, f is not a const pointer which point to a const integer like &ccr (the top-level is ignorged)
    const auto g = &ccr; // g++; error, if we want to define a top-level required auto object

    b = 42;
    c = 42;
    *d = 42;  // d = 42 is wrong, because d is a pointer which the value of d is the &i3
    // both e = 42 and *e = 42 were is wrong, because ci is a const int

    // 3. decltype
    const int ci1 = 0, & cj = ci;
    decltype(ci1) da = 0;  // type da is const int (same as ci1)
    decltype(cj) db = da;  // type db is const int &, which means y is a refrence of db

    // refrence and decltype
    int i4 = 4, * p3 = &i4, & r = i4;
    decltype(r + 0) i5 = 0; // correct type (r + 0) is int instead of refrence
    // decltype(r) r1 = 1;  error, decltype(r) means a refrence type, so r1 must be a refrence 
    // decltype(*p3) r2;  error, decltype(*p3) is a refrence type which need to be assigned when initialized 
    // "*" is a dereference oprator, as we all know that: because p3 is a pointer. when we dereference it, we will get the object which this pointer is point to which is a reference

    decltype(i4) dc;
    // decltype((i4)) dd; error: dd is a refrence, remember that decltype((variable)) is always a refrence

    // decltype vs auto
    // 1. both of them can define a object's type. auto using compiler to caculate the return value of the statement but decltype just try to analyse the statement and no need to caculate the value
    // 2. the auto value will ignore the top-level const(itself) (const int -> int) but the decltype won't
    // 3. decltype's type is relative to the expression form 

    
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
