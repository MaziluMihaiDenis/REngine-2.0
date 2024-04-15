#include "Physics.h"

void RE::Physics::Init()
{

}

void RE::Physics::Loop()
{
	int i, j, size;

	size = RegisteredColliders.size();

	for (i = 0; i < size - 1; i++)
		for (j = i + 1; j < size; j++)
		{
			if (RegisteredColliders[i]->Trigger == RegisteredColliders[j]->Trigger) continue;
			if (!TestCollision(RegisteredColliders[i], RegisteredColliders[j])) continue;
			if (!HandleCollision(RegisteredColliders[i], RegisteredColliders[j])) continue;

			WorldObject* iparent, * jparent;

			iparent = RegisteredColliders[i]->GetParent<WorldObject>();
			jparent = RegisteredColliders[j]->GetParent<WorldObject>();

			if (RegisteredColliders[i]->Trigger)
			{
				RegisteredColliders[j]->OnCollisionEnter(jparent);
				RegisteredColliders[i]->OnTriggerEnter(jparent);
			}
			else
			{
				RegisteredColliders[i]->OnCollisionEnter(jparent);
				RegisteredColliders[j]->OnTriggerEnter(jparent);
			}
		}
}

bool RE::Physics::HandleCollision(RE::CollisionShape2D* a, RE::CollisionShape2D* b)
{
	if (a->Mask != b->Layer)
		return 0;

	if (a->Shape == b->Shape)
	{
		if (a->Shape == RECTANGLE)
			return HandleRRCollision(a, b);
		return HandleCCCollision(a, b);
	}
	if(a->Shape == RECTANGLE)
		return HandleRCCollision(a, b);
	return HandleRCCollision(b, a);
}

bool RE::Physics::HandleRRCollision(RE::CollisionShape2D* a, RE::CollisionShape2D* b)
{
	float minY = (a->extent.ReferencePoint.y - a->extent.Size.y / 2) - (b->extent.ReferencePoint.y + b->extent.Size.y / 2);
	float maxY = (a->extent.ReferencePoint.y + a->extent.Size.y / 2) - (b->extent.ReferencePoint.y - b->extent.Size.y / 2);
	return minY >= 0 || maxY >= 0;
}

bool RE::Physics::HandleRCCollision(RE::CollisionShape2D* a, RE::CollisionShape2D* b)
{
	Vector2D circleDiff = Vector2D(
		abs(a->extent.ReferencePoint.x - b->extent.ReferencePoint.x),
		abs(a->extent.ReferencePoint.y - b->extent.ReferencePoint.y)
	);

	if (circleDiff.x > (a->extent.Size.x / 2 + b->extent.Size.x))
		return false;
	if (circleDiff.y > (a->extent.Size.y / 2 + b->extent.Size.y))
		return false;

	if (circleDiff.x <= a->extent.Size.x / 2)
		return true;
	if (circleDiff.y <= a->extent.Size.y / 2)
		return true;

	float dist = (circleDiff.x - a->extent.Size.x / 2) * (circleDiff.x - a->extent.Size.x / 2) +
				 (circleDiff.y - a->extent.Size.y / 2) * (circleDiff.y - a->extent.Size.y / 2);
	return (dist <= b->extent.Size.x * b->extent.Size.x);
}

bool RE::Physics::HandleCCCollision(RE::CollisionShape2D* a, RE::CollisionShape2D* b)
{
	float dist = a->extent.ReferencePoint.Distance(b->extent.ReferencePoint);
	return dist <= a->extent.Size.x + b->extent.Size.x;
}

bool RE::Physics::TestCollision(RE::CollisionShape2D* a, RE::CollisionShape2D* b)
{
	float minX = (a->extent.ReferencePoint.x - a->extent.Size.x) - (b->extent.ReferencePoint.x + b->extent.Size.x);
	float maxX = (a->extent.ReferencePoint.x + a->extent.Size.x) - (b->extent.ReferencePoint.x - b->extent.Size.x);
	std::cout << minX << " " << maxX << '\n';
	return minX >= 0 || maxX >= 0;
}
	
void RE::Physics::RegisterCollider(RE::CollisionShape2D* collider)
{
	RegisteredColliders.push_back(collider);
}

void RE::Physics::UnregisterCollider(RE::CollisionShape2D* collider)
{
	for(int i = 0; i < RegisteredColliders.size(); i++)
		if(collider == RegisteredColliders[i])
			RegisteredColliders.erase(RegisteredColliders.begin() + i);
}

RE::Physics* RE::Physics::GetInstance()
{
	if (!Instance)
		Instance = new Physics();
	return Instance;
}
