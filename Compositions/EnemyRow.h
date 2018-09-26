//
// Created by Scott Anthony Guidotti  on 11/2/17.
//

#ifndef GALAGA_ENEMYROW_H
#define GALAGA_ENEMYROW_H

#include "../Component.h"

class EnemyRow: public Component{
public:

    bool isMovingLeft() override;

    bool isOnScreen() override;

    void moveHorizontal() override;

    void moveDown() override;

    void add(Component* component) override;

    void draw(sf::RenderWindow&) override;

    Components getComposite() override {return componentsList;}

private:
    bool moveLeft = true;
    std::vector<Component*> componentsList;
    void update();

};

#endif //GALAGA_ENEMYROW_H
