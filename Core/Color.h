#pragma once

namespace RE
{
	struct Color
	{
		Color(float red, float green, float blue, float alpha = 1.f)
			: Red(red), Green(green), Blue(blue), Alpha(alpha) {}

		float Red = 1.f, Green = 1.f, Blue = 1.f, Alpha = 1.f;
	};
};
