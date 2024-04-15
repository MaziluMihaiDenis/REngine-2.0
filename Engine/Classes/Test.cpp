#include "Test.h"

void Test::Init()
{
	RE::WorldObject::Init();

	AddComponent<RE::CollisionShape2D>();
	AddComponent<RE::SpriteComponent>();
}

void Test::Start()
{
	RE::WorldObject::Start();

	sprite = GetComponent<RE::SpriteComponent>();
	shape = GetComponent<RE::CollisionShape2D>();

	sprite->GetSprite()->SetTexture("Resources/Textures/SwagGorilla.png");

	shape->Shape = EShape::RECTANGLE;
	shape->extent.Size = Vector2D(100, 100);
	shape->ShowDebug = true;
}

void Test::Loop(float deltaTime)
{
	RE::WorldObject::Loop(deltaTime);

	int scl = 50;

	SetRotation(GetRotation() + deltaTime * scl);
	SetPosition(Vector2D(axis * deltaTime * scl, 0.f) + GetPosition());
}
