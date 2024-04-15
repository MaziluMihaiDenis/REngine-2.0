#include "Graphics.h"
#include <External/Glad/glad.h>
#include <External/stb_image/stb_image.h>
#include <Application/Application.h>
#include <Application/API/Hints.h>

void RE::Graphics::Init(RE::Window* window)
{
	stbi_set_flip_vertically_on_load(1);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void RE::Graphics::Loop()
{
	for (IRenderable* object : RegisteredObjects)
		object->Render();
}

void RE::Graphics::UpdateViewport()
{
	glViewport(0, 0, _window_settings.Width, _window_settings.Height);
}

void RE::Graphics::RegisterDisplayObject(IRenderable* object)
{
	RegisteredObjects.push_back(object);
}

void RE::Graphics::UnregisterDisplayObject(IRenderable* object)
{
	for (std::vector<IRenderable*>::iterator i = RegisteredObjects.begin(); i != RegisteredObjects.end(); i++)
		if (*i == object)
		{
			RegisteredObjects.erase(i);
			break;
		}
}

RE::Graphics* RE::Graphics::GetInstance()
{
	if (Instance == nullptr)
		Instance = new Graphics();
	return Instance;
}
