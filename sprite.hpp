#ifndef SPRITE
#define SPRITE

#include "glad/glad.h"
#include "stb_image.h"
#include <iostream>

class Sprite
{
private:
	int nrTextures = 1;
	unsigned int* texture = new unsigned int[1];
	std::string* imagepath = new std::string[1];

	void SetPath(std::string path);
	void SetPath(int index, std::string path);

	void Dispose(unsigned char* data);

public:
	Sprite(std::string imagepath);
	Sprite(int nrTextures, std::string* imagepath);

	void Generate();
	~Sprite();
};

#endif
