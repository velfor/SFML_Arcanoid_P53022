#pragma once
#include <string>
#include "SFML/Graphics.hpp"

// ŒÕ—“¿Õ“€
const float WINDOW_WIDTH{ 800.f };
const float WINDOW_HEIGHT{ 800.f };
const std::string WINDOW_TITLE{ "SFML Racing P53022" };
const unsigned int FPS{ 60 };

const float ROAD_OBJ_SPEED = 3.f;

const std::string PLAYER_FILE_NAME{ "car.png" };
const float PLAYER_WIDTH = 80.f;
const float PLAYER_HEIGHT = 80.f;
sf::Vector2f PLAYER_START_POS{ (WINDOW_WIDTH - PLAYER_WIDTH)/2.f, WINDOW_HEIGHT - PLAYER_HEIGHT};