#pragma once

#include "IRenderable.h"
#include <Graphics/Structs/VertexArray.h>
#include <Graphics/Structs/ShaderProgram.h>
#include <Graphics/Structs/Texture.h>

namespace RE
{
	struct Mesh : public IRenderable
	{
	public:
		Mesh();
	};
};