#include "Sprite.h"

RE::Sprite::Sprite()
{
	float vertices[] = {
		-1.f, -1.f,		0.f, 0.f,
		 1.f, -1.f,		1.f, 0.f,
		 1.f, 1.f,		1.f, 1.f,
		-1.f, 1.f,		0.f, 1.f
	};
	uint indices[]{ 0, 1, 2, 2, 3, 0 };
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

	IRenderable::Init(vertices, sizeof(vertices), 
		indices, sizeof(indices),
		layout
	);
	SetProjection(World::GetInstance()->GetCamera()->getProjectionMatrix());
}
