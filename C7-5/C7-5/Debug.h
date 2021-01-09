#pragma once
#ifndef DEBUG_H
#define DEBUG_H

using namespace::std;

class Debug
{
public:
	constexpr Debug(bool b = true) : hw(b), io(b), other(b) { } // constexpr statement must init all member
	constexpr Debug(bool h, bool i, bool o) : hw(h), io(i), other(o) { }
public:
	constexpr bool any() { return hw || io || other; }
	void set_io(bool b) { io = b; }
	void set_hw(bool b) { hw = b; }
	void set_other(bool b) { other = b; }

private:
	bool hw;
	bool io;
	bool other;
};

#endif // !DEBUG_H
