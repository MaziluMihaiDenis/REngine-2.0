#include "Application.h"
#include "API/reAPI.h"
#include <External/Glad/glad.h>

using namespace RE;

void RE::Application::Init()
{
	_re.Init();
	_re.api.init();
}

RE::Application::Application()
	: Background(Color(1.f, 1.f, 1.f)), MainWindow(0) {}

RE::Window* RE::Application::InstanceWindow()
{
	Window* window = new Window(_window_settings);
	window->Settings = _window_settings;
	MainWindow = window;
	window->MakeContextCurrent();
	return window;
}

void RE::Application::PollEvents(Window* window)
{
	_re.api.poll_events(window);
}

void RE::Application::SetBackgroundColor(Color color)
{
	Background = color;
}

void RE::Application::PreUpdate()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(
		Background.Red,
		Background.Green,
		Background.Blue,
		Background.Alpha
	);
	glViewport(0, 0, MainWindow->GetWidth(), MainWindow->GetHeight());
}

void RE::Application::SwapBuffers()
{
	_re.api.swap_buffers(MainWindow);
}

void RE::Application::Terminate()
{
	DestroyWindow(MainWindow);
}

int RE::Application::GetCurrentRunTime()
{
	return _re.api.get_current_runtime();
}

int RE::Application::GetFrequnecy()
{
	return _re.api.get_frequnecy();
}

Application* RE::Application::GetInstance()
{
	if (!Instance)
		Instance = new Application();
	return Instance;
}

Window& RE::Application::GetWindow()
{
	return *MainWindow;
}

RE::Application* RE::GetApplication()
{
	return RE::Application::GetInstance();
}
