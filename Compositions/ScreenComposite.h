//
// Created by Scott Anthony Guidotti  on 11/2/17.
//

#ifndef GALAGA_SCREENCOMPOSITE_H
#define GALAGA_SCREENCOMPOSITE_H

#include "../Component.h"

class ScreenComposite: public Component {
public:
    ScreenComposite();
    void add(Component* component) override;
    void move(float deltaTime) override;
    void draw(sf::RenderWindow&) override;
    Component* getComposite() override {return this;}
private:
    std::vector<Component*> componentsList;
};

#endif //GALAGA_SCREENCOMPOSITE_H
