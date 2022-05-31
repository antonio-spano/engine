#ifndef PHYSICS
#define PHYSICS

#include "math.hpp"
#include "gameobject.hpp"
#include "utils.hpp"

enum Axis
{
	x,
	y,
	z
};

class Physics
{
private:

public:
	static void AddForce(GameObject& object, Vector2& dir, float force, float drag);
	static void Rotate(GameObject& obj, float angle, int axis);
	static void Rotate(GameObject& obj, Vector3 angleXYZ);
};

#endif