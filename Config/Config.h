#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <filesystem>

// Config содержит настройки игры
class Config {
public:
    // Map содержит информацию о картах уровней игры
    struct Map {
        static const std::vector<std::filesystem::path> LEVELS;  // Вектор путей к файлам уровней
    };

    // Graphics содержит информацию о графических настройках игры
    struct Graphics {
    public:
        // Пути к текстурам игровых объектов
        static const std::filesystem::path PLAYER_TEXTURE_PATH_1;
        static const std::filesystem::path PLAYER_TEXTURE_PATH_2;
        static const std::filesystem::path BLOCK_TEXTURE_PATH;
        static const std::filesystem::path SPIKE_TEXTURE_PATH;
        static const std::filesystem::path BACKGROUND_TEXTURE_PATH;
        static const std::filesystem::path MENU_FONT_PATH;

        // Отступы и размеры текстур игрока
        static const sf::Vector2i PLAYER_TEXTURE_PADDING;
        static const sf::Vector2i PLAYER_TEXTURE_SIZE;

        // Отступы и размеры текстур блока
        static const sf::Vector2i BLOCK_TEXTURE_PADDING;
        static const sf::Vector2i BLOCK_TEXTURE_SIZE;

        // Отступы и размеры текстур шипов
        static const sf::Vector2i SPIKE_TEXTURE_PADDING;
        static const sf::Vector2i SPIKE_TEXTURE_SIZE;

        // Отступы и размеры текстур фона
        static const sf::Vector2i BACKGROUND_TEXTURE_PADDING;
        static const sf::Vector2i BACKGROUND_TEXTURE_SIZE;

        // Увеличение текстуры шипов
        static const float SPIKE_SCALE;

        // Внутренние настройки меню
        struct Menu {
            static const float HIGHLIGHT_PADDING;  // Отступ выделения

            static const sf::Vector2f TEXT_PADDING;  // Отступы текста

            static const sf::Vector2f PLAYER_SIZE;  // Размеры спрайта игрока

            static const sf::Vector2f PLAYER_1_PADDING;  // Отступ спрайта игрока 1
            static const sf::Vector2f PLAYER_2_PADDING;  // Отступ спрайта игрока 2

            static const sf::Vector2f LEVEL_TEXT_PADDING;  // Отступы текста уровня
        };
    };

    // Physics содержит физические настройки игры
    struct Physics {
    public:
        // Параметры хитбоксов
        struct Hitbox {
            static const float END_THICKNESS_PERCENTS;  // Толщины концов хитбоксов
            static const float END_LENGTH_PERCENTS;  // Длина концов хитбоксов

            static const float PLAYER_HITBOX_WIDTH_PERCENTS;  // Процент ширины границы игрока
        };

        static const float G_ACCELERATION;  // Величина скорости гравитации
        static const float UP_ACCELERATION;  // Величина скорости подпрыгивания
        static const float PLAYER_MAX_SPEED_Y;  // Максимальная скорость игрока по оси Y
        static const float PLAYER_ROTATION_ANGLE;  // Максимальный угол поворота игрока
        static const float MAP_SHIFT_CHANGING_SPEED;  // Скорость изменения сдвига карты
    };

    //  Time содержит информацию о времени в игре
    struct Time {
        static const float TIME_AFTER_END;  // Время перезагрузки уровня
    };

    Config() = delete;  // Запрет конструктора по умолчанию
};
