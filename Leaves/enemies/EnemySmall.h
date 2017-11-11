//
// Created by Scott Anthony Guidotti  on 11/2/17.
//

#ifndef GALAGA_ENEMYSMALL_H
#define GALAGA_ENEMYSMALL_H

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "../../Component.h"


class EnemySmall:public Component {
public:
    EnemySmall();
    ~EnemySmall() override;
    explicit EnemySmall(sf::Vector2f position);
    void draw(sf::RenderWindow&) override;
    void moveHorizontal() override;

    bool isOnScreen() override;
    void die() override {alive = false; score += 100;}
    bool isAlive() override {return alive;}
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

#endif //GALAGA_ENEMYSMALL_H
