#include "Panel.h"

Panel::Panel()
{
	float vertices[16] = {
		-1.f, -1.f,		0.f, 0.f,
		 1.f, -1.f,		1.f, 0.f,
		 1.f, 1.f,		1.f, 1.f,
		-1.f, 1.f,		0.f, 1.f
	};
	float projection[] =
	{
		1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1
	};
	uint indices[6] =
	{ 0, 1, 2, 2, 3, 0 };

	VertexLayout layout;

	layout.AddElement({
		sizeof(float),
		GL_FLOAT,
		2,
		GL_FALSE
	});

	layout.AddElement({
		sizeof(float),
		GL_FLOAT,
		2,
		GL_FALSE
	});

	IRenderable::Init(
		vertices, sizeof(vertices),
		indices, sizeof(indices),
		layout
	);
	SetProjection(projection);
}

void Panel::SetPosition(Vector2D position)
{
	transform.Position = anchorPoint - position;
	BufferData(transform);
}

void Panel::SetSize(Vector2D size)
{
	transform.Size = size;
	BufferData(transform);
}