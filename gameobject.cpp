#include "gameobject.hpp"

GameObject::GameObject(int shape, float xLength, float yLength, float zLength)
{
	switch(shape)
	{
	case Shape::Square:
		break;

	case Shape::Cube:
		this->CubeVBO();
		break;
	}
}

GameObject::GameObject(int shape, float xLength, float yLength, float zLength, int imgID)
{
	this->object = glm::mat4(1.0f);
	switch(shape)
	{
	case Shape::Square:
		break;

	case Shape::Cube:
		this->CubeVBO();
		this->x = xLength;
		this->y = yLength;
		this->z = zLength;
		this->object = glm::scale(this->object, glm::vec3(this->x, this->y, this->z));
		this->imgID = imgID;
		break;
	}
}

void GameObject::Set(int shape, float xLength, float yLength, float zLength)
{
	switch(shape)
	{
	case Shape::Square:
		break;

	case Shape::Cube:
		this->CubeVBO();
		break;
	}
}

void GameObject::Set(int shape, float xLength, float yLength, float zLength, int imgID)
{
	this->object = glm::mat4(1.0f);
	switch(shape)
	{
	case Shape::Square:
		break;

	case Shape::Cube:
		this->CubeVBO();
		this->x = xLength;
		this->y = yLength;
		this->z = zLength;
		this->object = glm::scale(this->object, glm::vec3(this->x, this->y, this->z));
		this->imgID = imgID;
		break;
	}
}

void GameObject::Pos(float xpos, float ypos, float zpos)
{
	this->xpos = xpos;
	this->ypos = ypos;
	this->zpos = zpos;
	this->object = glm::translate(this->object, glm::vec3(this->xpos, this->ypos, this->zpos));
}

void GameObject::CubeVBO()
{
	//vertex buffer object
	unsigned int VBO;
	glGenBuffers(1, &VBO);
	//bind VBO
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(this->cubeVertices), this->cubeVertices, GL_STATIC_DRAW);
	//telling opengl how to interpret vertex attributes
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
}

void GameObject::Render()
{
	shader.Use();
	shader.SetMatrix4("model", this->object);
	shader.SetInt("texture0", this->imgID);
	glDrawArrays(GL_TRIANGLES, 0, 36);
}