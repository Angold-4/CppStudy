#pragma once
#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
#include <string>


using namespace::std;

class Screen
{
	// makes Window_mgr(member) can access the private member in Screen
	friend class Window_mgr; // in Window_mgr.h, we do not need to add "include "Screen.h"" after add this statement
//  friend void Window_mgr::clear(ScreenIndex);
public:
	// initialize
	typedef string::size_type pos;
	Screen() = default;
	Screen(pos ht, pos wid) : height(ht), width(wid), contents(ht* wid, ' ') { }
	Screen(pos ht, pos wid, char c) : height(ht), width(wid), contents(ht* wid, c) { }

public:
	Screen& move(pos, pos);
	Screen& set(char);
	Screen& set(pos, pos, char);
	// display won't change the value of Screen obj, in normal case, "this" is a const pointer
	// overload function display (both used whether the Screen obj is const)
	const Screen display(ostream& os) const { do_display(os); return *this; } // const 
	Screen display(ostream& os) { do_display(os); return *this; } // non-const

private:
	pos cursor = 0;
	pos height = 0, width = 0;
	string contents;
	void do_display(ostream& os) const { os << contents; }
};





inline Screen& Screen::move(pos r, pos c)
{
	cursor = r * width + c;
	return *this;
}


inline Screen& Screen::set(char ch)
{
	contents[cursor] = ch;
	return *this;
}

inline Screen& Screen::set(pos r, pos c, char ch)
{
	contents[r * width + c] = ch;
}

#endif // !SCREEN_H
