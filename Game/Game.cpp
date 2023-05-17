#include "Game.h"

Game::Game() {
    // Инициализация сцен
    menu_scene_ = std::make_shared<MenuScene>();
    game_scene_ = std::make_shared<GameScene>(*menu_scene_);
    cur_scene_ = menu_scene_;
}

void Game::Run() {
    // Создание окна
    std::unique_ptr<sf::RenderWindow> window;
    if (sf::VideoMode::getFullscreenModes().empty()) {
        window = std::make_unique<sf::RenderWindow>(sf::VideoMode::getDesktopMode(), "SFML-Collection");
    } else {
        window = std::make_unique<sf::RenderWindow>(sf::VideoMode::getDesktopMode(),
                                                    "SFML-Collection",
                                                    sf::Style::Fullscreen);
    }

    // Запуск игрового цикла
    GameCycle(*window);
}

void Game::GameCycle(sf::RenderWindow& window) {
    Timer timer;
    sf::Event event{};

    // Цикл пока открыто окно
    while (window.isOpen()) {
        window.clear();
        timer.Update();

        // Обработка изменений
        cur_scene_->OnFrame(timer);

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed
                || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape &&
                    cur_state_ == GameAction::Menu)) { // Если закрыто окно, или в меню нажат Escape, конец игры
                window.close();
            }

            if (cur_state_ == GameAction::Menu) { // Eсли в меню и нажат Enter - запуск игры
                if (event.type == sf::Event::KeyPressed) {
                    if (event.key.code == sf::Keyboard::Enter) {
                        cur_scene_ = game_scene_;
                        cur_state_ = GameAction::Game;
                        game_scene_->Reload();
                    }
                }
            } else {
                if (event.type == sf::Event::KeyPressed) { // Если в игре и нажат Escape, переходим в меню
                    if (event.key.code == sf::Keyboard::Escape) {
                        cur_scene_ = menu_scene_;
                        cur_state_ = GameAction::Menu;
                        game_scene_->Reload();
                    }
                }
            }

            // Обработка событий сценой
            cur_scene_->OnEvent(event, timer);
        }
        // Отрисовка
        cur_scene_->OnDraw(window);
        window.display();
    }
}
