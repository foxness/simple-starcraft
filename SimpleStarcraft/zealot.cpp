#include "zealot.h"
#include <memory>
#include "vector.h"
#include "entitydrawable.h"

Zealot::Zealot(const Vector& position_) : Unit(position_, 10, 150)
{
	drawable = std::make_unique<EntityDrawable>(position, size);
}