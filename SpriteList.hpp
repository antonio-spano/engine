#ifndef SPRITE_LIST
#define SPRITE_LIST

#include <string>
#include "sprite.hpp"

const int DIM = 2;

void SpriteList()
{
	std::string filetexture[DIM];
	filetexture[0] = "images/awesomeface.png";
	filetexture[1] = "images/container.jpg";

	Sprite images(DIM, filetexture);
	images.Generate();
}

#endif
