#pragma once

#include <typeinfo>
#include <vector>
#include <string>

#define NAME_OF_CLASS(T) typeid(T).name()
/*
#define OBJECT_FORMAT_IN(ID, PROCESSING) "{\"class\": \"Object\", \"ID\": " << ID << ", \"Processing\": " << PROCESSING  << "}"
#define OBJECT_FORMAT_OUT(ID, PROCESSING) ID >> PROCESSING
*/

namespace RE
{
	class Object
	{
		friend class World;
	public:
		unsigned int ID;
	public:
		bool Processing = true;
	public:
		virtual void Init();
		virtual void Start();
		virtual void Loop(float deltaTime);
		virtual void Destroy(float time = 0.f);
		// virtual void Serialize(std::string filePath);
		// virtual void Deserialize(std::string filePath);
	};

	template<typename T>
	inline T* Cast(void* object)
	{
		T* ret;
		if (!(ret = (T*)object))
			return nullptr;
		return ret;
	}
};

/*
	Object
	{
		Processing x
	}
	EmptyWorldObject
	{
		Object...
		Components
		{
			Sprite...
		}
	}
	WorldObject
	{
		Transformation
		{
			Position (x), (y)
			Size (x), (y)
			Rotation (x)
		}
	}
*/
