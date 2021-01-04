#pragma once
#ifndef SALES_DATA_H_INCLUDED
#define SALES_DATA_H_INCLUDED

#include <iostream>
#include <string>

using namespace::std;

class Sales_data
{
	// friend function
	friend istream& operator >> (istream&, Sales_data&);
	friend ostream& operator << (ostream&, const Sales_data&);
	friend bool operator < (const Sales_data&, const Sales_data&);
	friend bool operator == (const Sales_data&, const Sales_data&);
	friend Sales_data add(const Sales_data&, const Sales_data&);
	friend istream& read(istream& is, Sales_data& item);
	friend ostream& print(ostream& os, const Sales_data& item);


public: // 3 ways to initialize
	Sales_data() = default; // C++ 11 default initialization

	// constructor initialize list
	Sales_data(const string &book) : bookNo(book){ } // means bookNo = book
	Sales_data(const string &book, unsigned n, double p) : bookNo(book), units_sold(n), revenue(p) { }
	Sales_data(istream& is) { read(is, *this); }

public:
	Sales_data& operator += (const Sales_data&);
	string isbn() const { return bookNo; }
	Sales_data& combine(const Sales_data& rhs)
	{
		units_sold += rhs.units_sold;
		// caculated the avg saleprice
		saleprice = (rhs.saleprice * rhs.units_sold + saleprice * units_sold) / (rhs.units_sold + units_sold);
		if (sellingprice != 0.0)
		{
			discount = saleprice / sellingprice;
			return *this;
		}
	}


private:
	string bookNo;
	unsigned units_sold = 0;
	double sellingprice = 0.0; // original price
	double saleprice = 0.0; // actual price
	double discount = 0.0;
	double revenue = 0.0;
};

Sales_data add(const Sales_data& lhs, const Sales_data& rhs)
{
	Sales_data sum = lhs;
	sum.combine(rhs);
	return sum;
}

istream& read(istream& is, Sales_data& item)
{
	double price = 0;
	is >> item.bookNo >> item.units_sold >> item.sellingprice >> item.saleprice; // stop when meet blank (">>")
	item.revenue = price * item.units_sold;
	return is;
}

ostream& print(ostream& os, const Sales_data& item)
{
	os << item.isbn() << " " << item.units_sold << " " << item.saleprice << " " << item.discount;
	return os;
}

#endif
