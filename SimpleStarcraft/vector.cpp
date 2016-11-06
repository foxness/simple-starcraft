#include "vector.h"
#include <cmath>

Vector::Vector(float x, float y)
{
	this->x = x;
	this->y = y;
}

Vector::Vector(float angle, float length, int)
{
	x = length * std::cosf(angle);
	y = length * std::sinf(angle);
}

float Vector::getX() const
{
	return x;
}

float Vector::getY() const
{
	return y;
}

float Vector::getAngle() const
{
	return std::atan2f(-y, x);
}

float Vector::getLength() const
{
	return std::sqrt((*this) * (*this));
}

float Vector::operator*(const Vector& a) const // dot product
{
	return a.x * x + a.y * y;
}

Vector& Vector::operator+(const Vector& a) const
{
	return Vector(a.x + x, a.y + y);
}

Vector& Vector::operator-() const
{
	return Vector(-x, -y);
}

Vector & Vector::operator-(const Vector& a) const
{
	return (*this) + -a;
}

Vector& Vector::normalized() const
{
	return Vector(getAngle(), 1, 0);
}
