// C3-6.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 20201204 Jiawei Wang

#include <iostream>
using namespace std;


int main()
{
    std::cout << "Hello World!\n";

    // Multidimensional Arrays
    int ia[3][4]; // read from left to right:
    // ia size is 3, each element is a 4 dimension array
    int ia1[10][20][30];
    // ia1 size is 10, each element is a 20 dimension array which elements were 30 dimension.

    // initialization
    int ia2[3][4] = {
        {0, 1, 2, 3},
        {4, 5, 6, 7},
        {8, 9, 10, 11}
    };
    // Nested "{}" is not necessary
    int ia3[3][4] = { 0,1,2,3,4,5,6,7,8,9,10,11 };
    // ia2 and ia3 are equivalent(elements were equal)

    int ia4[3][4] = { 0,1,2,3 };
    // initialized the first line, others will be initialized with default value(0)
    int ia5[3][4] = { {0}, {4}, {8} };
    // initialized every first elements each line


    // using for to change the array
    constexpr size_t rowCnt = 3, colCnt = 4; // size_t represent the size of array
    int ia6[rowCnt][colCnt];
    for (size_t i = 0; i != rowCnt; ++i) {
        for (size_t j = 0; j != colCnt; ++j)
            ia6[i][j] = i * colCnt + j;
    }
    for (auto& ele : ia6) {
        for (auto ele1 : ele)
            cout << ele1 << " ";
    }
    cout << endl;
    // output: 0 1 2 3 4 5 6 7 8 9 10 11

    // using range for to change the array
    size_t val = 0;
    constexpr size_t zCnt = 5;
    int ia7[rowCnt][colCnt][zCnt];
    for (auto& ele2 : ia7) 
    {  // ele2 must be a refrence, if not, ele2 will be a pointer(auto)
        for (auto& ele3 : ele2) 
        {   // ele3 must be a refrence, because it is not the bottom loop
            for (auto& ele4 : ele3) 
            { // ele4 must be a refrence in this situation, because we need to change the array's value
                ele4 = val;
                cout << ele4 << " ";
                val++;
            }
        }
    }
    cout << endl;
    // output : 0 1 2 ...... 57 58 59


    // pointer and multidimentional array
    int ia8[3][4] = { 0 };
    for (auto p1 = ia8; p1 != ia8 + 3; ++p1) {
        for (auto p2 = *p1; p2 != *p1 + 4; ++p2)
        // p2 is a pointer, because ia8's value is a pointer
            cout << *p2 << ' ';
        cout << endl;
    }
    // output:
    // 0 0 0 0
    // 0 0 0 0
    // 0 0 0 0

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
