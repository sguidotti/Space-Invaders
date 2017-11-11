#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Compositions/RowComposite.h"
#include "Compositions/EnemyRow.h"
#include "Leaves/enemies/EnemySmall.h"
#include "Leaves/enemies/EnemyMedium.h"
#include "Leaves/enemies/EnemyLarge.h"
#include "Compositions/ScreenComposite.h"
#include "Leaves/Player.h"
#include "Compositions/PlayerComposite.h"
#include "Colissions.h"

int main()
{
    // create window
    const int height = 800;
    const int width = 800;
    Game game(sf::VideoMode(width, height), "Galaga");
    game.setVerticalSyncEnabled(true);

    sf::Text prompt;
    sf::Font font;
    font.loadFromFile("images/gyparody_rg.ttf");

    prompt.setCharacterSize(30);
    prompt.setFillColor(sf::Color::White);
    prompt.setString("Score: ");
    prompt.setPosition(320, 30);
    // point values are in the enemy file
    prompt.setFont(font);


// todo refactor all this shit

    // create sprite
    Component* enemyRows;
    enemyRows = new RowComposite;
    sf::Vector2f position {75, 100};
    for(int i = 0; i < 3; ++i) {
        Component* row = new EnemyRow;
        for(int j = 0; j < 6; ++j) {
            sf::Vector2f temp;
            temp.x = position.x + (j * 100);
            temp.y = position.y + (i * 100);
            if(i == 0) {
                Component* enemy = new EnemySmall(temp);
                row->add(enemy);
            } else if(i == 1) {
                Component* enemy = new EnemyMedium(temp);
                row->add(enemy);
            } else if(i == 2) {
                Component* enemy = new EnemyLarge(temp);
                row->add(enemy);
            }
        }
        enemyRows->add(row);
    }
    Component* player = new PlayerComposite;
    player->add(new Player());
    Component* screen = new ScreenComposite;
    screen->add(player);
    screen->add(enemyRows);

    // create delta time
    sf::Clock clock;
    sf::Time deltaTime;
    while (game.isOpen()) {
        deltaTime = clock.restart();
        sf::Event event{};
        // event loop to check if window closed
        while (game.pollEvent(event)) {
            if (event.type==sf::Event::Closed) {
                game.close();
            }
        }
        // update game
        screen->move(deltaTime.asSeconds());

        // check for collisons
        auto playerObjs = player->getComposite();
        auto enemyObjs = enemyRows->getComposite();
        for(auto i : playerObjs) {
            for(auto j : enemyObjs) {
                auto k = j->getComposite();
                for(auto enemy: k) {
                    if(Collision::BoundingBoxTest(*(i->getSprite()), *(enemy->getSprite()))){
                        i->die();
                        enemy->die();
                    }
                }


            }
        }
        // clear screen
        game.clear(sf::Color::Black);

        sf::Text gameScore;
        gameScore.setFillColor(sf::Color::White);
        gameScore.setCharacterSize(30);
        gameScore.setPosition(410,30);
        gameScore.setString(std::to_string(Component::score));
        gameScore.setFont(font);


        // draw game
        screen->draw(game);
        game.draw(gameScore);
        game.draw(prompt);


        // display game
        game.display();
    }
    return 0;
}