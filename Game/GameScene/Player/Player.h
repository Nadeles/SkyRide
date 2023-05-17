#pragma once

#include "../../../Scene/Scene.h"
#include "../Map/Map.h"

class Player : public Scene {
public:

    ~Player() override = default;

    // Конструируется из ссылки на карту и ссылки на текстуру
    explicit Player(Map& map, const sf::Texture& player_texture);
    void OnFrame(const Timer& timer) override;
    void OnDraw(sf::RenderWindow& window) override;
    void OnEvent(sf::Event& event, const Timer& timer) override;

    // Не столкнулся ли с препятствием
    bool IsAlive() const;
private:
    bool is_alive_ = true;

    void LoadSizes();
    void LoadResources();

    const sf::Texture& texture_;
    sf::Sprite sprite_;

    // размер и позиция на экране
    sf::Vector2f size_;
    sf::Vector2f pos_;

    // физические величины
    float y_speed_ = 0;
    const float g_acceleration_ = Config::Physics::G_ACCELERATION;
    const float up_acceleration_ = Config::Physics::UP_ACCELERATION;

    // нажата ли мышь
    bool mouse_pressed = false;

    Map& map_;
};
