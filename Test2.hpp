#ifndef TEST2
#define TEST2
#include "engine.hpp"
#include <iostream>

class Test2 : public Component
{
	void Start() override { }

	void Draw() override { }

	void Update(float dt) override
	{
		std::cout << "Update test2\n";
	}
};

Test2 test2;

#endif