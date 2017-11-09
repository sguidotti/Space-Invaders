//
// Created by Scott Anthony Guidotti  on 11/2/17.
//

#ifndef GALAGA_ENEMYMEDIUM_H
#define GALAGA_ENEMYMEDIUM_H

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "../../Component.h"

class EnemyMedium:public Component {
public:
    EnemyMedium();
    ~EnemyMedium() override;
    explicit EnemyMedium(sf::Vector2f position);
    void draw(sf::RenderWindow&) override;
    void moveHorizontal() override;

    bool isOnScreen() override;

    void moveDown() override;
    void swapTexture();
private:
    sf::Sprite* sprite;
    sf::FloatRect boundingBox;
    sf::Vector2f offsetX{20,0};
    const sf::Vector2f offsetY{0,70};
    bool alive = true;
    bool onScreen = false;
    sf::Texture textureA;
    sf::Texture textureB;
    enum textures{first, second};
    textures currentTexture = first;





};

#endif //GALAGA_ENEMYMEDIUM_H
