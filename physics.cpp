#include "physics.hpp"

void Physics::AddForce(GameObject& object, Vector2& dir, float force, float drag)
{
	const float DRAG_VALUE = .001f;
	const float MIN_DIR = .02f;

	float magnitude = Math::GetMagnitude2D(dir.x, dir.y);
	if (!glfwGetKey(window, GLFW_KEY_W) && !glfwGetKey(window, GLFW_KEY_S))
	{
		if (dir.y > 0)
		{
			dir.y -= DRAG_VALUE * drag;
		}
		if (dir.y < 0)
		{
			dir.y += DRAG_VALUE * drag;
		}
	}
	else
	{
		dir.y /= magnitude;
	}

	if (!glfwGetKey(window, GLFW_KEY_A) && !glfwGetKey(window, GLFW_KEY_D))
	{
		if (dir.x > 0)
		{
			dir.x -= DRAG_VALUE * drag;
		}
		if (dir.x < 0)
		{
			dir.x += DRAG_VALUE * drag;
		}
	}
	else
	{
		dir.x /= magnitude;
	}

	if (dir.y > -MIN_DIR && dir.y < MIN_DIR)
	{
		dir.y = 0;
	}

	if (dir.x > -MIN_DIR && dir.x < MIN_DIR)
	{
		dir.x = 0;
	}

	object.object = glm::translate(object.object, glm::vec3(dir.x * force * dt, dir.y * force * dt, 0.0f));
}

void Physics::Rotate(GameObject& obj, float angle, int axis)
{
	switch(axis)
	{
	case Axis::x:
		obj.object = glm::rotate(obj.object, angle, glm::vec3(1, 0, 0));
		break;
	case Axis::y:
		obj.object = glm::rotate(obj.object, angle, glm::vec3(0, 1, 0));
		break;
	case Axis::z:
		obj.object = glm::rotate(obj.object, angle, glm::vec3(0, 0, 1));
		break;
	default:
		return;
	}
}

void Physics::Rotate(GameObject& obj, Vector3 angleXYZ)
{
	obj.object = glm::rotate(obj.object, angleXYZ.x, glm::vec3(1, 0, 0));
	obj.object = glm::rotate(obj.object, angleXYZ.y, glm::vec3(0, 1, 0));
	obj.object = glm::rotate(obj.object, angleXYZ.z, glm::vec3(0, 0, 1));
}