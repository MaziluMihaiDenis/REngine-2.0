#pragma once
#include "Object.h"

namespace RE
{
	class Component : public Object
	{
		friend class EmptyWorldObject;

	protected:
		class EmptyWorldObject* Parent;

	public:
		virtual void Loop(float deltaTime);

		template<class T>
		T* GetParent();
	};

	template<class T>
	inline T* Component::GetParent()
	{
		return Cast<T>(Parent);
	}
};
