//
// Created by Scott Anthony Guidotti  on 10/26/17.
//

#include "RowComposite.h"

RowComposite::RowComposite() = default;

void RowComposite::add(Component* component)
{
    componentsList.push_back(component);
}

void RowComposite::move(float deltaTime)
{
    deltaTime = clock.getElapsedTime().asSeconds();
    if(deltaTime >= interval) {
        clock.restart();
        for(auto component: componentsList) {
            if(!component->isOnScreen()) {
                direction = vertical;
                break;
            }
            else direction = horizontal;
        }
        switch(direction) {
        case vertical: {
            for(auto component: componentsList) {
                component->moveDown();
            }
            break;
        } case horizontal: {
            for(auto component: componentsList) {
                component->moveHorizontal();
            }
            break;
        }
        }
    }
}

void RowComposite::draw(sf::RenderWindow& window)
{
    for(auto component: componentsList) {
        component->draw(window);
    }
}
