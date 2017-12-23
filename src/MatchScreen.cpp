#include "MatchScreen.hpp"
#include "math.h"

MatchScreen::MatchScreen(sf::RenderWindow *_window)
{
    window = _window;
    i = 0;
    
    //Init game
    map = new MatchMap("Test Map", window->getSize());
}

MatchScreen::~MatchScreen()
{
    delete map;
}

void MatchScreen::update()
{
    map->drawMap(window);

    
    sf::CircleShape circ(10);
    circ.setPosition(300+90*cos(i), 300+90*sin(i));
    i+=0.2;
    window->draw(circ);
}

GameState MatchScreen::nextScreen()
{
    return GameState::Match;
}
