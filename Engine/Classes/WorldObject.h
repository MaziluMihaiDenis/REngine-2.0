#pragma once

#include "EmptyWorldObject.h"
#include <Engine/Structs/Transformation2D.h>

namespace RE
{
	class WorldObject : public EmptyWorldObject
	{
		friend class SpriteComponent;
		friend class CollisionShape2D;
	protected:
		bool Updated = true;

	private:
		Transformation2D transformation;

	public:
		void SetPosition(const Vector2D& translation);
		void SetSize(const Vector2D& scale);
		void SetRotation(float rotation);

		void SetRelativePosition(Vector2D& translation);
		void SetRelativeSize(Vector2D& scale);
		void SetRelativeRotation(float rotation);

		Vector2D GetPosition() const;
		Vector2D GetSize() const;
		float GetRotation() const;

		Vector2D GetRelativePosition() const;
		Vector2D GetRelativeSize() const;
		float GetRelativeRotation() const;

	public:
		virtual void Init() override;
		virtual void Start() override;
		virtual void Loop(float deltaTime) override;
	};
};

