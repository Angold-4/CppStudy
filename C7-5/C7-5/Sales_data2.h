#pragma once
#ifndef SALES_DATA2
#define SALES_DATA2

#include <iostream>
#include <string>

using namespace::std;

class Sales_data2
{
	friend istream& read(istream&, Sales_data2&);
	friend ostream& print(ostream&, const Sales_data2&);

public:
	// init function
	Sales_data2(const string& book, unsigned num, double sellp, double salep) :
		bookNo(book), units_sold(num), sellingprice(sellp), saleprice(salep)
	{
		if (sellingprice)
			discount = saleprice / sellingprice;
		cout << "Create a Sales_data2 obj with four arguments" << endl;
	}
	Sales_data2() : Sales_data2("", 0, 0, 0) { cout << "Create a Sales_data2 obj with no argument" << endl; }
	Sales_data2(const string& book) : Sales_data2(book, 0, 0, 0) 
	{ cout << "Create a Sales_data2 obj with 1 argument" << endl; }

	Sales_data2(istream& is) : Sales_data2() 
	{
		read(is, *this);
		cout << "Create a Sales_data2 obj with an argument(istream)" << endl;
	}

private:
	string bookNo;
	unsigned units_sold = 0;
	double sellingprice = 0.0;
	double saleprice = 0.0;
	double discount = 0.0;
};


istream& read(istream& is, Sales_data2& sd)
{
	is >> sd.bookNo >> sd.units_sold >> sd.sellingprice >> sd.saleprice;
	return is;	
}

ostream& print(ostream& os, const Sales_data2& csd)
{
	os << csd.bookNo << csd.units_sold << endl;
	return os;
}


#endif // !SALES_DATA2
