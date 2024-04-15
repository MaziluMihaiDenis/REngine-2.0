#pragma once
#if defined(_WIN32)
#include "win32/win32API.h"
#else
#define WIN32_WINDOW
#define WIN32_LIBRARY
#define WIN32_CONTEXT
#define WIN32_INPUT
#endif // _WIN32

#define WINDOW_CLASS \
		WIN32_WINDOW

#define LIBRARY_CLASS \
		WIN32_LIBRARY

#define CONTEXT_CLASS \
		WIN32_CONTEXT

#define INPUT_CLASS \
		WIN32_INPUT