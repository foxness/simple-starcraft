#include "entitybase.h"

EntityBase::EntityBase(const Vector& position_) : position(position_) {}

const Vector& EntityBase::getPosition() const
{
	return position;
}