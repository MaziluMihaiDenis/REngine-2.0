#include "WorldObject.h"

void RE::WorldObject::SetPosition(const Vector2D& translation)
{
	transformation.Position = translation;
	Updated = true;

	if (WorldObject* parent = GetParent<WorldObject>())
		transformation.RelativePosition = parent->GetPosition() - translation;

	Vector2D childPos;
	for (EmptyWorldObject* child : GetChildren())
		if (WorldObject* wObj = (WorldObject*)child)
		{
			childPos = translation + wObj->GetRelativePosition();
			wObj->SetPosition(childPos);
		}
}

void RE::WorldObject::SetSize(const Vector2D& scale)
{
	transformation.Size = scale;
	Updated = true;

	if (WorldObject* parent = GetParent<WorldObject>())
		transformation.RelativeSize = parent->GetSize() - scale;

	Vector2D childSize;
	for (EmptyWorldObject* child : GetChildren())
		if (WorldObject* wObj = (WorldObject*)child)
		{
			childSize = scale + wObj->GetRelativeSize();
			wObj->SetSize(childSize);
		}
}

void RE::WorldObject::SetRotation(float rotation)
{
	transformation.Rotation = rotation;
	Updated = true;

	if (WorldObject* parent = GetParent<WorldObject>())
		transformation.RelativeRotation = parent->GetRotation() - rotation;

	for (EmptyWorldObject* child : GetChildren())
		if (WorldObject* wObj = (WorldObject*)child)
			wObj->SetRotation(rotation + wObj->GetRelativeRotation());
}

void RE::WorldObject::SetRelativePosition(Vector2D& translation)
{
	// TO DO
}

void RE::WorldObject::SetRelativeSize(Vector2D& scale)
{
	// TO DO
}

void RE::WorldObject::SetRelativeRotation(float rotation)
{
	// TO DO
}

Vector2D RE::WorldObject::GetPosition() const
{
	return transformation.Position;
}

Vector2D RE::WorldObject::GetSize() const
{
	return transformation.Size;
}

float RE::WorldObject::GetRotation() const
{
	return transformation.Rotation;
}

Vector2D RE::WorldObject::GetRelativePosition() const
{
	return transformation.RelativePosition;
}

Vector2D RE::WorldObject::GetRelativeSize() const
{
	return transformation.RelativeSize;
}

float RE::WorldObject::GetRelativeRotation() const
{
	return transformation.RelativeRotation;
}

void RE::WorldObject::Init()
{
	RE::EmptyWorldObject::Init();
	transformation = Transformation2D(0, 0, 100, 100, 0);
}

void RE::WorldObject::Start()
{
	EmptyWorldObject::Start();
}

void RE::WorldObject::Loop(float deltaTime)
{
	EmptyWorldObject::Loop(deltaTime);
}