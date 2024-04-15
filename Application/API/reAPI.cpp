#include "reAPI.h"

RE::Library RE::_re;

void RE::Library::Init()
{
#if defined(_WIN32)
	win32_connect();
#endif
}

void RE::DestroyWindow(Window*& window)
{
	window->Destroy();
	delete window;
	window = nullptr;
}

void RE::DestroyContext(Context*& context)
{
	context->Destroy();
	delete context;
}
