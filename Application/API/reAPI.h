#pragma once
#include "Window.h"
#include "Platform.h"
#include "Input.h"
#include "Environment.h"
#include "Context.h"
#include "Hints.h"

namespace RE
{
	struct Library
	{
		struct API
		{
			void(*init)();
			void(*instance_window)(Window*);
			void(*set_window_visibility)(Window*, bool);
			void(*set_window_focused)(Window*, bool);
			void(*set_window_fullscreen)(Window*, bool);
			void(*modify_window)(Window*);
			void(*modify_title)(Window*);
			void(*destroy_window)(Window*);
			void(*create_context)(Context*);
			void(*make_context_current)(Window*);
			void(*destroy_context)(Context*);
			void(*poll_events)(Window*);
			void(*swap_buffers)(Window*);
			int(*get_current_runtime)();
			int(*get_frequnecy)();
			void(*get_monitor_resolution)(Window*, int&, int&);
			void(*get_mouse_position)(float&, float&);
		} api;

		struct
		{
			KeyCallback keyCallback;
		} callbacks;

		void Init();

		LIBRARY_CLASS
	};

	void SetKeyCallback(KeyCallback callback);
	void DestroyWindow(Window*& window);
	void DestroyContext(Context*& context);

	extern Library _re;
};
