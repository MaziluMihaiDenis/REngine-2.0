#pragma once
#include <iostream>
namespace RE
{
	class Math
	{
	public:
		static inline float* MakeProjectionMatrix(float left, float right, float bottom, float top)
		{
			float* proj;
			proj = new float[16];

			for (int i = 0; i < 16; i++)
				proj[i] = 0.f;

			proj[4 * 0 + 0] = 2 / (right - left);
			proj[4 * 1 + 1] = 2 / (top - bottom);
			proj[4 * 2 + 2] = -1.f;
			proj[4 * 3 + 3] = 1.f;

			return proj;
		}

	};
}