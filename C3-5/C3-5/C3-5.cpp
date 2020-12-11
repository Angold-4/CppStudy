// C3-5.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 20201203 Jiawei Wang

#include <iostream>
#include <string>
#include <vector>

#include <ctime>
#include <cstdlib>

using namespace :: std;

int ncexpr()
{
    return 1;
}

constexpr int cexpr()
{
    return 1;
}

void iprint(int* beg, int* end)
{
    while (beg != end)
        cout << *beg++ << endl;
}

void irprint(int* (&beg)[3]) 
{
    for (auto ele : beg)
        cout << ele << endl;

}

int main()
{
    std::cout << "Hello World!\n";

    // array
    // array vs vector
    // 1. The size of array is fixed
    // 2. Both of them can store same type of data, and the data do not have name, must be accessed with index

    // initialization
    unsigned ui = 42;
    constexpr unsigned cui = 42;
    int arra[10];  // create an array which size is 10
    // The size of array must be a const number when initialized
    int arra1[cui];
    // int arr2[ui];  error: must be a const number
    int* parra[cui]; // an array which has 42 integer pointer

    // auto arr3[cui];  error: must determine the type of array when initialized

    string a[3] = { "hi","bye" }; // a = ["hi", "bye", "")

    // char array initialization
    char a1[] = { 'C', '+', '+' };  // a.size() = 3
    // In Chapter 2, "wgwan" == 'w''g''w''a''n''\0'
    // const char a1[3] = "C++";   // a1 need 4 spaces: 'C' '+' '+' and '\0'

    // cannot copy and assign
    int a2[] = { 0, 1, 2 };
    // int a3[] = a2;  error
    // a3 = a2; error

    // pointer array initialization
    int a4[] = { 1, 2, 3, 4, 5, 6 };
    int(*pa4)[6] = &a4;  // must define the size of pointer array when initialized
    int(&ra4)[6] = a4; 
    // int* (&rpa4)[6]; TODO: find the ptr array

    int* ptrarr[] = { a4,a4,a4 };
    int* (&rptarr)[3] = ptrarr;
    cout << "pointer array ref:" << endl;
    irprint(rptarr);
    // output:
    // pointer array ref:
    // 0098F4F4
    // 0098F4F4
    // 0098F4F4

    // looking from the inside out will help you to understand



    // int a5[ncexpr()];  error: although the ncexpr() function(defined in line10) always return the same value
    // it is not a const expression (cexpr)
    int a6[cexpr()]; // correct, because cexpr() (line 15) is defined as a const expression

    // Exercise 3.31
    int a7[10];
    for (size_t index = 0; index < size(a7); index++)
    {
        a7[index] = index;
    }
    cout << "a7 = " << a7 << endl; // every times it is different(the pointer which point to the first element of array)
    for (auto ia : a7) {
        cout << ia << " ";
    }
    cout << endl;
    // output: 0 1 2 3 4 5 6 7 8 9


    // array and pointer
    string s[] = { "one", "two", "three" };
    string* p = &s[0];
    string* p1 = s;
    cout << "p = " << p << endl << "p1 = " << p1 << endl;
    // p == p1 always
    // which means in cpp:
    // nums == &nums[0]

    int a8[] = { 1, 2, 3, 4, 5 };
    auto ia1(a8); // using "auto" : the type of "ia1" is a pointer
    decltype(a8) ia2;  // using decltype : the type of "ia2" is an array


    // iterator and pointer
    int a9[] = { 1, 2, 3, 4, 6, 7, 8, 11, 33, 44, 332, 131, 3232 };
    for (int* pa5 = a9, *e = &a9[13]; pa5 != e; pa5++)
        cout << *pa5 << " ";
    cout << endl;

    // end() and begin()
    // because array is not a class type(like vector), these two function were not member function
    int a10[] = { 2,4,6,8,10,12,14,16,18,20,22,24,-26,28 };
    int* pbeg = begin(a10), * pend = end(a10); 
    while (pbeg != pend && *pbeg >= 0)
    {
        ++pbeg;
    }
    cout << *pbeg << endl;  // output: -26

    // pointer opration
    // a pointer has three information:
    // 1. value -- the addr of the object which it point to
    // 2. object -- the type of the object wipt
    // 3. addr -- the pointer's address
    // addition between pointers is meaningless, but minus in the same container is meaningful
    // in same container, p1 - p2 = the distance between two objects(not the pointer)
    constexpr size_t sz = 5;
    int a11[sz] = { 1, 2, 3, 4, 5 };
    int* p2 = a11, * p3 = a11 + sz;
    while (p2 < p3)
        ++p2;

    int sz1 = 0, sz2 = 42;
    int* p4 = &sz1, * p5 = &sz2;
    if (p4 < p5) {
        cout << "True" << endl;
    }
    if (p4 >= p5) {
        cout << "False" << endl;
    }

    /*
    // Exercise 3.40
    const int size = 5;
    int a12[size], a13[size], i;

    srand((unsigned)time(NULL));  // genarate the random seed
    // genarate the random array
    for (i = 0; i < sz; i++)
        a12[i] = rand() % 10;
    cout << "Genarate successfully!" << endl << "Please input 5 number:" << endl;

    // get the user array
    int uVal;
    for (i = 0; i < sz; i++)
        if (cin >> uVal)
            a13[i] = uVal;

    int* p6 = begin(a12), * p7 = begin(a13);
    while (p6 != end(a12) && p7 != end(a13))
    {
        if (*p6 != *p7) 
        {
            cout << "Wrong!" << endl;
            cout << "Genarate number: " << endl;
            for (auto inpt : a12)
                cout << inpt;
            cout << endl;

            cout << "Your input: " << endl;
            for (auto inp : a13)
                cout << inp;
            cout << endl;

            return 1;
        }
        p6++;
        p7++;
    }
    cout << "Congraduations! You are right!!" << endl;

    // using array to initalize vector object
    int int_arr[] = { 0, 1, 2, 3, 4 };
    vector<int> ivect{ begin(int_arr)+1, end(int_arr)-1 };
    for (auto vec : ivect)
        cout << vec << " "; // output: 1 2 3
    cout << endl;

    return 0;
    */

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