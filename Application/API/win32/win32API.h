#pragma once
#include <Windows.h>

#define WIN32_WINDOW RE::win32Window* win32;
#define WIN32_LIBRARY RE::win32Library* win32;
#define WIN32_CONTEXT RE::win32Context* win32;

namespace RE
{
	struct win32Window
	{
		HWND Handle;
	};

	struct win32Context
	{
		HGLRC Context;
	};

	struct win32Library
	{
		HINSTANCE Instance;
		long long Frequnecy = 1LL;
	};

	void win32_init();
	void win32_connect();
	void win32_instance_window(class Window* window);
	void win32_set_window_visibility(class Window* window, bool value);
	void win32_set_window_focused(class Window* window, bool value);
	void win32_set_window_fullscreen(class Window* window, bool value);
	void win32_modify_window(class Window* window);
	void win32_modify_window_title(class Window* window);
	void win32_destroy_window(class Window* window);
	void win32_create_context(class Context* context);
	void win32_make_context_current(class Window* window);
	void _win32_create_context(class Context* context);
	void _wgl_create_context(class Context* context);
	void win32_destroy_context(class Context* context);
	void win32_poll_events(class Window* window);
	void win32_swap_buffers(class Window* window);
	void _win32_handle_input();
	void _win32_get_mouse_position(float &x, float &y);
	int win32_get_current_runtime();
	int win32_get_frequnecy();
	void win32_get_monitor_resolution(class Window* window, int& width, int& height);
}