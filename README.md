## SkyRide

Этот проект представляет собой игру, написанную с использованием библиотеки SFML. Для сборки проекта выполните следующие шаги:

## Зависимости:

Если вы на Windows, установите [SFML 2.5.1 для MinGW](https://www.sfml-dev.org/download/sfml/2.5.1/) и положите папку на диск C.

На Linux установите библиотеки для разработки на SFML

    sudo apt-get install libsfml-dev

## Сборка проекта:

    # Клонируйте репозиторий проекта с помощью команды git clone.
    git clone https://github.com/Nadeles/SkyRide
    
    # Перейдите в корневую директорию проекта.
    cd SkyRide

    # Создайте директорию build для сборки проекта.
    mkdir build

    # Перейдите в директорию build.
    cd build

    # Сгенерируйте файлы сборки с помощью команды cmake
    cmake ..
    # Выполните команду make для сборки проекта.
    cmake --build .
    
    # Выход из build и запуск игры
    cd ..
    ./build/SkyRide
