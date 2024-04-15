#include "Texture.h"
#include "TextureConfig.h"
#include <External/Glad/glad.h>
#include <External/stb_image/stb_image.h>

RE::Texture::Texture(const char* filename, bool assignUnit)
{
	unsigned char* data;
	int channels, wrap, filter, format, width, height;
	std::string fp;

	data = stbi_load(filename, &width, &height, &channels, 0);
	if (assignUnit)
	{
		Slot = g_Slot;
		g_Slot++;
	}
	else
	{
		Slot = -1;
	}

	if (data)
	{
		fp = std::string(filename);
		TextureConfig::Load(filename, wrap, format, filter);
	}

	glGenTextures(1, &ID);
	glBindTexture(GL_TEXTURE_2D, ID);

	if (data)
	{
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrap);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrap);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, filter);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, filter);

		glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);

		stbi_image_free(data);
	}
}

RE::Texture::Texture(unsigned int width, unsigned int height, unsigned char* data)
{
	Slot = -1;

	glGenTextures(1, &ID);
	glBindTexture(GL_TEXTURE_2D, ID);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, width, height, 0, GL_RED, GL_UNSIGNED_BYTE, data);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}

void RE::Texture::Destroy()
{
	glDeleteTextures(1, &ID);
}

void RE::Texture::Bind()
{
	if(Slot != - 1)
		glActiveTexture(GL_TEXTURE0 + Slot);
	glBindTexture(GL_TEXTURE_2D, ID);
}

void RE::Texture::Unbind()
{
	glBindTexture(GL_TEXTURE_2D, 0);
}
