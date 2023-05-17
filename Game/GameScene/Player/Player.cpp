#include "Player.h"

Player::Player(Map& map, const sf::Texture& player_texture) : map_(map), texture_(player_texture) {
    LoadResources();
    LoadSizes();
}

void Player::OnFrame(const Timer& timer) {
    // Если не нажата мышь, увеличиваем скорость падения, иначе уменьшаем
    if (!mouse_pressed)
        y_speed_ += timer.GetDelta() * g_acceleration_;
    if (mouse_pressed)
        y_speed_ -= timer.GetDelta() * up_acceleration_;

    // Получаем хитбокс
    sf::FloatRect hitbox = sprite_.getGlobalBounds();

    // Подсчитываем ожидаемое изменение y
    float y_change = y_speed_ * timer.GetDelta() * map_.GetTileSize();

    // Сжимаем хитбокс (так будет комфортнее играть)
    hitbox.width *= Config::Physics::Hitbox::PLAYER_HITBOX_WIDTH_PERCENTS;
    hitbox.left += hitbox.width * (1 - Config::Physics::Hitbox::PLAYER_HITBOX_WIDTH_PERCENTS) / 2;

    // Получаем направление движения
    Direction direction = (y_change < 0 ? Direction::Up : Direction::Down);
    // Данные о коллизии
    CollisionType collision_vert = map_.CheckForCollision(hitbox, direction);

    if (collision_vert == CollisionType::None) { // Если коллизии нет, просто изменяем y
        pos_.y += y_change;
    } else if (collision_vert == CollisionType::Unsafe) { // Небезопасная коллизия ведет к смерти
        is_alive_ = false;
        pos_.y += y_change;
    } else { // Коллизия безопасная (верхом или низом), регулирует y, чтобы игрок очутился вплотную к блоку
        if (direction == Direction::Up) {
            pos_.y = map_.NearestUp(hitbox);
        } else {
            pos_.y = map_.NearestDown(hitbox);
        }
        y_speed_ = 0;
    }

    // Проверяем коллизию по горизонтали
    CollisionType collision_horizontal = map_.CheckForCollision(hitbox, Direction::Right);
    if (collision_horizontal == CollisionType::Unsafe) {
        is_alive_ = false;
    }

    // Чтобы не падал слишком быстро
    if (y_speed_ > Config::Physics::PLAYER_MAX_SPEED_Y)
        y_speed_ = Config::Physics::PLAYER_MAX_SPEED_Y;

    // Позиция игрока
    sprite_.setPosition(pos_.x + size_.x / 2,
                        pos_.y + size_.y / 2);

    // Считаем угол наклона
    float max_angle = Config::Physics::PLAYER_ROTATION_ANGLE;
    sprite_.setRotation(max_angle * y_speed_ / Config::Physics::PLAYER_MAX_SPEED_Y);
}

void Player::OnDraw(sf::RenderWindow& window) {
    window.draw(sprite_);
}

void Player::OnEvent(sf::Event& event, const Timer& timer) {
    // Регулирует нажата мышка или нет
    if (event.type == sf::Event::MouseButtonPressed ||
        (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)) {
        mouse_pressed = true;
    } else if (event.type == sf::Event::MouseButtonReleased ||
        (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Space)) {
        mouse_pressed = false;
    }
}

void Player::LoadSizes() {
    float sprite_scale = map_.GetTileSize() / sprite_.getGlobalBounds().height;
    sprite_.setScale(sprite_scale, sprite_scale);
    sprite_.setOrigin({
                          sprite_.getLocalBounds().width / 2,
                          sprite_.getLocalBounds().height / 2,
                      });
    size_ = {sprite_.getGlobalBounds().width, sprite_.getGlobalBounds().height};

    pos_ = {map_.GetTileSize(), window_size_.y / 2};
}

void Player::LoadResources() {
    sprite_.setTexture(texture_);
}
bool Player::IsAlive() const {
    return is_alive_;
}
