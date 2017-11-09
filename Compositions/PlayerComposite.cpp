//
// Created by Scott Anthony Guidotti  on 11/2/17.
//

#include <SFML/Window/Keyboard.hpp>
#include "PlayerComposite.h"
#include "../Leaves/Bullet.h"

PlayerComposite::PlayerComposite() = default;

void PlayerComposite::add(Component* component)
{
    componentsList.push_back(component);
}
void PlayerComposite::draw(sf::RenderWindow& window)
{
    for(auto component: componentsList) {
        component->draw(window);
    }
}

void PlayerComposite::move(float deltaTime)
{
//    check if a bullet was fired
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !isFired) {
        sf::Vector2f position = componentsList[0]->getPosition();
        position.y -=50;
        Component* temp = new Bullet(position);
        add(temp);
        isFired = true;
    }
    for(auto component: componentsList) {
        component->move(deltaTime);
        if(!component->isOnScreen()) remove();
    }
}

void PlayerComposite::remove()
{
    // remove bullet that is no longer on screen
    componentsList.pop_back();
    // reset so that another bullet may be fired
    isFired = false;
}
