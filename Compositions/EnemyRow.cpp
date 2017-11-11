//
// Created by Scott Anthony Guidotti  on 11/2/17.
//

#include "EnemyRow.h"

bool EnemyRow::isMovingLeft()
{
    return moveLeft;
}

bool EnemyRow::isOnScreen()
{
    // assume all are onscreen unless one isnt then end there
    for(auto component: componentsList) {
        if(!component->isOnScreen()) {
            return false;
        }
    }
    // if function makes it here all must be on screen
    return true;
}

void EnemyRow::moveHorizontal()
{
    for(auto component: componentsList) {
        component->moveHorizontal();
    }
}

void EnemyRow::moveDown()
{
    for(auto component: componentsList) {
        component->moveDown();
    }
}

void EnemyRow::add(Component* component)
{
    componentsList.push_back(component);
}

void EnemyRow::draw(sf::RenderWindow& window)
{
    update();
    for(auto component: componentsList) {
        component->draw(window);
    }
}

void EnemyRow::update()
{
    componentsList.erase(std::remove_if(componentsList.begin(), componentsList.end(),
            [](Component* c) {return !c->isAlive();}),
            componentsList.end());
}



