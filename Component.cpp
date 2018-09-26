//
// Created by Scott Anthony Guidotti  on 10/25/17.
//

#include <vector>
#include <SFML/Graphics/Sprite.hpp>
#include "Component.h"

Component::Component() = default;

void Component::add(Component*)
{

}

void Component::move(float)
{

}

void Component::draw(sf::RenderWindow&)
{

}

Component::Components Component::getComposite()
{
    return Components{};
}

void Component::moveDown()
{

}

void Component::moveHorizontal()
{

}

sf::FloatRect Component::getBoundingBox()
{
    return {};
}

sf::Vector2f Component::getPosition()
{
    return {};
}

sf::Sprite* Component::getSprite()
{
    return nullptr;
}

Component::~Component() = default;
int Component::score = 0;



