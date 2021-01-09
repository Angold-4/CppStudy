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
	// member function
	Sales_data2& combine(const Sales_data2&);

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

Sales_data2& Sales_data2::combine(const Sales_data2& sd2)
{
	if (this->bookNo == sd2.bookNo)
	{
		units_sold += sd2.units_sold;
		saleprice = (sd2.saleprice * sd2.units_sold + saleprice * units_sold) / (sd2.units_sold + units_sold);
		if (sellingprice != 0)
			discount = saleprice / sellingprice;
	}
	else
		cerr << "Difference isbn of two sales data cannot be combined! " << endl;
	return *this;

}



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
