#ifndef TEST
#define TEST
#include "engine.hpp"
#include <iostream>

class Test : public Component
{
private:
	Vector2 dir;
	GameObject cube;
	GameObject player;

	float spd;
	float drag;

public:
	//Test() { }

	void Start() override
	{
		spd = 2;
		drag = 10;

		player.Set(GameObject::Cube, .4, .4, .4, 0);
		cube.Set(GameObject::Cube, .4, .4, .4, 1);

		player.Pos(0.0, 0.0, 1);
		cube.Pos(-1.5, 1.5, 0);
	}

	void Draw() override
	{
		player.Render();
		cube.Render();
	}

	void Update(float dt) override
	{
		Input::GetAxis(Input::Horizontal, dir.x);
		Input::GetAxis(Input::Vertical, dir.y);

		Physics::Rotate(cube, Vector3(1.5, 1, 1) * dt);

		Physics::AddForce(player, dir, spd, drag);
	}
};

Test test;

#endif