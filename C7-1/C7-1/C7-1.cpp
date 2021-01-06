// C7-1.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 20210104 Jiawei Wang

#include <iostream>
#include "Person.h"
#include "Sales_data.h"

using namespace::std;

int main()
{
    std::cout << "Hello World!\n";

    // class
    // data abstraction and encapsulation

    // Test Sales_data.h

    // initialization:
    Sales_data SD1;
    Sales_data SD2("978-7-121-15535-2");
    Sales_data SD3("978-7-121-15535-2", 100, 128.8);
    Sales_data SD4(cin);


    // The main deal with same ISBN books:
    cout << "Please input the translation record: (ISBN, Sold, selling price, sale price) " << endl;
    Sales_data total;

    if (read(cin, total))
    {
        Sales_data trans;
        while (read(cin, trans))
        {
            if (total.isbn() == trans.isbn())
                total = add(total, trans);
            else
            {
                print(cout, total);
                cout << endl;
                total = trans;
            }
        }
        print(cout, total);
        cout << endl;
    }
    else
    {
        cerr << "No data?!" << endl;
        return -1;
    }

    // Test Person.h
    Person Peter("Peter Wong", "Tokyo");
    Person Nul;
    Person John(cin);

    cout << "Peter: " << Peter << endl;
    cout << "Nul: " << Nul << endl;
    cout << "John: " << John << endl;

    // example:
    // line 32 in Sales_data.h:
    // string isbn() const { return bookNo; }
    // The usage of const after "isbn()" -- tell the compiler that "this" is a pointer which point to a const object
    // Then a const Sales_data obj can call isbn()
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
