//
// Created by Scott Anthony Guidotti  on 11/2/17.
//

#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "Player.h"

Player::Player()
{
    textureA.loadFromFile("images/playerShip.png");
    sprite = new sf::Sprite(textureA);
    // move texture and position to inside constructor
    float width = sprite->getGlobalBounds().width;
    float height = sprite->getGlobalBounds().height;
    sprite->setOrigin(width/2, height/2);
    sprite->setPosition(400, 800 - height);
}

Player::~Player()
= default;

Player::Player(sf::Vector2f position): Player()
{
    sprite->setPosition(position);
}

void Player::move(float deltaTime)
{
    auto width = sprite->getGlobalBounds().width/2;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        if(sprite->getPosition().x - width <= 0)
            return;
        sprite->move(deltaTime * -velocity, 0);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        if(sprite->getPosition().x + width >= 800)
            return;
        sprite->move(deltaTime * velocity, 0);
    }
}

void Player::draw(sf::RenderWindow& window)
{
    window.draw(*sprite);
}

sf::Vector2f Player::getPosition()
{
    return sprite->getPosition();
}

bool Player::isOnScreen()
{
    return true;
}

sf::Sprite* Player::getSprite()
{
    return sprite;
}
