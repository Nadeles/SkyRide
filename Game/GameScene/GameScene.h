#pragma once
#include "../../Scene/Scene.h"
#include "Map/Map.h"
#include "Player/Player.h"
#include "../MenuScene/MenuScene.h"

class GameScene : public Scene {
public:
    ~GameScene() override = default;

    GameScene(const MenuScene& menu_scene);
    void OnFrame(const Timer& timer) override;
    void OnDraw(sf::RenderWindow& window) override;
    void OnEvent(sf::Event& event, const Timer& timer) override;

    void Reload();
private:
    // Остановленна ли игра
    bool game_end_ = false;
    // Время, прошедшее после окончания игры
    float time_after_end_ = 0;

    // Ссылка на меню, для получения данных для запуска
    const MenuScene& menu_scene_;

    std::unique_ptr<Map> map_;
    std::unique_ptr<Player> player_;
};
