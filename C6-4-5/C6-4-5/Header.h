#include <string>

using namespace::std;

#pragma once
inline const string &
shorterString(const string& s1, const string& s2)
{
	return s1.size() <= s2.size() ? s1 : s2;
}

void printNDE(const int ia[], size_t size)
{
#ifndef NDEBUG
	cerr << __func__ << ": array size is " << size << endl;
#endif
}

void printCST()
{
	cerr << "Error: " << __FILE__ << " : in function " << __func__ << " at line " << __LINE__ << endl;
	cerr << "       Compiled on " << __DATE__ << " at " << __TIME__ << endl;
}
