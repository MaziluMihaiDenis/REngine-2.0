#pragma once

#include <string>
#include "Platform.h"

namespace RE
{
	struct WindowSettings
	{
		Window* Share = NULL;
		std::string Title = 0;
		long Style = 0, ExStyle = 0;
		int Width = 0, Height = 0;
		int OffsetX = 0, OffsetY = 0;
		bool Focused = false, Visible = false, Fullscreen = false, dummy = false;
	};

	class Window
	{
	private:
		bool Running;

	public:
		Context* WindowContext;
		WindowSettings Settings;
		WindowSettings oldSettings;
		WINDOW_CLASS

	public:
		// Creates a dummy window
		Window();
		Window(WindowSettings &settings);
		void Destroy();

	public:
		int GetWidth();
		int GetHeight(); 
		int GetOffsetX();
		int GetOffsetY();
		bool GetIsRunning();
		bool GetIsFocused();
		bool GetIsVisible();
		bool GetIsFullscreen();
		std::string GetTitle();
	public:
		void SetWidth(int width);
		void SetHeight(int height);
		void SetRunning(bool value);
		void SetFocused(bool value);
		void SetVisible(bool value);
		void SetFullscreen();
		void SetWindowed();
		void SetOffsetX(int x);
		void SetOffsetY(int y);
		// No need to call "Reconstruct"
		void SetTitle(std::string title);
		// Called after modifying the window
		void Reconstruct();
	public:
		void MakeContextCurrent();
		void ClearContextCurrent();
	};
};

