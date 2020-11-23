// C2-4.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 20201122 Jiawei Wang

#include <iostream>

int main()
{
    std::cout << "Hello World!\n";

    // const - constance which cannot be changed
    // Only operations that do not change its content can be performed on const value
    const int bufSize = 512;    
    // bufSize = 1024; error: expression must be an modifiable value (const cannot be changed)
    int i = 10;
    const int c = i;
    int j = c;
    std::cout << "c = " << c << std::endl
        << "j = " << j << std::endl;
    // output: c = 10; j = 10;

    // in normal situation. const object are only valid within the file
    // which means, when multiple files contain same const. They are different object

    // in some cases. When a const object is not a constant expression but need to shared in different files
    // if we want the const object work as other variables (defined in a file, used in all files) the way is to add "extern" before the const

    const int ci = 1024;
    int i2 = 512;
    const int& r1 = ci;
    const int& r2 = i2; // r1 = 1024; r2 = 512;
    // r1 = i2; even if the const is &r1, the r1 cannot be changed
    // all values related to constants cannot be changed
    // int& r3 = ci; also this would be wrong.
    // since we cannot assign value to const ci. then it is not needed to create a refrence of ci

    int i3 = 42;
    const int& r3 = i3;  // contant refrence
    const int& r4 = r3 * 2; // constant refrence
    // int& r4 = r3 * 2; error: because this is a normal refrence and r3 is a constant
    // when we talk about refrence in C2-3. in most cases, the ref type and the value type must be the same. here is the exception

    // to understand the constant refrence causes, let's see this example:
    double dval = 3.14159;
    const int& r5 = dval;
    // r5 = 3.14159 
    // To make int ref const achieved. the compiler do somethings between these two statement:
    // const int temp = dval;
    // const int& r5 = temp;
    // as we can see that: the compiler create a temporary object to make sure this refrence can be achieved

    // when r5 is not a constance, like line 39. the compiler can also choose to create a temporary object like above (line 47)
    // but as we can see that: it will not do that. the reason is if c5 is not a constance which means can assign new value to it.
    // if we create a temporary object(temp) then we bind the temp object to c5 (int& c5 = temp) not the dval;
    // in a programmer's perspective. since he/she wants r5 to refer to dval, he definitely wants to operate dval through r5.
    // otherwise why need to bind them? seems that most of people will not do that, then the C++ compiler will treat this as illegal.


    // pointer and const
    const double pi = 3.14159;
    const double* cptr = &pi;
    // *cpter = 42; error, although we can create a pointer to a constance, we still cannot change it.
    
    // in C2-3, we also metioned in most cases: 
    // The type of the pointer must be consistent with the type of the object it refers to
    double dval2 = 3.14159;
    cptr = &dval2;
    // This is also a exception, and the value of const pi still cannot be changed

    // const pointer
    int i9 = 0;
    const int i10 = 10;
    // The following two statements are the same:
    int const* cptr1 = &i10;
    const int* cptr2 = &i10;
    // The above two statements are the same;
    cptr1++; cptr2++;  // the point's value are changable
    // which means both cptr1 and cptr2 are the pointer which point to a constant object

    const int* const cptr3 = &i9;
    int* const cptr4 = &i9;
    // cptr3++; cptr4++; error: because the pointer is a constance
    std::cout << "*cptr3 = " << *cptr3 << std::endl
        << "*cptr4 + 1 = " << *cptr4 + 1 << std::endl;
    // *cptr3 = *cptr3 + 1;  error if the pointer type is const. 
    // then no matter the value which point to is const or not, it cannot be changed through the pointer

    // non-constant can be converted into constants. but cannot be reversed

    // Question (To exam):
    const int v2 = 0;
    int v1 = v2;
    int* p1 = &v1, & s1 = v1;
    const int* p2 = &v2, * const p3 = &i, & s2 = v2;
    
    s1 = v2; // legal, assign
    // p1 = p2; illegal, int* pointer cannot point to const int* pointer (low-level const)
    p2 = p1; // legal, p2 is a const int pointer which can point to int pointer (exception)
    // p1 = p3; // illegal, same as p1 = p2
    p2 = p3; // legal, same as p2 = p1


    // const expression:
    // which declares an object as constant. This implies a guarantee that once initialized, 
    // the value of that object won't change, and the compiler can make use of this fact for optimizations.

    const int max_files = 20;  // is a const expression
    const int limit = max_files + 1;  // is a const expression

    int staff_size = 27;  // not a const expression
    // const int sz = get_size();  not a const expression, no matter get_size() return a value or not when compile

    // constexpr
    // in a complex system, we cannot make sure whether a expression is a constant expression
    // the C++ 11 standard allows the variable to be declared as constexpr type 
    // so that the compiler can verify whether the value of the variable is a constant expression
    // if not it will cause error

    constexpr int mf = 20;
    constexpr int lmt = mf + 1;
    // constexpr int sz = size();  only when size() is a constexpr funcion (return a value when compile) is legal

    const int* i11 = nullptr;  // i11 is a pointer which point to a constant value
    constexpr int* i12 = nullptr;  // i12 is a const pointer which point to a integer (no need to be constant)
    constexpr const int* i13 = nullptr; // i13 is a const pointer which pointer to a constant integer

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
