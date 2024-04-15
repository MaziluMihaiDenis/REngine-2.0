#pragma once

#include <Application/API/Window.h>
#include <Engine/Classes/Graphics/IRenderable.h>
#include <vector>

namespace RE
{
	class Graphics
	{
		friend class Engine;
	private:
		static inline Graphics* Instance;
		std::vector<IRenderable*> RegisteredObjects;

	public:
		void Init(Window* window);
		void Loop();
		void UpdateViewport();
	public:
		void RegisterDisplayObject(IRenderable* object);
		void UnregisterDisplayObject(IRenderable* object);
	public:
		static Graphics* GetInstance();
	};
};
