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

    sf::FloatRect getBoundingBox() override;

    sf::Sprite* getSprite() override;

    bool isOnScreen() override;
    bool isAlive() override {return alive;}
    void die() override {alive = false; }

private:
    const int velocity = -1000;
    sf::Sprite* sprite;
    sf::Texture textureA;
    sf::FloatRect boundingBox;
    bool onScreen = false;
    bool alive = false;

};


#endif //GALAGA_BULLET_H
