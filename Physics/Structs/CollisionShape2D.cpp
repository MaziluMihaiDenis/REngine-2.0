#include "CollisionShape2D.h"
#include <Physics/Physics.h>

void RE::CollisionShape2D::OnCollisionEnter(WorldObject* hit)
{
}

void RE::CollisionShape2D::OnTriggerEnter(WorldObject* hit)
{
}

void RE::CollisionShape2D::OnCollisionExit(WorldObject* hit)
{
}

void RE::CollisionShape2D::OnTriggerExit(WorldObject* hit)
{
}

void RE::CollisionShape2D::SetReferencePoint(Vector2D& point)
{
}

void RE::CollisionShape2D::DrawDebug()
{
	if (ShowDebug)
	{
		Transformation2D trs;
		if (!DebugSprite)
		{
			DebugSprite = new Sprite();
			DebugSprite->SetColor(0.f, .5f, 0.f, .1f);
		}
		trs.Size = extent.Size;
		trs.Position = extent.ReferencePoint;
		DebugSprite->BufferData(trs);
	}
}

void RE::CollisionShape2D::Init()
{
	Component::Init();

	Mask = Layer = 1;
}

void RE::CollisionShape2D::Start()
{
	RE::Physics::GetInstance()->RegisterCollider(this);
}

void RE::CollisionShape2D::Loop(float deltaTime)
{
	extent.ReferencePoint = GetParent<WorldObject>()->GetPosition();
	DrawDebug();
}
