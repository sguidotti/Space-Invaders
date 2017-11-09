//
// Created by Scott Anthony Guidotti  on 11/2/17.
//

#include "Bullet.h"

Bullet::Bullet()
{
    textureA.loadFromFile("images/bullet.png");
    sprite = new sf::Sprite(textureA);
    sprite->scale(0.5,0.5);
    boundingBox = sprite->getGlobalBounds();
}

Bullet::Bullet(sf::Vector2f position):Bullet()
{
    sprite->setPosition(position);
}

void Bullet::move(float deltaTime)
{
    sprite->move(0, deltaTime*velocity);
    if(sprite->getPosition().y < 0) onScreen = false;
}

bool Bullet::isOnScreen()
{
    return onScreen;
}

void Bullet::draw(sf::RenderWindow& window)
{
    window.draw(*sprite);
}
