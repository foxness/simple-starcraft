#include "rectangle.h"

Rectangle::Rectangle(const Vector& position_, float width_, float height_) : position(position_), width(width_), height(height_) {}

Rectangle::Rectangle(const Vector& firstPoint, const Vector& secondPoint)
{
	float nStartX = std::fminf(firstPoint.getX(), secondPoint.getX()); // n - normalized
	float nStartY = std::fminf(firstPoint.getY(), secondPoint.getY());
	float nEndX = std::fmaxf(firstPoint.getX(), secondPoint.getX());
	float nEndY = std::fmaxf(firstPoint.getY(), secondPoint.getY());

	position = Vector(nStartX, nStartY);
	width = nEndX - nStartX;
	height = nEndY - nStartY;
}

bool Rectangle::contains(const Vector& point) const
{
	return position.getX() <= point.getX() && point.getX() <= position.getX() + width &&
	    	position.getY() <= point.getY() && point.getY() <= position.getY() + height;
}

const Vector& Rectangle::getPosition() const
{
	return position;
}

float Rectangle::getWidth() const
{
	return width;
}

float Rectangle::getHeight() const
{
	return height;
}
