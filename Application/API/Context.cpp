#include "Context.h"
#include "reAPI.h"

RE::Context::Context(RE::Window* parent, ContextSettings& settings)
{
	Settings = settings;
	Parent = parent;	
	parent->WindowContext = this;
	_re.api.create_context(this);
}

void RE::Context::Destroy()
{
	_re.api.destroy_context(this);
}

int RE::Context::GetProfile()
{
	return Settings.profile;
}

int RE::Context::GetMajorVersion()
{
	return Settings.major;
}

int RE::Context::GetMinorVersion()
{
	return Settings.minor;
}

bool RE::Context::GetIsDummy()
{
	return Settings.dummy;
}

bool RE::Context::GetUseForwardRendering()
{
	return Settings.forward;
}

RE::Window* RE::Context::GetParentWindow()
{
	return Parent;
}
