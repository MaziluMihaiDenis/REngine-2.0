#pragma once

#include "Vector2D.h"

namespace RE
{
	struct Transformation2D
	{
	public:
		Vector2D Position, Size, RelativePosition, RelativeSize;
		float Rotation, RelativeRotation;

	public:
		Transformation2D(float posx = 0.f, float posy = 0.f, float sizex = 0.f, float sizey = 0.f, float rot = 0.f);
		float* GetMatrix();
		
	public:
		bool operator!=(Transformation2D& transform) const;
		bool operator==(Transformation2D& transform) const;
		void operator=(Transformation2D& transform);
		void operator=(Transformation2D transform);
	};
};
