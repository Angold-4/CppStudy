// C6-3.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 20201222 Jiawei Wang

#include <iostream>
#include <String>
#include <vector>

using namespace :: std;


// Local object/value cannot be return! (in ref or pointer function)
const string &mainrip()
{
    string ret;
    ret += "JK";
    if (ret == "JK")
        return ret; // error: after return, the local variable ret will be freed
    else
        return "Empty"; // error: after return, the local object will be freed
}

// return ref
const string& shorterString(const string& s1, const string& s2)
{
    return s1.size() <= s2.size() ? s1 : s2;
}

// function call as lvalue
char& get_val(string& str, string::size_type ix)
{
    return str[ix];
}

// recursion function
int& outVector(vector<int> v)
{
    static auto b = v.begin(), e = v.end();
    if (b != e)
    {
        cout << *b << " ";
        b++;
        return outVector(v);
    }
}

// array function (the following four functions are the same)
int(*af1(int i))[3]
{
    int a[3] = {i,i,i};
    return &a;
    // not safe because return a addr of local variable
}

using arrT = int[3]; // or typedef int arrT[3];
arrT* af2(int i)
{
    int a1[3] = { i,i,i };
    return &a1;
    // not safe because return a addr of local variable
}

auto af3(int i) -> int(*)[3]
{
    int a2[3] = {i,i,i};
    return &a2;
    // not safe because return a addr of local variable
}

int a3[3] = { 3,3,3 };
decltype(a3)* af4(int i)
{
    return &a3;
}


int main()
{
    std::cout << "Hello World!\n";

    // return

    // it is not necessary to have a return statement in void function
    // because the return will be implicitly add and execute by the compiler
    // another exception: in main() function, if no return statement, 
    // the compiler would add a "return 0;" statement automatically

    // line 12 function &mainrip()
    // const string mr = mainrip();
    // error, after return, all storiages of local objects/value will be freed

    // line 23 function &shorterString()
    string s1 = "wangjiawei";
    string s2 = "Wange";

    auto sz = shorterString(s1, s2).size();
    cout << sz << endl; // 5

    // line 29 function &get_val()
    string s("a value");
    cout << s << endl;
    get_val(s, 0) = 'A';
    cout << s << endl;

    // line 35
    vector<int> vi = { 1,2,3,4,5 };
    outVector(vi);
    cout << endl;

    // array cannot be copied
    // we usually a ref or a pointer of array when function return
    // line 47 see four different expressions of define a array-ret function
    int (*p)[3] = af1(3);
    cout << **p << endl; // 3

    int(*p2)[3] = af2(3);
    cout << **p2 << endl; // 3

    // trailing return type
    int(*p3)[3] = af3(3);
    cout << **p3 << endl; // 3

    // using decltype
    int(*p4)[3] = af4(3);
    cout << **p4 << endl; // 3

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
