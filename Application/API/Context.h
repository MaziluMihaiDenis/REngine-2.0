#pragma once

#include "Platform.h"

namespace RE
{
	struct ContextSettings
	{
		int profile, major, minor;
		bool dummy, forward;
	};

	class Context
	{
		ContextSettings Settings;
		Window* Parent;

	public:
		CONTEXT_CLASS

	public:
		Context(Window* parent, ContextSettings &settings);
		void Destroy();
	public:
		int GetProfile();
		int GetMajorVersion();
		int GetMinorVersion();
		bool GetIsDummy();
		bool GetUseForwardRendering();
		Window* GetParentWindow();
	};
};

