#include "MatchScreen.hpp"

#include "math.h"
#include <iostream>

using namespace std;

MatchScreen::MatchScreen(sf::RenderWindow *_window)
{
    activeSoldier = -1;
    currentState = MatchScreenState::SoldierInput;
    window = _window;
    i = 0;
    
    //Init game
    map = new MatchMap("Test Map", window->getSize());
}

MatchScreen::~MatchScreen()
{
    delete map;
}

void MatchScreen::update(vector<sf::Event::KeyEvent> keyList)
{
    map->drawMap(window);

    for (sf::Event::KeyEvent key : keyList)
    {
	switch(currentState)
	{
	case MatchScreenState::SoldierInput:
	    if (activeSoldier == -1)
		activeSoldier = 0;
	    
	    switch (key.code)
	    {
	    case sf::Keyboard::D:
		if(!map->moveSoldier(activeSoldier, Direction::E))
		    cout << "Couldn't move there!" << endl;
		break;

	    case sf::Keyboard::A:
		if(!map->moveSoldier(activeSoldier, Direction::W))
		    cout << "Couldn't move there!" << endl;
		break;
		
	    default:
		cout << "Unhandled key" << endl;
	    }

	    
	    
	    break;
	    
	default:
	    cout << "Unhandled state" << endl;
	}
    }
    
    sf::CircleShape circ(10);
    circ.setPosition(300+90*cos(i), 300+90*sin(i));
    i+=0.2;
    window->draw(circ);
}

GameState MatchScreen::nextScreen()
{
    return GameState::Match;
}
