//
// Created by Scott Anthony Guidotti  on 11/2/17.
//

#ifndef GALAGA_ENEMYROW_H
#define GALAGA_ENEMYROW_H

#include "../Component.h"

class EnemyRow: public Component{
public:
    bool isAlive() override;

    bool isMovingLeft() override;

    bool isOnScreen() override;

    void moveHorizontal() override;

    void moveDown() override;

    void add(Component* component) override;


    void draw(sf::RenderWindow&) override;

    Component* getComposite() override {return this;}

private:
    bool moveLeft = true;
    std::vector<Component*> componentsList;

};

#endif //GALAGA_ENEMYROW_H
