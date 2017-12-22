#include "MatchScreen.hpp"

MatchScreen::MatchScreen(sf::RenderWindow *_window)
{
    window = _window;
    
    //Init game
    map = new MatchMap("Test Map", window->getSize());
}

MatchScreen::~MatchScreen()
{
}

void MatchScreen::update()
{
    map->drawMap(window);
}

GameState MatchScreen::nextScreen()
{
    return GameState::Match;
}
