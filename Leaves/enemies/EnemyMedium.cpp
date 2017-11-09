#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "EnemyMedium.h"



EnemyMedium::EnemyMedium(){
    textureA.loadFromFile("images/invader-2-frame-2(2).png");
    textureB.loadFromFile("images/invader-2-frame-1(2).png");
    // move texture and position to inside constructor
    sprite = new sf::Sprite(textureA);
    boundingBox = sprite->getGlobalBounds();
}

EnemyMedium::EnemyMedium(sf::Vector2f position)
        :EnemyMedium()
{
    sprite->setPosition(position);
}

void EnemyMedium::draw(sf::RenderWindow& window)
{
    window.draw(*sprite);
}

void EnemyMedium::moveHorizontal()
{
    sprite->move(offsetX);
    swapTexture();

}

void EnemyMedium::moveDown()
{
    sprite->move(offsetY);
    // reverse direction
    offsetX.x *= -1;
}

bool EnemyMedium::isOnScreen()
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

void EnemyMedium::swapTexture()
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

EnemyMedium::~EnemyMedium()
= default;

