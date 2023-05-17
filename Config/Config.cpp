#include "Config.h"

// В этом файле заданы все config переменные

const std::vector<std::filesystem::path> Config::Map::LEVELS = {
    "Levels/level_1.txt",
    "Levels/level_2.txt",
};

const std::filesystem::path Config::Graphics::PLAYER_TEXTURE_PATH_1 = "Resources/img/Player_1.png";
const std::filesystem::path Config::Graphics::PLAYER_TEXTURE_PATH_2 = "Resources/img/Player_2.png";
const std::filesystem::path Config::Graphics::BLOCK_TEXTURE_PATH = "Resources/img/Block.png";
const std::filesystem::path Config::Graphics::SPIKE_TEXTURE_PATH = "Resources/img/Spike.png";
const std::filesystem::path Config::Graphics::BACKGROUND_TEXTURE_PATH = "Resources/img/Background.png";
const std::filesystem::path Config::Graphics::MENU_FONT_PATH = "Resources/font/MenuFont.ttf";

const sf::Vector2i Config::Graphics::PLAYER_TEXTURE_PADDING = {0, 0};
const sf::Vector2i Config::Graphics::PLAYER_TEXTURE_SIZE = {68, 40};

const sf::Vector2i Config::Graphics::BLOCK_TEXTURE_PADDING = {3, 3};
const sf::Vector2i Config::Graphics::BLOCK_TEXTURE_SIZE = {16, 16};

const sf::Vector2i Config::Graphics::SPIKE_TEXTURE_PADDING = {1, 1};
const sf::Vector2i Config::Graphics::SPIKE_TEXTURE_SIZE = {53, 52};

const sf::Vector2i Config::Graphics::BACKGROUND_TEXTURE_PADDING = {0, 0};
const sf::Vector2i Config::Graphics::BACKGROUND_TEXTURE_SIZE = {1391, 1000};

const float Config::Graphics::SPIKE_SCALE = 1.1;
const float Config::Graphics::Menu::HIGHLIGHT_PADDING = 0.1;
const sf::Vector2f Config::Graphics::Menu::TEXT_PADDING = {0.1, 0.1};
const sf::Vector2f Config::Graphics::Menu::PLAYER_1_PADDING = {0.1, 0.3};
const sf::Vector2f Config::Graphics::Menu::PLAYER_2_PADDING = {0.6, 0.3};
const sf::Vector2f Config::Graphics::Menu::LEVEL_TEXT_PADDING = {0.1, 0.6};

const sf::Vector2f Config::Graphics::Menu::PLAYER_SIZE = {0.3, 0.2};

const float Config::Physics::G_ACCELERATION = 13;
const float Config::Physics::UP_ACCELERATION = 20;
const float Config::Physics::PLAYER_MAX_SPEED_Y = 8;
const float Config::Physics::PLAYER_ROTATION_ANGLE = 45;
const float Config::Physics::MAP_SHIFT_CHANGING_SPEED = 5;

const float Config::Physics::Hitbox::END_LENGTH_PERCENTS = 0.5;
const float Config::Physics::Hitbox::END_THICKNESS_PERCENTS = 0.1;

const float Config::Physics::Hitbox::PLAYER_HITBOX_WIDTH_PERCENTS = 0.6;

const float Config::Time::TIME_AFTER_END = 0.5;
