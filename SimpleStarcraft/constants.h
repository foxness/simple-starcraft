#pragma once

#include <SFML/Graphics.hpp>
#include "entitytype.h"

static const int SELECTION_SEGMENTS = 32;
static const float SELECTION_SIZE_COEFFICIENT = 1.3f;
static const sf::Color& SELECTION_COLOR = sf::Color::Green;

static const float HEALTHBAR_WIDTH = 35;
static const float HEALTHBAR_HEIGHT = 6;
static const float HEALTHBAR_DIST_COEFFICINENT = 1.3f;
static const float HEALTHBAR_DIST = 9;
static const sf::Color& HEALTHBAR_BG_COLOR = sf::Color::Transparent;
static const sf::Color& HEALTHBAR_OUTLINE_COLOR = sf::Color::White;
static const sf::Color& HEALTHBAR_COLOR = sf::Color::Green;
static const float HEALTHBAR_OUTLINE_THICKNESS = 1;

static const float ORIGIN_COEFFICIENT = 0.5f;

static const int MINERALPATCH_SIZE = 16;
static const int MINERALPATCH_CAPACITY = 1000;
static const sf::Color& MINERALPATCH_COLOR = sf::Color::Cyan;
static const std::string& MINERALPATCH_NAME = "Mineral Patch";
static const EntityType& MINERALPATCH_TYPE = EntityType::MineralPatch;

static const int NEXUS_SIZE = 48;
static const float NEXUS_MAXHEALTH = 500;
static const sf::Color& NEXUS_COLOR = sf::Color::Yellow;
static const std::string& NEXUS_NAME = "Nexus";
static const EntityType& NEXUS_TYPE = EntityType::Nexus;

static const int PROBE_SIZE = 7;
static const float PROBE_MAXHEALTH = 10;
static const sf::Color& PROBE_COLOR = sf::Color(120, 80, 170);
static const float PROBE_MOVESPEED = 120;
static const float PROBE_CARRY_SIZE = 4;
static const std::string& PROBE_NAME = "Probe";
static const EntityType& PROBE_TYPE = EntityType::Probe;

static const int ZEALOT_SIZE = 10;
static const float ZEALOT_MAXHEALTH = 10;
static const sf::Color& ZEALOT_COLOR = sf::Color(150, 32, 180);
static const float ZEALOT_MOVESPEED = 150;
static const std::string& ZEALOT_NAME = "Zealot";
static const EntityType& ZEALOT_TYPE = EntityType::Zealot;

static const float RESOURCE_HEALTH = -1; // resources have no hp

static const float BEAKSIZE_COEFFICIENT = 1.5f;
static const float BEAKSIZE = -3;
static const int BEAK_VERTICES = 3;
static const sf::Color& BEAK_COLOR = sf::Color::White;

static const int WINDOW_WIDTH = 800;
static const int WINDOW_HEIGHT = 600;
static const char* const WINDOW_TITLE = "Simple Starcraft";
static const float FPS_CALC_PERIOD = 1;
static const float FPS_DISPLAY_PERIOD = 3;