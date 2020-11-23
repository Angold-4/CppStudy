// C2-3.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 20201122 Jiawei Wang

#include <iostream>

int main()
{
    std::cout << "Hello World!\n";

    // lvalue reference
    int ival = 1024;
    int& refVal = ival;
    // int& refval2; error: reference variable requires an initializer
    // because when a variable is initialized. the initial value will be copied to the object
    // but when reference is initialized. the compiler will bind the ref and the value together

    refVal = 2;
    std::cout << refVal << std::endl << ival << std::endl; // output: 2 2

    // int& refVal2 = 10; error: initial value of refrence must be a non-const value

    // double dval = 3.14; int& refVal3 = dval; error: the ref and the object must be the same type

    // pointer

    int pval = 42;
    int* p = &pval;
    std::cout << "&pval = " << &pval << std::endl << "*p = " << *p << std::endl;
    std::cout << "p = " << p << std::endl << "&p = " << &p << std::endl << "*&p = " << *&p << std::endl;

    // output:
    // &pval = 0115F918
    // * p = 42
    // p = 0115F918
    // &p = 0115F90C
    // * &p = 0115F918

    // note: if "*" and "&" do not appear immediately after the type name.
    // "*" :dereference oprator; "&" : address-of oprator

    // & after the type: quote
    int pval9 = 25;
    int& p9 = pval9;
    std::cout << "&pval9 = " << &pval9 << std::endl
        << "p9 = " << p9 << std::endl
        << "&p9 = " << &p9 << std::endl;

    // output:
    // &pval9 = 0031F854
    // p9 = 25
    // &p9 = 0031F854

    // null pointer
    int* p1 = nullptr;
    int* p2 = 0;

    // pointer vs refrence
    // 1. pointer pointer to a object, refrence "bind" to a object, both of them achieved indirect access to objects
    // 2. the pointer is an objet which means can assign it and copy it. and a pointer can point to mutiple objects(not at the same time)
    // 3. the refrence is not an object which means it cannot be re-bind after initialization

    // void pointer
    double d = 3.14159, * pd = &d;
    int i5 = 5;
    void* pv = &d;
    std::cout << "pv = " << pv << std::endl;
    pv = &i5;
    std::cout << "pv = " << pv << std::endl;
    // output: pv = 008FFB48; pv = 008FFB30
    // note: but we cannot use void pointer to directly manipulate the pointed object
    // because the compiler do not know the type of the point object (just know the address)
    // std::cout << "* pv = " << * pv << std::endl; will be wrong statement

    // notice:
    // both int *p6 and int* p6 are the correct ways to define a pointer
    // the type of both pointer p6 and integer p7 are the same (int)
    int* p6, p7;
    p7 = 100;
    p6 = &p7;
    std::cout << "p7 = " << *p6 << std::endl; // output: p7 = 100;

    // pointer to pointer:
    int ival5 = 1024;
    int* pi7 = &ival5;
    int** pp7 = &pi7;
    int*** ppp7 = &pp7;

    std::cout << "The value of ival5:\n"
        << "direct value: " << ival5 << "\n"
        << "indirect value: " << *pi7 << "\n"
        << "double indirect value: " << **pp7 << "\n"
        << "triple indirect value: " << ***ppp7 << "\n";

    // output:
    // The value of ival5:
    // direct value : 1024
    // indirect value : 1024
    // double indirect value : 1024
    // triple indirect value : 1024

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
