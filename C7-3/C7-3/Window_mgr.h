#pragma once
#ifndef WINDOW_MGR_H
#define WINDOW_MGR_H

#include <string>
#include <iostream>
#include <vector>


using namespace::std;

class Window_mgr
{
public:
	using ScreenIndex = vector<Screen>::size_type;

public:
	void clear(ScreenIndex);
	ScreenIndex addScreen(const Screen&);

private:
	std::vector<Screen> screens{ Screen(24, 80, ' ') };
};

void Window_mgr::clear(ScreenIndex i)
{
	Screen& s = screens[i];
	s.contents = string(s.height * s.width, ' '); // friend class can access (height and width) 
}

Window_mgr::ScreenIndex 
// before we define a function which is declared inside the class
// we need to make sure that the return type is visible outside the class
Window_mgr::addScreen(const Screen& s)
{
	screens.push_back(s);
	return screens.size() - 1;
}

#endif // !WINDOW_MGR_H
