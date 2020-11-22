// C2-4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

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
    std::cout << r1 << "\n"
        << &r1 << "\n"
        << &ci;




    





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
