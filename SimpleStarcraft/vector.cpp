#include "vector.h"
#include <cmath>
#include <iostream>
#include <SFML/Graphics.hpp>

Vector::Vector(float x_, float y_) : x(x_), y(y_) {}

Vector::Vector(float angle, float length, int)
{
	x = length * std::cosf(angle);
	y = length * std::sinf(angle);
}

const Vector& Vector::from(const sf::Vector2i& a)
{
	return Vector(a.x, a.y);
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
	return std::atan2f(y, x);
}

float Vector::getLength() const
{
	return std::sqrt((*this) * (*this));
}

Vector& Vector::operator+=(const Vector& a)
{
	x += a.x;
	y += a.y;
	return *this;
}

Vector& Vector::operator-=(const Vector& a)
{
	x -= a.x;
	y -= a.y;
	return *this;
}

Vector& Vector::operator*=(float a)
{
	x *= a;
	y *= a;
	return *this;
}

const Vector Vector::operator+(const Vector& a) const
{
	return Vector(*this) += a;
}

const Vector Vector::operator-(const Vector& a) const
{
	return Vector(*this) -= a;
}

float Vector::operator*(const Vector& a) const
{
	return std::sqrtf(x * a.x + y * a.y);
}

const Vector Vector::operator*(float a) const
{
	return Vector(*this) *= a;
}

const Vector Vector::operator-() const
{
	return Vector(-x, -y);
}

bool Vector::operator==(const Vector& a) const
{
	return x == a.x && y == a.y;
}

bool Vector::operator!=(const Vector& a) const
{
	return !(*this == a);
}

const Vector Vector::normalized() const
{
	return Vector(getAngle(), 1, 0);
}

std::ostream& operator<<(std::ostream& a, const Vector& b)
{
	return a << "(" << b.getX() << ", " << b.getY() << ")";
}
