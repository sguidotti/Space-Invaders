//
// Created by Scott Anthony Guidotti  on 11/2/17.
//

#include "EnemyRow.h"

bool EnemyRow::isAlive()
{
    // assume dead unless we find a living enemy in row
    for(auto component: componentsList) {
        if(component->isAlive()) {
            // if a single enemy is alive then entire row is alive
            return true;
        }

    }
    // otherwise all are dead
    return false;
}

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
    for(auto component: componentsList) {
        component->draw(window);
    }
}

