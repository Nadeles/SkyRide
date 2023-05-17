#include "GameScene.h"
#include "../../Resources/Resources.h"

#include <fstream>

GameScene::GameScene(const MenuScene& menu_scene) : menu_scene_(menu_scene) {
    Reload();
}

void GameScene::Reload() {
    // В зависимости от состояния меню загружаем нужные данные
    std::ifstream in_file;
    if (menu_scene_.LevelSelected() == Selected::First) {
        in_file.open(Config::Map::LEVELS[0]);
    } else {
        in_file.open(Config::Map::LEVELS[1]);
    }

    map_ = std::make_unique<Map>(in_file);

    if (menu_scene_.PlayerSelected() == Selected::First) {
        player_ = std::make_unique<Player>(*map_, Resources::PLAYER_TEXTURE_1());
    } else {
        player_ = std::make_unique<Player>(*map_, Resources::PLAYER_TEXTURE_2());
    }
}

void GameScene::OnFrame(const Timer& timer) {
    // В зависимости от состояния игры, определенным образом обрабатываем кадр
    if (!game_end_) {
        map_->OnFrame(timer);
        player_->OnFrame(timer);
        if (!player_->IsAlive()) {
            game_end_ = true;
            time_after_end_ = 0;
        }
    } else {
        time_after_end_ += timer.GetDelta();
        if (time_after_end_ >= Config::Time::TIME_AFTER_END) {
            game_end_ = false;
            Reload();
        }
    }
}

void GameScene::OnDraw(sf::RenderWindow& window) {
    map_->OnDraw(window);
    player_->OnDraw(window);
}

void GameScene::OnEvent(sf::Event& event, const Timer& timer) {
    map_->OnEvent(event, timer);
    player_->OnEvent(event, timer);
}
