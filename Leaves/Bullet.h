//
// Created by Scott Anthony Guidotti  on 11/2/17.
//

#ifndef GALAGA_BULLET_H
#define GALAGA_BULLET_H

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "../Component.h"

class Bullet: public Component {
public:
    Bullet();

    explicit Bullet(sf::Vector2f);

    void move(float deltaTime) override;

    void draw(sf::RenderWindow&) override;

    bool isOnScreen() override;

private:
    const int velocity = -1000;
    sf::Sprite* sprite;
    sf::Texture textureA;
    sf::FloatRect boundingBox;
    bool onScreen = true;

};


#endif //GALAGA_BULLET_H
