// C3-4.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 20201201 Jiawei Wang

#include <iostream>
#include <string>
#include <vector>

using std::cout; using std::cin; using std::endl;
using std::string;
using std::vector;


int main()
{
    std::cout << "Hello World!\n";

    // Create an iterator
    vector<string> v{ "Jia", "Wei", "Wang" };
    auto b = v.begin(), e = v.end();
    cout << *b << endl;
    cout << *(--e) << endl; // output: Wang
    // end() return the elements which "one past the end", which means the "off the end" position in the container
    // it dost not excist in the container, on the other hand, if there is no element in the container, 
    // both end and begin will return the same refrence(off the end)
    string s("some string");
    if (s.begin() != s.end())
    {
        auto it = s.begin();
        *it = toupper(*it);  // we use derefrence to change the value in s which means the it iterator is a refrence
    }
    cout << s << endl;  // output : Some string

    for (auto it1 = s.begin(); it1 != s.end() && !isspace(*it1); ++it1)
        *it1 = toupper(*it1);
    cout << s << endl;  // output : SOME string   


    // types of iterator
    vector<int>::iterator it2;
    string::iterator it3;

    vector<int>::const_iterator cit1;
    string::const_iterator cit2;

    const vector<int> cv;
    auto cit = cv.begin(); // type of cit is vector<int>::const_iterator
    vector<int> v1;
    auto it1 = v1.begin(); // type of it1 is vector<int>::iterator

    // if you want to define a const iterator: use cbegin
    auto cit3 = v1.cbegin();  // type of cit2 is vector<int>::iterator

    // Arrow(->) oprator
    // (*it).mem == it->mem
    /* get string
    string line, text;
    cout << "Please input text: " << endl;
    while (getline(cin, line)) {
        text += line;
        text += "\n";
        if (line == "")
            text += "\n";
        if (line == "Test")
            break;
    }
    */
    string line1;
    vector<string> v2;
    cout << "Please input text: " << endl;
    while (getline(cin, line1))
    {
        v2.push_back(line1);
        if (line1 == "Test")
            break;
    };

    /* Print every line
    for (auto it4 = v2.cbegin(); it4 != v2.cend(); ++it4)
        cout << *it4 << endl;
    */

    /*
    // Print line till meet the first blank line
    for (auto it5 = v2.cbegin(); it5 != v2.cend() && !it5->empty(); ++it5)
        cout << *it5 << endl;
    */

    // Do not add elements to the container to which the iterator belongs to the loop body that uses iterators

    // Print line till meet the first blank line && All caps
    for (auto it6 = v2.begin(); it6 != v2.end() && !it6->empty(); it6++)
    {
        for (auto it7 = it6->begin(); it7 != it6->end(); it7++)
            *it7 = toupper(*it7);
        cout << *it6 << endl;
    }

    // Exercise 3.23
    vector<int> vi{ 1,2,3,4,5,6,7,8,9,10 };
    for (auto it8 = vi.begin(); it8 != vi.end(); it8++)
    {
        *it8 = 2 * (*it8);
        cout << *it8 << " " << endl;
    }

    // Binary Search (iterator opration)
    vector<int> v11{ 2,4,5,7,8,44,677,877,54453,345436,32423425 };
    int sought = 677;
    auto beg = v11.begin(), end = v11.end();
    auto mid = v11.begin() + (end - beg) / 2;
    // The addition of iterators is meaningless, only the substraction have meaning, so (end + beg) is illegal

    while (mid != end && *mid != sought) {
        if (sought < *mid)
            end = mid;
        else
            beg = mid + 1;
        mid = beg + (end - beg) / 2;
    }
    cout << (*mid == sought) << endl; // output: 1

    // Exercise 3.24
    vector<int> vi20{ 2,3,4,5,7,5,6,7,5,435,32,543,437,56,435435,5436,5745,45325,645,46432,54357,45653,653754,6326,43657 };
    int times = 1;
    for (auto it20 = vi20.begin(), it21 = vi20.end() - 1; it20 < it21; it20++, it21--, ++times)
    {
        cout << *it20 + *it21 << " ";
        if (times % 5 == 0)
            cout << endl;
    }
    if (vi20.size() % 2 == 1)
        // odd number
        cout << vi20[(vi20.size() - 1) / 2] << endl;

    // output:
    // 43659 6329 653758 45658 54364
    // 46437 651 45332 5750 5871
    // 435467 599 437

    // Exercise 3.25
    vector<int> vi25{ 23,43,21,34,56,66,64,45,43,43,87,45,32,90,100,76,34,64,43,32,77,99,45,43 };
    vector<int> vi26(11, 0);
    for (auto it25 = vi25.begin(), it26 = vi25.end(); it25 != it26 && (*it25) <= 100; it25++)
        ++vi26[(*it25) / 10];
    for (auto& i1 : vi26)
        cout << i1 << " ";
    // output:
    // 0 0 2 4 8 1 3 2 1 2 1

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
