#include "shader.hpp"
#include "file.hpp"

Shader::Shader() { }

Shader::Shader(const char* vertexPath, const char* fragmentPath)
{
	File vShaderFile(vertexPath, FileMode::Read);
	File fShaderFile(fragmentPath, FileMode::Read);

	std::string vertexCode = vShaderFile.GetContent();
	std::string fragmentCode = fShaderFile.GetContent();

	const char* vShaderCode = vertexCode.c_str();
	const char* fShaderCode = fragmentCode.c_str(); //epico

	//COF COF COF NZNZNZ COF COF COF COF NZNZNNZNZN
	CreateShader(this->vertex, 1, vShaderCode, GL_VERTEX_SHADER);
	CreateShader(this->fragment, 1, fShaderCode, GL_FRAGMENT_SHADER);

	CreateAndLinkProgram(this->ID, vertex, fragment);
}

void Shader::Init(const char* vertexPath, const char* fragmentPath)
{
	File vShaderFile(vertexPath, FileMode::Read);
	File fShaderFile(fragmentPath, FileMode::Read);

	std::string vertexCode = vShaderFile.GetContent();
	std::string fragmentCode = fShaderFile.GetContent();

	const char* vShaderCode = vertexCode.c_str();
	const char* fShaderCode = fragmentCode.c_str(); //epico

	//COF COF COF NZNZNZ COF COF COF COF NZNZNNZNZN
	CreateShader(this->vertex, 1, vShaderCode, GL_VERTEX_SHADER);
	CreateShader(this->fragment, 1, fShaderCode, GL_FRAGMENT_SHADER);

	CreateAndLinkProgram(this->ID, vertex, fragment);
}

void Shader::CreateShader(unsigned int& shader, int size, const char* shaderSource, unsigned int type)
{
	shader = glCreateShader(type);
	glShaderSource(shader, size, &shaderSource, NULL);
	glCompileShader(shader);

	int status;
	char infoLog[512];
	glGetShaderiv(shader, GL_COMPILE_STATUS, &status);

	if (!status)
	{
		glGetShaderInfoLog(shader, 512, NULL, infoLog);
		std::cout << infoLog << std::endl;
	}
}

void Shader::CreateAndLinkProgram(unsigned int& program, unsigned int vertexShader, unsigned int fragmentShader)
{
	this->ID = glCreateProgram();
	glAttachShader(this->ID, vertexShader);
	glAttachShader(this->ID, fragmentShader);
	glLinkProgram(this->ID);

	int linkStatus;
	char linkInfoLog[512];
	glGetProgramiv(this->ID, GL_LINK_STATUS, &linkStatus);

	if (!linkStatus) {
		glGetProgramInfoLog(this->ID, 512, NULL, linkInfoLog);
		std::cout << linkInfoLog << std::endl;
	}
}

int Shader::GetID()
{
	return this->ID;
}

void Shader::Use()
{
	glUseProgram(this->ID);
}

void Shader::SetBool(const std::string& name, bool value) const
{
	glUniform1i(glGetUniformLocation(this->ID, name.c_str()), (int)value);
}

void Shader::SetInt(const std::string& name, int value) const
{
	glUniform1i(glGetUniformLocation(this->ID, name.c_str()), value);
}

void Shader::SetFloat(const std::string& name, float value) const
{
	glUniform1f(glGetUniformLocation(this->ID, name.c_str()), value);
}

void Shader::SetMatrix4(const std::string& name, glm::mat4 mat)
{
	glUniformMatrix4fv(glGetUniformLocation(this->ID, name.c_str()), 1, GL_FALSE, glm::value_ptr(mat));
}

Shader::~Shader()
{
	glDeleteShader(this->vertex);
	glDeleteShader(this->fragment);
}