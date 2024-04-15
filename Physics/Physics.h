#pragma once

#include "Structs/CollisionShape2D.h"
#include <vector>

namespace RE
{
	class Physics
	{
		friend class Engine;
		friend void run_logic_thread(float delta);

	private:
		inline static Physics* Instance;
		std::vector<CollisionShape2D*> RegisteredColliders;

	private:
		bool HandleCollision(CollisionShape2D* a, CollisionShape2D* b);
		bool HandleRRCollision(CollisionShape2D* a, CollisionShape2D* b);
		bool HandleRCCollision(CollisionShape2D* a, CollisionShape2D* b);
		bool HandleCCCollision(CollisionShape2D* a, CollisionShape2D* b);

		bool TestCollision(CollisionShape2D* a, CollisionShape2D* b);
	public:
		void Init();
		void Loop();
		void RegisterCollider(CollisionShape2D* collider);
		void UnregisterCollider(CollisionShape2D* collider);

	public:
		static Physics* GetInstance();
	};
};
