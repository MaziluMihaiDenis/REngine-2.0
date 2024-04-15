#pragma once

#include "Graphics/Sprite.h"
#include "Component.h"

namespace RE
{
	class SpriteComponent : public Component
	{
		Sprite* sprite;

	private:
		virtual void Loop(float deltaTime) override;
	public:
		SpriteComponent();
		Sprite* GetSprite();
	};
}

