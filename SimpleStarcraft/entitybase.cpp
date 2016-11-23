#include "entitybase.h"

EntityBase::EntityBase(const Vector& position_) : position(position_), id(getNextId()) {}

const Vector& EntityBase::getPosition() const
{
	return position;
}

int EntityBase::getId() const
{
	return id;
}

int EntityBase::getNextId() const
{
	static int _id = 0;
	return _id++;
}
