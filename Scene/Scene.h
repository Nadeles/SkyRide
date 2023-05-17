#pragma once

#include "SFML/Graphics.hpp"
#include "Timer.h"

// Класс Scene - базовый класс для всех обьектов игры
class Scene {
public:
    virtual ~Scene() = default;

    // Функция которая вызывается на каждом кадре для обновления состояния обьекта
    virtual void OnFrame(const Timer& timer) = 0;

    // Функция которая вызывается на каждом кадре для отрисовки обьекта
    virtual void OnDraw(sf::RenderWindow& window) = 0;

    // Функция которая вызывается на каждом кадре для обработки событий обьектом
    virtual void OnEvent(sf::Event& event, const Timer& timer) = 0;

protected:
    const static sf::Vector2f window_size_;  // Размер окна
};
