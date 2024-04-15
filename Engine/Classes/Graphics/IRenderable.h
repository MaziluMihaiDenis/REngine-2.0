#pragma once

#include <Graphics/Structs/VertexArray.h>
#include <Graphics/Structs/ShaderProgram.h>
#include <Graphics/Structs/Texture.h>

#include <Application/API/Hints.h>
#include <External/Glad/glad.h>
#include <Graphics/Graphics.h>
#include <Engine/World.h>
#include <Core/Math.h>

#include "../../Structs/Transformation2D.h"

namespace RE
{
	class IRenderable
	{
		friend class Graphics;

	private:
		Texture* texture;
		ShaderProgram* shader;
		VertexArray* vertexArray;
		unsigned short indexCount;

	private:
		void Bind();
		void Unbind();
		void Render();

	public:
		void SetColor(float r, float g, float b, float a = 1.f);
		void SetTexture(const char* filename);
		void SetShader(const char* filename);
		void BufferData(struct Transformation2D& transform);
		void SetProjection(float* projection);

	public:
		IRenderable() = default;
		void Init(float *vertices, ushort va_size, 
				uint *indices, ushort ind_size,
				VertexLayout &layout
		);
	};
};