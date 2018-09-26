#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "Enemy.h"

Enemy::Enemy(std::string fileA, std::string fileB, sf::Vector2f position)
{

    // move texture and position to inside constructor
    textureA.loadFromFile(fileA);
    textureB.loadFromFile(fileB);
    sprite = new sf::Sprite(textureA);
    boundingBox = sprite->getGlobalBounds();
    sprite->setPosition(position);
}

void Enemy::draw(sf::RenderWindow& window)
{
    window.draw(*sprite);
}

void Enemy::moveHorizontal()
{
    sprite->move(offsetX);
    swapTexture();

}

void Enemy::moveDown()
{
    sprite->move(offsetY);
    // reverse direction
    offsetX.x *= -1;
}

bool Enemy::isOnScreen()
{
    // assume not at the edge
    onScreen = true;
    float leftCorner = sprite->getPosition().x;
    float rightCorner = sprite->getPosition().x + boundingBox.width;
    if(leftCorner + offsetX.x <=10 ||
            rightCorner + offsetX.x >= 790) {
        onScreen = false;
    }
    return onScreen;

}

void Enemy::swapTexture()
{
    if(currentTexture == first) {
        sprite->setTexture(textureB);
        currentTexture = second;
    }
    else {
        sprite->setTexture(textureA);
        currentTexture = first;
    }
}

sf::FloatRect Enemy::getBoundingBox()
{
    boundingBox = sprite->getGlobalBounds();
    return boundingBox;
}

sf::Sprite* Enemy::getSprite()
{
    return sprite;
}

Enemy::~Enemy()
= default;

