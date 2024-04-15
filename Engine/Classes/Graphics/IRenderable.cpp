#include "IRenderable.h"

void RE::IRenderable::Bind()
{
	if (texture) 
		texture->Bind();
	shader->Bind();
	vertexArray->Bind();
}

void RE::IRenderable::Unbind()
{
	if (texture) 
		texture->Unbind();
	vertexArray->Unbind();
	shader->Unbind();
}

void RE::IRenderable::Render()
{
	Bind();
	glDrawElements(
		GL_TRIANGLES,
		indexCount,
		GL_UNSIGNED_INT,
		NULL
	);
	Unbind();
}

void RE::IRenderable::SetColor(float r, float g, float b, float a)
{
	shader->Bind();
	shader->SetUniform4f("u_color", r, g, b, a);
}

void RE::IRenderable::SetTexture(const char* filename)
{
	if (texture)
		texture->~Texture();
	texture = new Texture(filename);
	shader->Bind();
	shader->SetUniform1i("u_tex", texture->Slot);
}

void RE::IRenderable::SetShader(const char* filename)
{
	//..
}

void RE::IRenderable::BufferData(RE::Transformation2D& transform)
{
	float* matrix = transform.GetMatrix();
	glUseProgram(shader->ID);
	shader->SetUniform4fMatrix("matrix", matrix);
	delete matrix;
}

void RE::IRenderable::SetProjection(float* projection)
{
	glUseProgram(shader->ID);
	shader->SetUniform4fMatrix("projection", projection);
}

void RE::IRenderable::Init(float* vertices, ushort va_size, 
	uint* indices, ushort ind_size,
	VertexLayout &layout
)
{
	vertexArray = new VertexArray(vertices, va_size, 
		indices, ind_size,
		layout
	);
	shader = new ShaderProgram();
	SetTexture("Resources/Textures/square.png");
	indexCount = ind_size;

	RE::Graphics::GetInstance()->RegisterDisplayObject(this);
	SetColor(1, 1, 1);
}