#include "SpriteComponent.h"
#include "WorldObject.h"

SpriteComponent::SpriteComponent()
{
	sprite = new Sprite();
}

void RE::SpriteComponent::Loop(float deltaTime)
{
	if (GetParent<WorldObject>()->Updated)
	{
		GetParent<WorldObject>()->Updated = false;
		sprite->BufferData(GetParent<WorldObject>()->transformation);
	}
}

Sprite* RE::SpriteComponent::GetSprite()
{
	return sprite;
}
