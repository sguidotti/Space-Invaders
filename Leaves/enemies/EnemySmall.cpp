#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "EnemySmall.h"



EnemySmall::EnemySmall(){

    // move texture and position to inside constructor
    textureA.loadFromFile("images/invader-3-frame-1(2).png");
    textureB.loadFromFile("images/invader-3-frame-2(2).png");
    sprite = new sf::Sprite(textureA);
    boundingBox = sprite->getGlobalBounds();
}

EnemySmall::EnemySmall(sf::Vector2f position)
        :EnemySmall()
{
    sprite->setPosition(position);
}

void EnemySmall::draw(sf::RenderWindow& window)
{
    window.draw(*sprite);
}

void EnemySmall::moveHorizontal()
{
    sprite->move(offsetX);
    swapTexture();

}

void EnemySmall::moveDown()
{
    sprite->move(offsetY);
    // reverse direction
    offsetX.x *= -1;
}

bool EnemySmall::isOnScreen()
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

void EnemySmall::swapTexture()
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

EnemySmall::~EnemySmall()
= default;

