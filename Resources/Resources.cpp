#include "Resources.h"

// Инициализация статического экземпляра класса Resources
const Resources Resources::instance_;


Resources::Resources() {
    // Создание уникальных указателей на текстуры и шрифт
    player_texture_1_ = std::make_unique<sf::Texture>();
    player_texture_2_ = std::make_unique<sf::Texture>();
    spike_texture_ = std::make_unique<sf::Texture>();
    block_texture_ = std::make_unique<sf::Texture>();
    background_texture_ = std::make_unique<sf::Texture>();
    menu_font_ = std::make_unique<sf::Font>();

    // Загрузка ресурсов из файлов
    player_texture_1_->loadFromFile(Config::Graphics::PLAYER_TEXTURE_PATH_1,
                                    sf::IntRect(
                                        Config::Graphics::PLAYER_TEXTURE_PADDING.x,
                                        Config::Graphics::PLAYER_TEXTURE_PADDING.y,
                                        Config::Graphics::PLAYER_TEXTURE_SIZE.x,
                                        Config::Graphics::PLAYER_TEXTURE_SIZE.y
                                    ));

    player_texture_2_->loadFromFile(Config::Graphics::PLAYER_TEXTURE_PATH_2,
                                    sf::IntRect(
                                        Config::Graphics::PLAYER_TEXTURE_PADDING.x,
                                        Config::Graphics::PLAYER_TEXTURE_PADDING.y,
                                        Config::Graphics::PLAYER_TEXTURE_SIZE.x,
                                        Config::Graphics::PLAYER_TEXTURE_SIZE.y
                                    ));

    spike_texture_->loadFromFile(Config::Graphics::SPIKE_TEXTURE_PATH,
                                 sf::IntRect(
                                     Config::Graphics::SPIKE_TEXTURE_PADDING.x,
                                     Config::Graphics::SPIKE_TEXTURE_PADDING.y,
                                     Config::Graphics::SPIKE_TEXTURE_SIZE.x,
                                     Config::Graphics::SPIKE_TEXTURE_SIZE.y
                                 ));

    block_texture_->loadFromFile(Config::Graphics::BLOCK_TEXTURE_PATH,
                                 sf::IntRect(
                                     Config::Graphics::BLOCK_TEXTURE_PADDING.x,
                                     Config::Graphics::BLOCK_TEXTURE_PADDING.y,
                                     Config::Graphics::BLOCK_TEXTURE_SIZE.x,
                                     Config::Graphics::BLOCK_TEXTURE_SIZE.y
                                 ));

    background_texture_->loadFromFile(Config::Graphics::BACKGROUND_TEXTURE_PATH,
                                      sf::IntRect(
                                          Config::Graphics::BACKGROUND_TEXTURE_PADDING.x,
                                          Config::Graphics::BACKGROUND_TEXTURE_PADDING.y,
                                          Config::Graphics::BACKGROUND_TEXTURE_SIZE.x,
                                          Config::Graphics::BACKGROUND_TEXTURE_SIZE.y
                                      ));
    menu_font_->loadFromFile(Config::Graphics::MENU_FONT_PATH);
}

const sf::Texture& Resources::PLAYER_TEXTURE_1() {
    return *instance_.player_texture_1_;
}

const sf::Texture& Resources::PLAYER_TEXTURE_2() {
    return *instance_.player_texture_2_;
}

const sf::Texture& Resources::SPIKE_TEXTURE() {
    return *instance_.spike_texture_;
}
const sf::Texture& Resources::BLOCK_TEXTURE() {
    return *instance_.block_texture_;
}
const sf::Texture& Resources::BACKGROUND_TEXTURE() {
    return *instance_.background_texture_;
}
const sf::Font& Resources::MENU_FONT() {
    return *instance_.menu_font_;
}
