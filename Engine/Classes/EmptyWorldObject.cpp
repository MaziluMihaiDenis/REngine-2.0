#include "EmptyWorldObject.h"

void RE::EmptyWorldObject::Start()
{
	for (int i = 0; i < Components.size(); i++)
		Components[i]->Start();
}

void RE::EmptyWorldObject::Loop(float deltaTime)
{
	for (EmptyWorldObject*& child : Children)
		if(child->Processing)
			child->Loop(deltaTime);
	for (Component*& component : Components)
		if (component->Processing)
			component->Loop(deltaTime);
}

void RE::EmptyWorldObject::RemoveComponent(RE::Component* component)
{
	for (int i = 0; i < Components.size(); i++)
		if (component == Components[i])
		{
			Components[i]->Parent = NULL;
			Components.erase(Components.begin() + i);
			break;
		}
}

void RE::EmptyWorldObject::AddChild(EmptyWorldObject* child)
{
	child->SetParent(this);
}

void RE::EmptyWorldObject::RemoveChild(RE::EmptyWorldObject* child)
{
	for (std::vector<RE::EmptyWorldObject*>::iterator i = Children.begin(); i != Children.end(); i++)
		if (child == *i)
		{
			Children.erase(i);
			break;
		}
	child->SetParent(nullptr);
}

std::vector<RE::EmptyWorldObject*> RE::EmptyWorldObject::GetChildren()
{
	return Children;
}

RE::Object* RE::EmptyWorldObject::GetChildByName(const char* name)
{
	for(EmptyWorldObject* child : Children)
		if(child->Name == name)
			return child;
	return nullptr;
}

RE::Object* RE::EmptyWorldObject::GetChildByIndex(int index)
{
	return nullptr;
}

void RE::EmptyWorldObject::SetParent(RE::EmptyWorldObject* wObj)
{
	Parent = wObj;
}
