//
// Created by Scott Anthony Guidotti  on 10/26/17.
//

#ifndef GALAGA_COMPOSITIONCHARACTER_H
#define GALAGA_COMPOSITIONCHARACTER_H

#include <vector>
#include <SFML/Graphics/RenderWindow.hpp>
#include "../Component.h"

class RowComposite:public Component {
public:
    RowComposite();
    void add(Component* component) override;
    void move(float deltaTime) override;
    void draw(sf::RenderWindow&) override;
    Components getComposite() override {return componentsList;}

private:
    std::vector<Component*> componentsList;
    enum moveType{horizontal, vertical};
    sf::Clock clock;
    const float interval = 1.5;
    moveType direction = horizontal;
};

#endif //GALAGA_COMPOSITIONCHARACTER_H
