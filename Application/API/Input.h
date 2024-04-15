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

template<class T, void(T::* Method)()>
inline void RE::Input::BindKeyEvent(int keyCode, int action, T* object)
{
	int i;
	for(i = 0; i < inpBuf.KeyEvents.size(); i++)
		if (inpBuf.KeyEvents[i].key == keyCode && inpBuf.KeyEvents[i].action == action)
			inpBuf.KeyEvents[i].callback.bind_member_function<T, Method>(object);

	Delegate<> deleg;
	deleg.bind_member_function<T, Method>(object);

	KeyEvent kEvent =
	{
		action,
		keyCode,
		deleg
	};

	inpBuf.KeyEvents.push_back(kEvent);
}

// win32
inline Vector2D RE::Input::GetMousePosition()
{
	Vector2D vec;
	_re.api.get_mouse_position(vec.x, vec.y);
	return vec;
}

