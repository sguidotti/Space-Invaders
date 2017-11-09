//
// Created by Scott Anthony Guidotti  on 11/2/17.
//

#ifndef GALAGA_PLAYER_H
#define GALAGA_PLAYER_H

#include <SFML/Graphics/Sprite.hpp>
#include "../Component.h"

class Player: public Component {
public:
    Player();
    ~Player() override;
    explicit Player(sf::Vector2f position);
    void move(float deltaTime) override;
    void draw(sf::RenderWindow&) override;
    sf::Vector2f getPosition() override;

    bool isOnScreen() override;

private:
    sf::Sprite* sprite;
    sf::Texture textureA;
    float velocity = 200;
    bool movingLeft = true;
    bool alive = true;
    bool atBorder = false;



};

#endif //GALAGA_PLAYER_H
