// C2-1.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 20201121 Jiawei Wang

#include <iostream>

int main()
{
    std::cout << "Hello World!\n";

    // types transformation

    bool b = 42; std::cout << "b = " << b << std::endl; // output: b = 1

    bool t = true; int i = t; std::cout << "i = " << i << std::endl; // output: i = 1

    int j = 3.14; std::cout << "j = " << j << std::endl; // output: j = 3

    double p = j; std::cout << "p = " << p << std::endl; // output: p = 3.0

    signed char c = 256; std::cout << "c = " << c << std::endl;  // c is undefined

    unsigned u = 10;
    int in = -42;
    std::cout << u + in << std::endl; 
    // output: 4294967264 (2^32 - 42 + 10)
    // when oprations between int and unsigned(int), int -> unsigned

    unsigned u1 = 42, u2 = 10;
    std::cout << u2 - u1 << std::endl; 
    // output: 4294967264
    // u2 + (-u1) which means we transform unsigned number to an integer -> -u1 = 2^32 - 42 = 4294967254

    std::cout << "\7"; // Bell!

    std::cout << L'a' << u8"hi!" << 42ULL << 3e-2F << std::endl; // output: 97hi!420.03

    std::cout << 'a' << " " << L'a' << " " << "a" << " " << L"a" << std::endl; // output: a 97 a 00349C1C

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
