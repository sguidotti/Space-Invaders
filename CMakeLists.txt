cmake_minimum_required(VERSION 3.8)
project(Galaga)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp
        Game.cpp Game.h
        Component.cpp Component.h
        Compositions/RowComposite.cpp Compositions/RowComposite.h
        "Observer Pattern Abstract/Subject.cpp" "Observer Pattern Abstract/Subject.h"
        "Observer Pattern Abstract/Observer.cpp" "Observer Pattern Abstract/Observer.h"
        Compositions/EnemyRow.cpp Compositions/EnemyRow.h Leaves/Player.cpp Leaves/Player.h Leaves/enemies/EnemySmall.cpp Leaves/enemies/EnemySmall.h Leaves/enemies/EnemyMedium.cpp Leaves/enemies/EnemyMedium.h Leaves/enemies/EnemyLarge.cpp Leaves/enemies/EnemyLarge.h Compositions/ScreenComposite.cpp Compositions/ScreenComposite.h Leaves/Bullet.cpp Leaves/Bullet.h Compositions/PlayerComposite.cpp Compositions/PlayerComposite.h)

#add subdirectories


#create executable
add_executable(galaga ${SOURCE_FILES})

#include sfml
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(galaga ${SFML_LIBRARIES})
endif()

