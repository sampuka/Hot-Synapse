#ifndef MATCH_SCREEN_H
#define MATCH_SCREEN_H

#include <SFML/Graphics.hpp>

#include "GameScreen.hpp"
#include "MatchMap.hpp"

class MatchScreen : public GameScreen
{
public:
    MatchScreen(sf::RenderWindow *_window);
    ~MatchScreen();

    void update() override;
    GameState nextScreen() override;

private:
    sf::RenderWindow *window;
    MatchMap *map;
};

#endif
