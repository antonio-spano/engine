#ifndef INPUT
#define INPUT

#include "utils.hpp"

class Input
{
	public:
	enum Axis
	{
		Horizontal,
		Vertical
	};

	static void GetAxis(Axis which, float& axis);
};

#endif