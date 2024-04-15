#pragma once

#include "Window.h"
#include "Context.h"

inline RE::ContextSettings _context_settings =
{
	1, 3, 3,
	false, false
};
inline RE::WindowSettings _window_settings = 
{
	NULL, "WINDOW_NAME",
	0, 0,
	1024, 768,
	0, 0,
	true, true, false, false
};

using namespace RE;

#define OPENGL_CORE_PROFILE 1
// idk if it works
#define OPENGL_COMPATIBILITY 0

#define SET_WINDOW_OFFSET(X, Y) \
	_window_settings.OffsetX = X; \
	_window_settings.OffsetY = Y;

#define SET_WINDOW_RESOLUTION(W, H) \
	_window_settings.Width = W; \
	_window_settings.Height = H;

#define SET_WINDOW_TITLE(TITLE) \
	_window_settings.Title = TITLE;

#define SET_WINDOW_SHARE(SHARE) \
	_window_settings.Share = SHARE;

#define SET_WINDOW_FOCUSED(VALUE) \
	_window_settings.Focused = VALUE;

#define SET_WINDOW_VISIBLE(VALUE) \
	_window_settings.Visible = VALUE;

#define SET_WINDOW_FULLSCREEN(VALUE) \
	_window_settings.Fullscreen = VALUE;

#define SET_WINDOW_DUMMY(VALUE) \
	_window_settings.dummy = VALUE;

#define SET_OPENGL_VERSION_MAJOR(MAJOR) \
	_context_settings.major = MAJOR;

#define SET_OPENGL_VERSION_MINOR(MINOR) \
	_context_settings.minor = MINOR;

#define SET_OPENGL_PROFILE(PROFILE) \
	_context_settings.profile = PROFILE;

#define SET_OPENGL_FORWARD_RENDERING(VALUE) \
	_context_settings.forward = VALUE;

#define SET_OPENGL_DUMMY(VALUE) \
	_context_settings.dummy = VALUE;

#define SET_WINDOW_STYLE(VALUE) \
	_window_settings.Style = VALUE;

#define SET_WINDOW_EXSTYLE(VALUE) \
	_window_settings.ExStyle = VALUE;