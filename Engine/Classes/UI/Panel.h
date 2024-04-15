#pragma once
#include "../Graphics/IRenderable.h"

class Panel : public IRenderable
{
public:
	Vector2D anchorPoint;
	Transformation2D transform;

public:
	Panel();
	void SetPosition(Vector2D position);
	void SetSize(Vector2D size);
};

