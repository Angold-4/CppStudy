#pragma once
#ifndef NODEFAULT_H
#define NODEFAULT_H

#include <istream>
#include <string>

using namespace::std;

class NoDefault
{
	// there is no default init method in NoDefault()
public:
	NoDefault(int i)
	{
		val = i;
	}
	int val;
};

class C
{
public: 
	NoDefault nd; 
    C(int i = 0) : nd(i) { } // without this statement, C cannot be initialized
};
#endif // !NODEFAULT_H
