#pragma once
#include "API/Window.h"
#include <Core/Color.h>
#include <vector>

namespace RE
{
	class Application
	{
		friend class Engine;
	private:
		Color Background;
		Window* MainWindow;
		inline static Application* Instance;

	public:
		Application();
		Window* InstanceWindow();

	public:
		void Init();
		void PollEvents(Window* window);
		void SetBackgroundColor(Color color);
		void SwapBuffers();
		void PreUpdate();
		void Terminate();
		int GetCurrentRunTime();
		int GetFrequnecy();

	public:
		static Application* GetInstance();
		Window& GetWindow();
	};

	extern RE::Application* GetApplication();
};

