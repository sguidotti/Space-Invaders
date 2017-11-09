//
// Created by Scott Anthony Guidotti  on 11/2/17.
//

#include "ScreenComposite.h"

ScreenComposite::ScreenComposite() = default;

void ScreenComposite::add(Component* component)
{
    componentsList.push_back(component);
}
void ScreenComposite::draw(sf::RenderWindow& window)
{
    for(auto component: componentsList) {
        component->draw(window);
    }
}

void ScreenComposite::move(float deltaTime)
{
    for(auto component: componentsList) {
        component->move(deltaTime);
    }
}
