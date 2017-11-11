//
// Created by Scott Anthony Guidotti  on 11/2/17.
//

#ifndef GALAGA_ENEMYLARGE_H
#define GALAGA_ENEMYLARGE_H

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "../../Component.h"


class EnemyLarge:public Component {
public:
    EnemyLarge();
    ~EnemyLarge() override;
    explicit EnemyLarge(sf::Vector2f position);
    void draw(sf::RenderWindow&) override;
    void moveHorizontal() override;

    bool isOnScreen() override;
    bool isAlive() override {return alive;}
    void die() override {alive = false; score += 60;}
    void moveDown() override;
    void swapTexture();

    sf::Sprite* getSprite() override;

    sf::FloatRect getBoundingBox() override;

private:
    sf::Sprite* sprite;
    sf::FloatRect boundingBox;
    sf::Vector2f offsetX{20,0};
    const sf::Vector2f offsetY{0,70};
    bool alive = true;
    bool onScreen = false;
    enum textures{first, second};
    textures currentTexture = first;
    sf::Texture textureA;
    sf::Texture textureB;

};

#endif //GALAGA_ENEMYLARGE_H
