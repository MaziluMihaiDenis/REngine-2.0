#pragma once

#include "Object.h"
#include "Component.h"
#include <string>

namespace RE
{
	class EmptyWorldObject : public Object
	{
	private:
		std::vector<EmptyWorldObject*> Children;
		std::vector<Component*> Components;
		EmptyWorldObject* Parent;
	public:
		char* Name;

	public:
		virtual void Start();
		virtual void Loop(float deltaTime) override;

	public:
		template<class T>
		void AddComponent();

		void RemoveComponent(Component* component);

		template<class T>
		T* GetComponent();

	public:
		void AddChild(EmptyWorldObject* child);
		void RemoveChild(EmptyWorldObject* child);
		std::vector<EmptyWorldObject*> GetChildren();
		Object* GetChildByName(const char* name);
		/// 0 = first child
		Object* GetChildByIndex(int index);
		void SetParent(EmptyWorldObject* wObj);
		template<class T>
		T* GetParent();
	};

	template<class T>
	inline void EmptyWorldObject::AddComponent()
	{
		Component* component;
		component = new T();
		component->Parent = this;
		component->Init();
		Components.push_back(component);
	}

	template<class T>
	inline T* EmptyWorldObject::GetComponent()
	{
		for (Component* comp : Components)
			if (NAME_OF_CLASS(*comp) == NAME_OF_CLASS(T))
				return (T*)comp;
		return nullptr;
	}

	template<class T>
	inline T* EmptyWorldObject::GetParent()
	{
		return (T*)Parent;
	}
};