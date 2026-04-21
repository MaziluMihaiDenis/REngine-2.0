#pragma once

#include "Platform.h"
#include <Engine/Structs/Vector2D.h>
#include <Application/Application.h>
#include <Core/Delegate.h>
#include <vector>

#define KEY_PRESS 1
#define KEY_HOLD 2
#define KEY_UP 0

namespace RE
{
	typedef void(*KeyCallback)(int, int);

	struct KeyEvent
	{
		int action, key;
		Delegate<> callback;
	};

	struct Input
	{
		friend void KeyClbck(int key, int action);
		friend void RE::_win32_handle_input();

	private:
		std::vector<KeyEvent> KeyEvents;
		int KeyState[256]{ 0 };

	public:
		template<class T, void(T::* Method)()>
		static void BindKeyEvent(int keyCode, int action, T* object);
		static Vector2D GetMousePosition();
	};

	extern Input inpBuf;

	void SetKeyCallback(KeyCallback callback);
	void KeyClbck(int key, int action);
};

