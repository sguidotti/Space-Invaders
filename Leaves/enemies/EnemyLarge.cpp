#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "EnemyLarge.h"



EnemyLarge::EnemyLarge(){
    textureA.loadFromFile("images/invader-1-frame-2(2).png");
    textureB.loadFromFile("images/invader-1-frame-1(2).png");
    // move texture and position to inside constructor
    sprite = new sf::Sprite(textureA);
    boundingBox = sprite->getGlobalBounds();
}

EnemyLarge::EnemyLarge(sf::Vector2f position)
        :EnemyLarge()
{
    sprite->setPosition(position);
}

void EnemyLarge::draw(sf::RenderWindow& window)
{
    window.draw(*sprite);
}

void EnemyLarge::moveHorizontal()
{
    sprite->move(offsetX);
    swapTexture();

}

void EnemyLarge::moveDown()
{
    sprite->move(offsetY);
    // reverse direction
    offsetX.x *= -1;
}

bool EnemyLarge::isOnScreen()
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

void EnemyLarge::swapTexture()
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

EnemyLarge::~EnemyLarge()
= default;

