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

