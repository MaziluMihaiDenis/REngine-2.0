#pragma once

namespace RE
{
	class Engine
	{
		friend int main();

	private:
		inline static Engine* Instance;

	public:
		void Init();
		void Loop(float deltaTime);
		void End();
	public:
		static Engine* GetInstance();
	};
};

