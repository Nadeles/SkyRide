#include "MenuScene.h"
#include "../../Config/Config.h"
#include "../../Resources/Resources.h"

MenuScene::MenuScene() {
    // Инициализация ресурсов и размеров
    LoadResources();
    LoadSizes();
}

void MenuScene::OnFrame(const Timer& timer) {
}

void MenuScene::OnDraw(sf::RenderWindow& window) {
    // Отрисовка фона
    window.draw(background_sprite_);

    // Установка текста уровня в зависимости от выбранного уровня
    if (level_selected_ == Selected::First) {
        level_text_.setString("Level 1");
    } else {
        level_text_.setString("Level 2");
    }

    // Отрисовка спрайтов игроков, текстов и выделения
    window.draw(player_sprite_[0]);
    window.draw(player_sprite_[1]);
    window.draw(help_text_);
    window.draw(level_text_);

    // Выделение спрайта выбранного игрока
    if (player_selected_ == Selected::First) {
        HighlightSprite(player_sprite_[0], window);
    } else {
        HighlightSprite(player_sprite_[1], window);
    }

}

void MenuScene::OnEvent(sf::Event& event, const Timer& timer) {
    // Обработка событий клавиатуры
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Num1) {
            level_selected_ = Selected::First;
        } else if (event.key.code == sf::Keyboard::Num2) {
            level_selected_ = Selected::Second;
        } else if (event.key.code == sf::Keyboard::Left) {
            player_selected_ = Selected::First;
        } else if (event.key.code == sf::Keyboard::Right) {
            player_selected_ = Selected::Second;
        }
    }
}
void MenuScene::HighlightSprite(const sf::Sprite& sprite, sf::RenderWindow& window) {
    sf::RectangleShape border;

    auto hitbox = sprite.getGlobalBounds();

    float border_scale = (1 + Config::Graphics::Menu::HIGHLIGHT_PADDING);

    border.setSize({hitbox.width * border_scale, hitbox.height * border_scale});
    border.setPosition({hitbox.left - hitbox.width * (border_scale - 1) / 2,
                        hitbox.top - hitbox.height * (border_scale - 1) / 2});

    border.setOutlineColor(sf::Color::White);
    border.setOutlineThickness(10);
    border.setFillColor(sf::Color::Transparent);
    window.draw(border);
}

void MenuScene::SqueezeTo(sf::Sprite& sprite, sf::FloatRect hitbox) {
    sprite.setPosition(hitbox.left, hitbox.top);

    float hitbox_scale = std::min(
        hitbox.width / sprite.getLocalBounds().width,
        hitbox.height / sprite.getLocalBounds().height
    );

    sprite.setScale(hitbox_scale, hitbox_scale);
}

void MenuScene::LoadSizes() {
    SqueezeTo(player_sprite_[0],
              {
                  Config::Graphics::Menu::PLAYER_1_PADDING.x * window_size_.x,
                  Config::Graphics::Menu::PLAYER_1_PADDING.y * window_size_.y,
                  Config::Graphics::Menu::PLAYER_SIZE.x * window_size_.x,
                  Config::Graphics::Menu::PLAYER_SIZE.y * window_size_.y,
              });

    SqueezeTo(player_sprite_[1],
              {
                  Config::Graphics::Menu::PLAYER_2_PADDING.x * window_size_.x,
                  Config::Graphics::Menu::PLAYER_2_PADDING.y * window_size_.y,
                  Config::Graphics::Menu::PLAYER_SIZE.x * window_size_.x,
                  Config::Graphics::Menu::PLAYER_SIZE.y * window_size_.y,
              });

    level_text_.setPosition(
        {
            Config::Graphics::Menu::LEVEL_TEXT_PADDING.x * window_size_.x,
            Config::Graphics::Menu::LEVEL_TEXT_PADDING.y * window_size_.y,
        });

    help_text_.setPosition(
        {
            Config::Graphics::Menu::TEXT_PADDING.x * window_size_.x,
            Config::Graphics::Menu::TEXT_PADDING.y * window_size_.y,
        });

    background_tile_size_.x = window_size_.x;
    background_tile_size_.y = background_tile_size_.x *
        static_cast<float>(Config::Graphics::BACKGROUND_TEXTURE_SIZE.y) /
        static_cast<float>(Config::Graphics::BACKGROUND_TEXTURE_SIZE.x);

    float background_scale = background_tile_size_.x / background_sprite_.getGlobalBounds().width;
    background_sprite_.setScale(background_scale, background_scale);
}

void MenuScene::LoadResources() {
    // Загрузка ресурсов из класса Resources и установка значений текстовых элементов
    player_sprite_[0].setTexture(Resources::PLAYER_TEXTURE_1());
    player_sprite_[1].setTexture(Resources::PLAYER_TEXTURE_2());

    help_text_.setFont(Resources::MENU_FONT());
    help_text_.setCharacterSize(static_cast<uint32_t>(window_size_.y * 0.05));
    level_text_.setFont(Resources::MENU_FONT());
    level_text_.setCharacterSize(static_cast<uint32_t>(window_size_.y * 0.05));

    help_text_.setString("Arrows - Choose Skin\n 1,2 - Choose Level");
    level_text_.setFillColor(sf::Color::White);
    level_text_.setString("Level 1");
    help_text_.setFillColor(sf::Color::White);

    background_sprite_.setTexture(Resources::BACKGROUND_TEXTURE());
}

Selected MenuScene::PlayerSelected() const {
    return player_selected_;
}
Selected MenuScene::LevelSelected() const {
    return level_selected_;
}
