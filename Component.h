//
// Created by Scott Anthony Guidotti  on 10/25/17.
//

#ifndef GALAGA_COMPONENT_H
#define GALAGA_COMPONENT_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>

class Component{
public:
    typedef std::vector<Component*> Components;
    Component();
    virtual ~Component();
    virtual void draw(sf::RenderWindow&);
    virtual void add(Component*);
    virtual void move(float);
    virtual Components getComposite();
    virtual bool isMovingLeft() {return false;}
    virtual bool isOnScreen() {return false;}
    virtual void moveHorizontal();
    virtual void moveDown();
    virtual sf::FloatRect getBoundingBox();
    virtual sf::Vector2f getPosition();
    virtual void die() {};
    virtual bool isAlive() {return false;}
    virtual sf::Sprite* getSprite();
};

#endif //GALAGA_COMPONENT_H
