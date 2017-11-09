//
// Created by Scott Anthony Guidotti  on 10/25/17.
//

#ifndef GALAGA_GAME_H
#define GALAGA_GAME_H

#include <SFML/Graphics/RenderWindow.hpp>

class Game: public sf::RenderWindow {
public:
    Game(const sf::VideoMode& mode, const sf::String& title, sf::Uint32 style = sf::Style::Default,
            const sf::ContextSettings& settings = sf::ContextSettings());
};

#endif //GALAGA_GAME_H
