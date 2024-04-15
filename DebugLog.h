#pragma once
#include <iostream>

namespace RE
{
	class Debug
	{
	public:
		template <typename T, typename... Args>
		static void Print(T t, Args... args);
	};

	template<typename T, typename... Args>
	inline void Debug::Print(T t, Args ...args)
	{
		std::cout << t << '\n';
		//Print(args...);
	}
};

