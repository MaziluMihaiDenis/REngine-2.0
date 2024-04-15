#pragma once
#include "WorldObject.h"
#include "SpriteComponent.h"
#include <Physics/Structs/CollisionShape2D.h>

class Test : public RE::WorldObject
{
private:
	RE::SpriteComponent* sprite;
	RE::CollisionShape2D* shape;
public:
	float axis = 1.f;

public:
	virtual void Init() override;
	virtual void Start() override;
	virtual void Loop(float deltaTime) override;
};

