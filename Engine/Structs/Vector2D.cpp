#include "Vector2D.h"

#include <math.h>

const Vector2D& Vector2D::ZeroVector = { 0, 0 };

Vector2D::Vector2D(float x, float y)
{
	this->x = x;
	this->y = y;
}

Vector2D::Vector2D(int x, int y)
{
	this->x = x;
	this->y = y;
}

Vector2D::Vector2D(unsigned int x, unsigned int y)
{
	this->x = x;
	this->y = y;
}

Vector2D::Vector2D() : x(0), y(0) {}

float Vector2D::DistanceSquared(const Vector2D& v) const
{
	return (v.x - x) * (v.x - x) + (v.x - y) * (v.y - y);
}

float Vector2D::Distance(const Vector2D& v) const
{
	return sqrt(DistanceSquared(v));
}

float Vector2D::Length() const
{
	return sqrt(x * x + y * y);
}

float Vector2D::AngleTo(const Vector2D& v) const
{
	return atan2(v.y - y, v.x - x);
}

Vector2D Vector2D::operator+(const Vector2D& v) const
{
	return Vector2D(v.x + this->x, v.y + this->y);
}

Vector2D Vector2D::operator-(const Vector2D& v) const
{
	return Vector2D(v.x - this->x, v.y - this->y);
}

float Vector2D::DotProduct(const Vector2D& v) const
{
	float len1 = Length();
	float len2 = v.Length();
	return len1 * len2 * cos(AngleTo(v));
}

float Vector2D::operator*(const Vector2D& v) const
{
	return DotProduct(v);
}

Vector2D Vector2D::operator+(float f) const
{
	return Vector2D(x + f, y + f);
}

Vector2D Vector2D::operator-(float f) const
{
	return Vector2D(x - f, y - f);
}

Vector2D Vector2D::operator*(float f) const
{
	return Vector2D(x * f, y * f);
}

Vector2D Vector2D::operator/(float f) const
{
	return Vector2D(x / f, y / f);
}

bool Vector2D::operator==(const Vector2D& vector) const
{
	return vector.x == x && vector.y == y;
}

bool Vector2D::operator!=(const Vector2D& vector) const
{
	return vector.x != x && vector.y != y;
}

