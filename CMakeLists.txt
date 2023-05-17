cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_STANDARD 20)
project(SkyRide)


find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_executable(SkyRide
        Config/Config.cpp
        main.cpp
        Scene/Scene.cpp Scene/Timer.cpp

        Resources/Resources.cpp

        Game/Game.cpp
        Game/GameScene/GameScene.cpp
        Game/GameScene/Map/Map.cpp
        Game/GameScene/Player/Player.cpp
        Game/MenuScene/MenuScene.cpp
        )

target_link_libraries(SkyRide sfml-network sfml-audio sfml-graphics sfml-window sfml-system)
