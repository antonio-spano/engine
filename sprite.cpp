#include "sprite.hpp"

Sprite::Sprite(std::string path)
{
	this->SetPath(path);
}

Sprite::Sprite(int nrTextures, std::string* path) : nrTextures(nrTextures)
{
	if (nrTextures > 1)
	{
		this->texture = new unsigned int[nrTextures];
		this->imagepath = new std::string[nrTextures];
	}

	for (int i = 0; i < nrTextures; i++)
	{
		this->SetPath(i, path[i]);
	}
}

void Sprite::SetPath(std::string path)
{
	this->imagepath[0] = path;
}

void Sprite::SetPath(int index, std::string path)
{
	this->imagepath[index] = path;
}

void Sprite::Generate()
{
	int width, height, nrChannels;
	unsigned int channelType;
	unsigned char* data;

	for (int i = 0; i < nrTextures; i++)
	{
		glGenTextures(1, &this->texture[i]);

		glActiveTexture(GL_TEXTURE0 + i);
		glBindTexture(GL_TEXTURE_2D, this->texture[i]);

		data = stbi_load(imagepath[i].c_str(), &width, &height, &nrChannels, 0);

		if (data)
		{
			switch (nrChannels)
			{
			case 3:
				channelType = GL_RGB;
				break;
			case 4:
				channelType = GL_RGBA;
				break;
			default:
				channelType = GL_RGB;
				break;
			}

			glTexImage2D(GL_TEXTURE_2D, 0, channelType, width, height, 0, channelType, GL_UNSIGNED_BYTE, data);

			glGenerateMipmap(GL_TEXTURE_2D);
		}
		else
		{
			std::cout << "ERROR: Failed to load texture" << std::endl;
		}
		this->Dispose(data);
	}
}

void Sprite::Dispose(unsigned char* data)
{
	stbi_image_free(data);
}

Sprite::~Sprite()
{
	delete[] this->texture;
	delete[] this->imagepath;
}