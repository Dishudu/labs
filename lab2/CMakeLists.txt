cmake_minimum_required(VERSION 3.10)

# Название проекта
project(TurnBasedStrategy)

# Включить поддержку C++
set(CMAKE_CXX_STANDARD 17)

# Установить директорию для заголовочных файлов
include_directories(include)

# Добавить исходные файлы проекта
set(SOURCES
    src/GameObject.cpp
    src/Unit.cpp
    src/Archer.cpp
    src/Building.cpp
    src/Fort.cpp
    src/MobileHouse.cpp
    main.cpp
)

# Создать исполняемый файл
add_executable(game ${SOURCES})