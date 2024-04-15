#include "win32API.h"
#include "../reAPI.h"

#include <External/Glad/glad_wgl.h>
#include <Core/StringFunctions.h>
#include <External/Glad/glad.h>
#include <EnginePerformance.h>
#include <Graphics/Graphics.h>
#include <thread>

LRESULT CALLBACK _winProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
	if (LogicThread.joinable())
		LogicThread.join();

	Window* window = (Window*)GetProp(hwnd, L"RE");

	if (window)
	{
		switch (msg)
		{
		case WM_CLOSE:
			window->SetRunning(false); 
			break;
		case WM_QUIT:
			break;
		case WM_KEYDOWN:
		case WM_KEYUP:
 			LogicThread = std::thread(_win32_handle_input);
			break;
		case WM_SIZE:
			window->Settings.Width = LOWORD(lparam);
			window->Settings.Height = HIWORD(lparam);
			break;
		}
	}

	return DefWindowProc(hwnd, msg, wparam, lparam);
}

void RE::win32_init()
{
	_re.win32 = new win32Library;

	_re.win32->Instance = GetModuleHandle(0);

	// create a false context
	Window* dummy_window;
	WindowSettings settings =
	{
		NULL, "DUMMY", 0, 0, 100, 100, 0, 0, false, false, false, true
	};

	dummy_window = new Window(settings);

	// initialize gl
	gladLoadGL();
	gladLoadWGL(GetDC(dummy_window->win32->Handle));

	RE::DestroyWindow(dummy_window);

	// initialize time
	LARGE_INTEGER lint;
	QueryPerformanceFrequency(&lint);
	_re.win32->Frequnecy = lint.QuadPart;
}

void RE::win32_connect()
{
	_re.api = RE::Library::API
	{
		win32_init,
		win32_instance_window,
		win32_set_window_visibility, 
		win32_set_window_focused,
		win32_set_window_fullscreen,
		win32_modify_window,
		win32_modify_window_title,
		win32_destroy_window,
		win32_create_context,
		win32_make_context_current,
		win32_destroy_context,
		win32_poll_events,
		win32_swap_buffers,
		win32_get_current_runtime,
		win32_get_frequnecy,
		win32_get_monitor_resolution,
		_win32_get_mouse_position
	};
}

#include <iostream>

void RE::win32_instance_window(Window* window)
{
	const wchar_t CLASS[] = L"RE";
	WNDCLASS wndClass = {};
	std::wstring wstring = {};
	const wchar_t* wchr;

	window->win32 = new win32Window();

	wstring = StringToWideString(window->GetTitle());
	wchr = wstring.c_str();

	wndClass.hInstance = _re.win32->Instance;
	wndClass.lpfnWndProc = _winProc;
	wndClass.lpszClassName = CLASS;

	RegisterClass(&wndClass);

	window->win32->Handle = CreateWindowEx(
		window->Settings.ExStyle,
		CLASS,
		wchr,
		window->Settings.Style,
		window->GetOffsetX(), window->GetOffsetY(),
		window->GetWidth(), window->GetHeight(),
		(window->Settings.Share == NULL ?
			NULL : window->Settings.Share->win32->Handle),
		NULL, 
		_re.win32->Instance,
		NULL
	);

	window->win32->Handle;

	win32_set_window_visibility(window, window->GetIsVisible());
	win32_set_window_focused(window, window->GetIsFocused());
}

void RE::win32_set_window_visibility(Window* window, bool value)
{
	ShowWindow(window->win32->Handle, 
		(window->Settings.Visible ? SW_SHOW : SW_HIDE)
	);
}

void RE::win32_set_window_focused(Window* window, bool value)
{
	if (window->Settings.Focused)
		SetProp(window->win32->Handle, L"RE", window);
	else
		RemoveProp(window->win32->Handle, L"RE");
}

void RE::win32_set_window_fullscreen(Window* window, bool value)
{
	if (value == window->Settings.Fullscreen)
		return;
	if (!window)
		return;

	if (value)
	{
		window->oldSettings = window->Settings;

		SetFocus(window->win32->Handle);

		SetWindowLong(
			window->win32->Handle, 
			GWL_STYLE, 
			window->Settings.Style & ~(WS_CAPTION | WS_THICKFRAME)
		);

		//SetWindowLong(
		//	window->win32->Handle,
		//	GWL_EXSTYLE,
		//	window->Settings.ExStyle & ~(WS_EX_DLGMODALFRAME |
		//	WS_EX_WINDOWEDGE | WS_EX_CLIENTEDGE | WS_EX_STATICEDGE)
		//);

		SetWindowPos(
			window->win32->Handle,
			HWND_NOTOPMOST,
			0, 0,
			1920, 1080,
			SWP_FRAMECHANGED | SWP_NOACTIVATE | SWP_SHOWWINDOW
		);

		window->Settings.Fullscreen = true;
	}
	else
	{
		window->Settings = window->oldSettings;
		SetWindowLong(
			window->win32->Handle,
			GWL_STYLE,
			window->Settings.Style
		);

		//SetWindowLong(
		//	window->win32->Handle,
		//	GWL_EXSTYLE,
		//	window->Settings.ExStyle
		//);

		SetWindowPos(
			window->win32->Handle,
			NULL,
			window->Settings.OffsetX, window->Settings.OffsetY,
			window->Settings.Width, window->Settings.Height,
			SWP_NOZORDER | SWP_NOACTIVATE | SWP_FRAMECHANGED
		);

		window->Settings.Fullscreen = false;

		SendMessage(window->win32->Handle, WM_PAINT, 0, 0);
	}
}

void RE::win32_modify_window(Window* window)
{
	SetWindowPos(
		window->win32->Handle,
		HWND_NOTOPMOST,
		window->GetOffsetX(), window->GetOffsetY(),
		window->GetWidth(), window->GetHeight(),
		SWP_NOZORDER
	);
}

void RE::win32_modify_window_title(Window* window)
{
	std::wstring wstring;
	const wchar_t* wchr;

	wstring = StringToWideString(window->GetTitle());
	wchr = wstring.c_str();

	SetWindowText(
		window->win32->Handle,
		wchr
	);
}

void RE::win32_destroy_window(Window* window)
{
	DestroyWindow(window->win32->Handle);
	delete window->win32;
	window->win32 = nullptr;
}

void RE::win32_create_context(Context* context)
{
	if (context->GetIsDummy())
		_win32_create_context(context);
	else
		_wgl_create_context(context);
}

void RE::win32_make_context_current(Window* window)
{
	if (!window)
	{
		wglMakeCurrent(NULL, NULL);

		return;
	}

	HDC dc = GetDC(window->win32->Handle);
	HGLRC GLrc = window->WindowContext->win32->Context;
	wglMakeCurrent(dc, GLrc);
}

void RE::_win32_create_context(Context* context)
{
	int pixelFormat;
	HDC dc;
	HWND handle;
	PIXELFORMATDESCRIPTOR pfd;

	context->win32 = new win32Context();

	// Getting the pixel format
	pfd = {
		sizeof(PIXELFORMATDESCRIPTOR),
		1,
		PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,    
		PFD_TYPE_RGBA,        
		32,                   
		0, 0, 0, 0, 0, 0,
		0,
		0,
		0,
		0, 0, 0, 0,
		24,                   
		8,                    
		0,                    
		PFD_MAIN_PLANE,
		0,
		0, 0, 0
	};
	handle = context->GetParentWindow()->win32->Handle;
	dc = GetDC(handle);
	pixelFormat = ChoosePixelFormat(dc, &pfd);
	SetPixelFormat(dc, pixelFormat, &pfd);

	context->win32->Context = wglCreateContext(dc);
	wglMakeCurrent(dc, context->win32->Context);

	ReleaseDC(handle, dc);
}

void RE::_wgl_create_context(Context* context)
{
	HDC dc;
	HWND handle;
	UINT numFormats;
	PIXELFORMATDESCRIPTOR pfd = { 0 };
	int pixelFormat;
	int openGLAttributes[] = {
			WGL_CONTEXT_MAJOR_VERSION_ARB, context->GetMajorVersion(),
			WGL_CONTEXT_MINOR_VERSION_ARB, context->GetMinorVersion(),
			WGL_CONTEXT_PROFILE_MASK_ARB, context->GetProfile(),
			context->GetUseForwardRendering()
	};
	int attribList[] = {
		WGL_DRAW_TO_WINDOW_ARB, TRUE,
		WGL_SUPPORT_OPENGL_ARB, TRUE,
		WGL_DOUBLE_BUFFER_ARB, TRUE,
		WGL_ACCELERATION_ARB, WGL_FULL_ACCELERATION_ARB,
		WGL_PIXEL_TYPE_ARB, WGL_TYPE_RGBA_ARB,
		WGL_COLOR_BITS_ARB, 32,
		WGL_DEPTH_BITS_ARB, 24,
		WGL_STENCIL_BITS_ARB, 8,
		0
	};

	handle = context->GetParentWindow()->win32->Handle;
	dc = GetDC(handle);
	context->win32 = new win32Context;

	if (wglChoosePixelFormatARB(dc, attribList, NULL, 1, &pixelFormat, &numFormats))
	{
		DescribePixelFormat(dc, pixelFormat, sizeof(PIXELFORMATDESCRIPTOR), &pfd);
		SetPixelFormat(dc, pixelFormat, &pfd);
		context->win32->Context = wglCreateContextAttribsARB(dc, NULL, openGLAttributes);
	}

	ReleaseDC(handle, dc);
}

void RE::win32_destroy_context(Context* context)
{
	wglDeleteContext(context->win32->Context);
	delete context->win32;
	context->win32 = nullptr;
}

void RE::win32_poll_events(Window* window)
{
	MSG msg = {};
	while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}

void RE::win32_swap_buffers(Window* window)
{
	HDC dc = GetDC(window->win32->Handle);
	SwapBuffers(dc);
	ReleaseDC(window->win32->Handle, dc);
}

void RE::_win32_handle_input()
{
	int i;
	_re.callbacks.keyCallback;

	for (i = 0; i < 256; i++)
	{
		if (GetAsyncKeyState(i) & 0x01)
			inpBuf.KeyState[i] = (inpBuf.KeyState[i] == 1 ? 2 : 1);
		else
			inpBuf.KeyState[i] = 0;

		_re.callbacks.keyCallback(i, inpBuf.KeyState[i]);
	}
}

void RE::_win32_get_mouse_position(float &x, float &y)
{
	POINT mpos;

	if (!GetCursorPos(&mpos) || !ScreenToClient(GetActiveWindow(), &mpos))
		return;

	x = mpos.x;	
	y = mpos.y;
}

int RE::win32_get_current_runtime()
{
	LARGE_INTEGER lint;
	QueryPerformanceCounter(&lint);
	return lint.QuadPart;
}

int RE::win32_get_frequnecy()
{
	return _re.win32->Frequnecy;
}

void RE::win32_get_monitor_resolution(Window* window, int& width, int& height)
{
	HMONITOR monitor;
	MONITORINFO info;

	info.cbSize = sizeof(MONITORINFO);
	monitor = MonitorFromWindow(window->win32->Handle, MONITOR_DEFAULTTOPRIMARY);
	GetMonitorInfo(monitor, &info);

	width = info.rcMonitor.right - info.rcMonitor.left;
	height = info.rcMonitor.top - info.rcMonitor.bottom;
}
