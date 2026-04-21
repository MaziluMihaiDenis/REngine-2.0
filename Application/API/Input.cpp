#include "Input.h"
#include "reAPI.h"

RE::Input RE::inpBuf;

void RE::SetKeyCallback(KeyCallback callback)
{
	_re.callbacks.keyCallback = callback;
}

void RE::KeyClbck(int key, int action)
{
	int i;
	for (i = 0; i < inpBuf.KeyEvents.size(); i++)
	{
		if (inpBuf.KeyEvents[i].key == key && inpBuf.KeyEvents[i].action == action)
			inpBuf.KeyEvents[i].callback();
	}
}

template<class T, void(T::* Method)()>
void RE::Input::BindKeyEvent(int keyCode, int action, T* object)
{
	int i;
	for (i = 0; i < inpBuf.KeyEvents.size(); i++)
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

Vector2D RE::Input::GetMousePosition()
{
	Vector2D vec;
	_re.api.get_mouse_position(vec.x, vec.y);
	return vec;
}

