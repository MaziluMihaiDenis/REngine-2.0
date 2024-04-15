#include "Application/Application.h"
#include "Application/API/Hints.h"
#include "EnginePerformance.h"

#include <Engine/Structs/Transformation2D.h>
#include <Engine/Classes/SpriteComponent.h>
#include <Engine/Classes/WorldObject.h>
#include <Engine/Classes/UI/Panel.h>
#include <Application/API/Input.h>
#include <Graphics/Graphics.h>
#include <Physics/Physics.h>
#include <Core/Filesystem.h>
#include <Core/Delegate.h>
#include <Engine/Engine.h>
#include <Engine/World.h>
#include <Core/Math.h>
#include <iostream>
#include <thread>

#define NICE_COLOR .13f, .17f, .19f

void file_work_thread()
{
	Filesystem::MakeDirectory("", "Saves");
	Filesystem::MakeDirectory("Saves", "Game");
	Filesystem::ImportTextures("Resources/Textures");
}

void add_window_hints()
{
	SET_WINDOW_TITLE("NIGGA BALLS");
	SET_WINDOW_RESOLUTION(1024, 768);
	SET_WINDOW_OFFSET(0, 0);
	SET_WINDOW_STYLE(WS_OVERLAPPEDWINDOW);
	SET_WINDOW_EXSTYLE(0);
}

#include <Engine/Classes/Test.h>

void game_init()
{
	Test* test = RE::World::Instantiate<Test>();
	test->SetPosition(Vector2D(-384, 0));
	Test* test1 = RE::World::Instantiate<Test>();
	test1->SetPosition(Vector2D(384, 0));
	test1->axis = -1.f;

	Panel* panel = new Panel();
	panel->SetSize(Vector2D(1/10.f, 1/10.f));
	panel->anchorPoint = Vector2D(1.f, 1.f);
	panel->SetPosition(Vector2D(1/50.f, 1/50.f));
}

void lth()
{
	RE::Physics::GetInstance()->Loop();
}

int main()
{	
	int startTime;
	float deltaTime = 0.f;

	add_window_hints();

	RE::Window* window;

	LoaderThread = std::thread(file_work_thread);

	RE::SetKeyCallback(RE::KeyClbck);
	RE::GetApplication()->Init();

	window = RE::GetApplication()->InstanceWindow();
	RE::Graphics::GetInstance()->Init(window);
	RE::GetApplication()->SetBackgroundColor(Color(NICE_COLOR));

	LoaderThread.join();

	game_init();

	RE::Engine::GetInstance()->Init();

	while (window->GetIsRunning())
	{
		Vector2D mpos;
		mpos = Input::GetMousePosition();
		std::cout << mpos.x << " " << mpos.y << '\n';

		startTime = Application::GetInstance()->GetCurrentRunTime();
		RE::GetApplication()->PreUpdate();
		
		RE::Engine::GetInstance()->Loop(deltaTime);
		LogicThread = std::thread(lth);
		RE::Graphics::GetInstance()->Loop();
		LogicThread.join();

		RE::GetApplication()->SwapBuffers();
		RE::GetApplication()->PollEvents(window);
		deltaTime = (float)(RE::GetApplication()->GetCurrentRunTime() - startTime) / RE::GetApplication()->GetFrequnecy();
	}
	RE::GetApplication()->Terminate();

	return 0;
}