#pragma once
#ifndef EGG_H
#define EGG_H

#include <string>

using namespace::std;

// aggregate class
struct Data
{
	int ival;
	string s;
	double dval;

	int setIval(int i)
	{
		ival = i;
		return ival;
	}
};

#endif // !EGG_H
