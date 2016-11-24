#pragma once

#include <string>

enum class EntityType
{
	MineralPatch, Nexus, Probe, Zealot
};

const std::string& getName(const EntityType& type);