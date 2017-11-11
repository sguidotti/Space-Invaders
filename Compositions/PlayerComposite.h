//
// Created by Scott Anthony Guidotti  on 11/2/17.
//

#ifndef GALAGA_PLAYERCOMPOSITE_H
#define GALAGA_PLAYERCOMPOSITE_H

#include <vector>
#include "../Component.h"

class PlayerComposite: public Component {
public:
    PlayerComposite();
    void add(Component* component) override;
    void move(float deltaTime) override;
    void draw(sf::RenderWindow&) override;
    void remove();
    Components getComposite() override {return componentsList;}
private:
    std::vector<Component*> componentsList;
    bool isFired = false;
};

#endif //GALAGA_PLAYERCOMPOSITE_H
