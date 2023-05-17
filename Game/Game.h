#pragma once

#include "GameScene/GameScene.h"
#include "MenuScene/MenuScene.h"

#include <memory>

// Класс текущего состояния игры
enum class GameAction {
    Menu, Game
};

class Game {
public:
    Game();
    // Запускает игровой цикл
    void Run();

private:
    // Основной игровой цикл
    void GameCycle(sf::RenderWindow& window);

    // Текущая сцена
    std::shared_ptr<Scene> cur_scene_;

    // Текущее состояние
    GameAction cur_state_ = GameAction::Menu;

    // Возможные состояния
    std::shared_ptr<MenuScene> menu_scene_;
    std::shared_ptr<GameScene> game_scene_;
};
