#ifndef UPDATE_LIST
#define UPDATE_LIST

#include "scripts.hpp"

Updatable list;

void UpdateList()
{
	list.RegisterUpdate(&test);
	list.RegisterUpdate(&test2);
}

#endif