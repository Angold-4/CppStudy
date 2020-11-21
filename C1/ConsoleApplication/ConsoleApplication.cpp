// ConsoleApplication.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    // 1.iostream
    std::cout << "Hello World!\n";
    // std::cout means a variable cout in namespace std
    std::cout << "Enter two numbers:" << std::endl;
    // this expressinon can also be written as: 
    // std::cout << "Enter two numbers:";
    // std::cout << std::endl;
    int v1 = 0, v2 = 0;
    std::cin >> v1 >> v2;
    // this expressinon can also be written as: 
    // std:cin >> v1;
    // std:cin >> v2;

    // "<<" and ">>"
    // "<<" means output oprator, in its left must be an ostream object,
    // and in its right must be the value need to be output.
    // It will return the left object (ostream object).

    //  ">>" means input oprator, in its left must be an istream object,
    // and in its right must be the variable that need to be assigned.
    // It will also return the left object (istream object).

    std::cout << "The sum of " << v1 << " and " << v2
        << " is " << v1 + v2 << std::endl;

    // 2.while
    int sum1 = 0, val1 = 1;
    while (val1 <= 10) {
        sum1 += val1;
        ++val1;
    }
    std::cout << "Sum of 1 to 10 inclusive is "
        << sum1 << std::endl;

    // 3.for
    int sum2 = 0;
    for (int val2 = 1; val2 <= 10; ++val2)
        sum2 += val2;
    std::cout << "Sum of 1 to 10 inclusive is "
        << sum2 << std::endl;


    // test main
    char c;
    std::cout << "Enter a char" << std::endl;
    std::cin >> c;
    std::cout << "You've entered: " << c << std::endl;
    // conclution: 
    // the istream not only can accept the int value.

   
    // 4.iostream unknown parameter(s)
    int sum3 = 0, value = 0;
    while (std::cin >> value)
        // in this while expression the std::cin >> svalue return its left object (std::cin)
        sum3 += value;
    std::cout << "Sum is: " << sum3 << std::endl;

    // 5.if statement
    // cannot run in this if program 
    // because in line 61. if we input a non-integer value. 
    // the cin will not accepte input anymore(maybe) but can run other things like output.
    int currVal = 0, val = 0;
    if (std::cin >> currVal) {
        int cnt = 1;
        while (std::cin >> val) {
            if (val == currVal)
                ++cnt;
            else {
                std::cout << currVal << " occurs "
                    << cnt << " times" << std::endl;
                currVal = val;
                cnt = 1;
            }
        }
        std::cout << currVal << " occurs "
            << cnt << "times" << std::endl;
    }
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
