#include "Transformation2D.h"
#include <cmath>
#include <stdio.h>

RE::Transformation2D::Transformation2D(float posx, float posy, float sizex, float sizey, float rot)
{
	RelativePosition = Position = Vector2D(posx, posy);
	RelativeSize = Size = Vector2D(sizex, sizey);
	Rotation = RelativeRotation = rot;
}

float* RE::Transformation2D::GetMatrix()
{
	float* matrix, radians;
	radians = DEG2RAD * Rotation;
	matrix = new float[16];
	for (int i = 0; i < 16; i++)
		matrix[i] = 0.f;
	matrix[4 * 3 + 3] = 1.f;

	// x rotation
	matrix[0] = Size.x * cos(radians);
	matrix[1] = Size.x * sin(radians);

	// y rotation
	matrix[4 * 1 + 0] = Size.y * -sin(radians);
	matrix[4 * 1 + 1] = Size.y * cos(radians);

	// translation
	matrix[4 * 3 + 0] = Position.x;
	matrix[4 * 3 + 1] = Position.y;

	return matrix;
}

bool RE::Transformation2D::operator!=(Transformation2D& transform) const
{
	return transform.Position != Position ||
			transform.Size != Size ||
			transform.Rotation != Rotation;
}

bool RE::Transformation2D::operator==(Transformation2D& transform) const
{
	return transform.Position == Position ||
		transform.Size == Size ||
		transform.Rotation == Rotation;
}

void RE::Transformation2D::operator=(Transformation2D& transform)
{
	this->Position = transform.Position;
	this->Size = transform.Size;
	this->Rotation = transform.Rotation;
}

void RE::Transformation2D::operator=(Transformation2D transform)
{
	this->Position = transform.Position;
	this->Size = transform.Size;
	this->Rotation = transform.Rotation;
}
