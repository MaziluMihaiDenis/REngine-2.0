#include "Engine.h"
#include "World.h"
#include <Application/Application.h>

void RE::Engine::Init()
{
	for (int i = 0; i < World::GetInstance()->WorldObjects.size(); i++)
		World::GetInstance()->WorldObjects[i]->Start();
}

void RE::Engine::Loop(float deltaTime)
{
	for (int i = 0; i < World::GetInstance()->WorldObjects.size(); i++)
		if (World::GetInstance()->WorldObjects[i]->Processing)
			World::GetInstance()->WorldObjects[i]->Loop(deltaTime);

}

void RE::Engine::End()
{
	Application::GetInstance()->MainWindow->SetRunning(false);
}

RE::Engine* RE::Engine::GetInstance()
{
	if (!Instance)
		Instance = new Engine();
	return Instance;
}
