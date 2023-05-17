#pragma once
#include "../Config/Config.h"

// Класс Resources предоставляет доступ к ресурсам игры, таким как текстуры и шрифты
class Resources {
public:
    // Функции доступа к ресурсам
    static const sf::Texture& PLAYER_TEXTURE_1();
    static const sf::Texture& PLAYER_TEXTURE_2();
    static const sf::Texture& SPIKE_TEXTURE();
    static const sf::Texture& BLOCK_TEXTURE();
    static const sf::Texture& BACKGROUND_TEXTURE();
    static const sf::Font& MENU_FONT();

private:
    // Единственный экземпляр класса Resources
    static const Resources instance_;

    Resources();

    // Указатели на ресурсы
    std::unique_ptr<sf::Texture> player_texture_1_;
    std::unique_ptr<sf::Texture> player_texture_2_;
    std::unique_ptr<sf::Texture> spike_texture_;
    std::unique_ptr<sf::Texture> block_texture_;
    std::unique_ptr<sf::Texture> background_texture_;
    std::unique_ptr<sf::Font> menu_font_;
};
