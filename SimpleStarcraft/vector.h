#pragma once

class Vector
{
private:
	float x;
	float y;

public:
	Vector(float x, float y);

	Vector(float angle, float length, int);

	float getX() const;

	float getY() const;

	float getAngle() const;

	float getLength() const;

	float operator*(const Vector& a) const;

	Vector& operator+(const Vector& a) const;

	Vector& operator-() const;

	Vector& operator-(const Vector& a) const;

	Vector& normalized() const;
};