#pragma once
#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

using namespace::std;

class Person
{
	friend istream& read(istream&, Person&);
	friend ostream& print(ostream&, Person&);

	friend istream& operator >> (istream&, Person&);
	friend ostream& operator << (ostream&, Person&);
public:
	Person() = default;
	Person(const string &n, const string &addr) : name(n), address(addr) { }
	Person(istream& is) { is >> *this; }
public:
	string getName() const { return name; }
	string getAddr() const { return address; }
private:
	string name;
	string address;
};


istream& read(istream& is, Person& per)
{
	is >> per.name >> per.address;
	return is;
}

ostream& print(ostream& os, Person& per)
{
	os << per.getName() << per.getAddr();
	return os;
}

istream& operator >> (istream& is, Person& p)
{
	is >> p.name >> p.address;
	return is;
}

ostream& operator << (ostream& os, Person& p)
{
	os << p.name << p.address;

}

#endif