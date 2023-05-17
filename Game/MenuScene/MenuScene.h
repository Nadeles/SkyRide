#pragma once

#include "../../Scene/Scene.h"

// Класс выбора элемента игры
enum Selected {
    First, Second
};

// Описывает Меню
class MenuScene : public Scene {
public:
    ~MenuScene() override = default;

    MenuScene();
    void OnFrame(const Timer& timer) override;
    void OnDraw(sf::RenderWindow& window) override;
    void OnEvent(sf::Event& event, const Timer& timer) override;

    // Доступ к данным меню
    Selected PlayerSelected() const;
    Selected LevelSelected() const;
private:
    void LoadSizes();
    void LoadResources();

    // Выделяет спрайт
    static void HighlightSprite(const sf::Sprite& sprite, sf::RenderWindow& window);
    // Изменяет позицию и размер спрайта, чтобы он влезал в hitbox
    static void SqueezeTo(sf::Sprite& sprite, sf::FloatRect hitbox);

    // Данные меню
    Selected player_selected_ = First;
    Selected level_selected_ = First;

    // Данные для отрисовки
    sf::Vector2f background_tile_size_;
    sf::Sprite background_sprite_;

    sf::Sprite player_sprite_[2];
    sf::Text level_text_;
    sf::Text help_text_;
};
