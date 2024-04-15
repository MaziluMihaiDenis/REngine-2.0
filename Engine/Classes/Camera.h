#pragma once
#include "WorldObject.h"

namespace RE
{
	enum PROJECTION_MODE 
	{
		ORTHOGRAPHIC,
		PERSPECTIVE
	};

	class Camera : public WorldObject
	{
	public:
		PROJECTION_MODE ProjectionType;

	public:
		void UpdateViewport();
		float* getProjectionMatrix();

	private:
		float* ProjectionMatrix;
	};
}

