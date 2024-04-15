#pragma once
#include "Classes/Object.h"
#include "Classes/Camera.h"
#include "Structs/Transformation2D.h"
#include <Engine/Classes/EmptyWorldObject.h>
#include <vector>

namespace RE
{
	static unsigned int g_ID = 0;

	class World
	{
		friend class Engine;
	private:
		Camera* MainCamera;
		inline static World* Instance;
	private:
		std::vector<EmptyWorldObject*> WorldObjects;

	public:
		template<class T> 
		static T* Instantiate();
		static World* GetInstance();
		static void SaveCurrentLevel();
		static void LoadLevel(std::string levelPath);
		static void ClearCurrentLevel();

	public:
		Camera* GetCamera();
	};

	template<class T>
	inline T* World::Instantiate()
	{
		EmptyWorldObject* wobjCast;
		T* obj;

		obj = new T();
		wobjCast = static_cast<EmptyWorldObject*>(obj);

		if (!wobjCast)
			return NULL;

		wobjCast->Init();
		wobjCast->ID = g_ID++;
		World::GetInstance()->WorldObjects.push_back(wobjCast);

		return obj;
	}
	inline World* World::GetInstance()
	{
		if (!Instance)
			Instance = new World();
		return Instance;
	}
	inline void World::SaveCurrentLevel()
	{
	}
	inline void World::LoadLevel(std::string levelPath)
	{
	}
	inline void World::ClearCurrentLevel()
	{
	}
	inline Camera* World::GetCamera()
	{
		if (!MainCamera)
			MainCamera = Instantiate<Camera>();
		return MainCamera;
	}
};

