// C6-2.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 20201210 Jiawei Wang

#include <iostream>
#include <string>
#include <vector>
#include <initializer_list>

using namespace :: std;

// pointer parameter:
void reset(int* ip)
{
    *ip = 0; // although it is not called by refrence function, with pointer, we can change the value of ip
    ip = 0;  // just create a local variable
}

void reset1(int& ref)
{
    ref = 39;  // called by refrence function
}

void exchange(int &i1, int& i2)
{
    int i3 = i1;
    i1 = i2;
    i2 = i3;
}

// ignore the top-level const will cause: 
void fcn(const int i) {
    int j = i;
}

/*
void fcn(int i) // error: redefinition of function void fcn(const int)
{
    int j = i;
}
*/
// in C++, we can define two function with same name, but must have different type or number of parameters
// these two fcn functions above are same (because const object when initialized, it will ignore the top-level const

// These 3 functions will be treated as the same function
/*
void print(const int*) {};
void print(const int[]) {};
*/
void print(const int[10]) {}; 
// The compiler will only check whether the type of argument is int* or const int*

// using begin() and end() to avoid overflow:
void print(const int* beg, const int* end) 
{
    while (beg != end)
        cout << *beg++ << endl;
}

// These two statement are the same, they all pointer to a multidimentional array
void mprint(int matrix[][10], int rowsize){}
void mprint1(int (*matrix)[10], int rowsize){}

// Exercise 6.22
void pexchange(int* &p1, int* &p2)
// exchange the pointer's value
{
    int* p3 = p1;
    p1 = p2;
    p2 = p3;
}

void pexchange1(int* p1, int* p2)
// exchange the value which the pointer points to
{
    int v3 = *p1;
    *p1 = *p2;
    *p2 = v3;
}


// initializer_list
void err_msg(initializer_list<string> il)
{
    for (auto beg = il.begin(); beg != il.end(); ++beg)
        cout << *beg << " ";
    cout << endl;
}

int main()
{
    std::cout << "Hello World!\n";

    // line 11 function reset:
    int i = 42;
    reset(&i);
    cout << "i = " << i << endl; // output: i = 0

    // line 17 function reset1:
    reset1(i);
    cout << "After called reset1(), i = " << i << endl; // output: i = 39

    // line 22 function exchange (exercise 6.10)
    int i1 = 22, i2 = 12;
    cout << "Before exchange() i1 = " << i1 << ", i2 = " << i2 << endl;
    exchange(i1, i2);
    cout << "After exchange() i1 = " << i1 << ", i2 = " << i2 << endl;
    // output:
    // Before exchange() i1 = 22, i2 = 12
    // After exchange() i1 = 12, i2 = 22

    // notice: if the function does not modify the value of parameter, in general, we usually use called by refrence
    // That is because it can save space and increace the efficiency of program

    fcn(9);

    // array parameter:
    // line 44 function print
    int j[1] = { 1 };
    print(j); 
    // if we do not give the limitation of array's size, then overflow causes easily
    // because the compiler will ignore the size of parameter when passing an array 
    // and only check the type of this object is whether a correspounding pointer
    int k[4] = { 1,2,3,4 };
    print(begin(k), end(k)); // string and vector has their own build-in function begin() and end() but array do not
    
    // refrence of array 
    int (&jl)[4] = k;
    for (auto ele : jl) { 
        cout << ele;
    } // output: 1234
    cout << endl;

    // refrence of multidimensional arrays
    // see line 58

    // Exercise 6.22
    // line 63 func pexchange

    int pe1 = 9, pe2 = 19;
    int *p1 = &pe1, *p2 = &pe2;
    cout << "Before pexchange(): pe1 = " << pe1 << "  pe2 = " << pe2 << endl;
    // pexchange(&pe1, &pe2); error
    pexchange(p1, p2); // cannot passing the addr, must the same type with parameter(pointer)
    cout << "After pexchange(): pe1 = " << *p1 << "  pe2 = " << *p2 << endl;
    pexchange1(p1, p2);
    cout << "After pexchange1(): pe1 = " << pe1 << "  pe2 = " << pe2 << endl;
    // output:
    // Before pexchange() : pe1 = 9  pe2 = 19
    // After pexchange() : pe1 = 19  pe2 = 9
    // After pexchange1() : pe1 = 19  pe2 = 9


    // parameters in main()
/*
int main(int argc, char *argv[])
{
    cout << "argc: " << argc << endl;
    cout << "argv[0]: " << argv[0] << endl;
    cout << "argv[1]: " << argv[1] << endl;
    cout << "argv[2]: " << argv[2] << endl;
}
*/
    // when input:
    // $ ./main Jiawei Wang
    // output:
    // argc: 3
    // argv[0]: ./main
    // argv[1]: Jiawei
    // argv[2]: Wang


    // initializer_list
    // like vector, initializer list is also a class template type
    // for a function, if all the paraeter have same type but the number is not sure
    err_msg({ "Jiawei", "Wang", "Fight", "!" });
    // Jiawei Wang Fight !

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
