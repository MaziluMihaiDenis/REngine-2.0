#include "Window.h"
#include "reAPI.h"

using namespace RE;

Window::Window(WindowSettings &settings)
	: Settings(settings), oldSettings(settings), Running(true)
{
	SET_OPENGL_DUMMY(settings.dummy);
	_re.api.instance_window(this);
	WindowContext = new Context(this, _context_settings);
}

Window::Window()
{
	ContextSettings ctxsett =
	{
		0, 0, 0,
		true, false
	};
	_re.api.instance_window(this);
	WindowContext = new Context(this, ctxsett);
}

void RE::Window::Destroy()
{
	SetRunning(false);

	WindowContext->Destroy();
	delete WindowContext;
	WindowContext = nullptr;

	_re.api.destroy_window(this);
}

int RE::Window::GetWidth()
{
	return Settings.Width;
}

int RE::Window::GetHeight()
{
	return Settings.Height;
}

int RE::Window::GetOffsetX()
{
	return Settings.OffsetX;
}

int RE::Window::GetOffsetY()
{
	return Settings.OffsetY;
}

bool RE::Window::GetIsRunning()
{
	return Running;
}

bool RE::Window::GetIsFocused()
{
	return Settings.Focused;
}

bool RE::Window::GetIsVisible()
{
	return Settings.Visible;
}

bool RE::Window::GetIsFullscreen()
{
	return Settings.Fullscreen;
}

std::string RE::Window::GetTitle()
{
	return Settings.Title;
}

void RE::Window::SetWidth(int width)
{
	Settings.Width = width;
}

void RE::Window::SetHeight(int height)
{
	Settings.Height = height;
}

void RE::Window::SetRunning(bool value)
{
	Running = value;
}

void RE::Window::SetFocused(bool value)
{
	Settings.Focused = value;
	_re.api.set_window_focused(this, value);
}

void RE::Window::SetVisible(bool value)
{
	Settings.Visible = value;
	_re.api.set_window_visibility(this, value);
}

void RE::Window::SetFullscreen()
{
	_re.api.set_window_fullscreen(this, true);
}

void RE::Window::SetWindowed()
{
	_re.api.set_window_fullscreen(this, false);
}
 
void RE::Window::SetOffsetX(int x)
{
	Settings.OffsetX = x;
}

void RE::Window::SetOffsetY(int y)
{
	Settings.OffsetY = y;
}

void RE::Window::SetTitle(std::string title)
{
	Settings.Title = title;

	_re.api.modify_title(this);
}

void RE::Window::Reconstruct()
{
	_re.api.modify_window(this);
}

void RE::Window::MakeContextCurrent()
{
	_re.api.make_context_current(this);
}

void RE::Window::ClearContextCurrent()
{
}

