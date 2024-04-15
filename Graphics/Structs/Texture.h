#pragma once

#include "TextureConfig.h"
#include <string>

static unsigned short g_Slot;

namespace RE
{
	struct Texture
	{
		friend class IRenderable;
	protected:
		unsigned int ID;
		unsigned short Slot;
	public:
		Texture(const char* filename, bool assignUnit = true);
		Texture(unsigned int width, unsigned int height, unsigned char* data);
		void Destroy();
		void Bind();
		void Unbind();
	};
}

