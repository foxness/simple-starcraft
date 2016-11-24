#include "entitytype.h"
#include "constants.h"

const std::string& getName(const EntityType& type)
{
	switch (type)
	{
	case EntityType::MineralPatch: return MINERALPATCH_NAME;
	case EntityType::Nexus: return NEXUS_NAME;
	case EntityType::Probe: return PROBE_NAME;
	case EntityType::Zealot: return ZEALOT_NAME;
	}

	throw "This type has no name";
}