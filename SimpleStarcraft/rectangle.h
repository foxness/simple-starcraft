#pragma once

#include "vector.h"

class Rectangle
{
protected:
	Vector position;
	float width;
	float height;

public:
	Rectangle(const Vector& position_, float width_, float height_);

	Rectangle(const Vector& firstPoint, const Vector& secondPoint);

	bool contains(const Vector& point) const;

	const Vector& getPosition() const;

	float getWidth() const;

	float getHeight() const;
};