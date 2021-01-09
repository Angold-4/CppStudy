#pragma once
#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <vector>

using namespace::std;

class Account
{
public:
	Account(string s, double d) : owner(s), amount(d) { }
	Account() = default;
public:
	void caculate() { amount += amount * interestRate; }
	static double rate() { return interestRate; }
	static void rate(double d) { interestRate = d; }
	Account& inits(string o = "Administrator", double ir = interestRate);
 // Account& init(string o = owner, double ir = interestRate); error: non-static member (owner) cannot be the default parameter

private:
	string owner = "";
	double amount;
	static double interestRate;
	static const int bankNo = 89;
	static double initRate();
	Account* PACT;
	static Account ACT;
 // Account ACT2; error: when define a same type member in class, no-static object is no allowed (except ref and ptr)
};

double Account::initRate()
{
	Account::interestRate = 0.01;
	return Account::interestRate;
}

Account& Account::inits(string o, double ir)
{
	owner = o;
	amount = ir;
	return *this;
}
#endif // !ACCOUNT_H
