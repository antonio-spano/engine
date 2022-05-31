#ifndef SHADER_H
#define SHADER_H

#include "glad/glad.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader
{
private: //ses
	unsigned int ID, vertex, fragment;

	void CreateAndLinkProgram(unsigned int& program, unsigned int vertexShader, unsigned int fragmentShader);
	void CreateShader(unsigned int& shader, int size, const char* shaderSource, unsigned int type);

public:
	Shader();
	Shader(const char* vertexPath, const char* fragmentPath);
	void Init(const char* vertexPath, const char* fragmentPath);

	void Use();
	//uniform stuff
	void SetBool(const std::string& name, bool value) const;
	void SetInt(const std::string& name, int value) const;
	void SetFloat(const std::string& name, float value) const;
	void SetMatrix4(const std::string& name, glm::mat4 mat);

	int GetID();

	~Shader();
};

#endif
