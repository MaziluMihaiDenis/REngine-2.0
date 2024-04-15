#pragma once

#include <Engine/Classes/WorldObject.h>
#include <Engine/Classes/Component.h>
#include <Engine/Classes/Graphics/Sprite.h>

namespace RE
{
	enum EShape
	{
		CIRCLE,
		RECTANGLE
	};
	class CollisionShape2D : public Component
	{
		friend class Physics;

	public:
		EShape Shape;
		Sprite* DebugSprite;
		bool ShowDebug;
		bool Trigger;

	public:
		struct Extent
		{
			Vector2D Size;
			Vector2D ReferencePoint;
		} extent;

	public:
		int Layer, Mask;

	protected:
		virtual void OnCollisionEnter(WorldObject* hit);
		virtual void OnTriggerEnter(WorldObject* hit);
		virtual void OnCollisionExit(WorldObject* hit);
		virtual void OnTriggerExit(WorldObject* hit);
	protected:
		void SetReferencePoint(Vector2D& point);
		void DrawDebug();
	public:
		virtual void Init() override;
		virtual void Start() override;
		virtual void Loop(float deltaTime) override;
	};
};