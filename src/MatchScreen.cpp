#include "MatchScreen.hpp"

#include "math.h"
#include <iostream>

using namespace std;

MatchScreen::MatchScreen(sf::RenderWindow *_window)
{
    activeSoldier = -1;
    currentState = MatchScreenState::StartOfMatch;
    window = _window;
    i = 0;
    
    //Init game
    MatchMap::setupMaps("Test Map", &mastermap, &player1map, &player2map);
    mastermap->getSoldiers();
    /*
    mastermap = new MatchMap("Test Map", window->getSize(), 0);
    player1map = new MatchMap("Test Map", window->getSize(), 1);
    player2map = new MatchMap("Test Map", window->getSize(), 2);
    */
}

MatchScreen::~MatchScreen()
{
    delete mastermap;
    delete player1map;
    delete player2map;
}

void MatchScreen::update(vector<sf::Event::KeyEvent> keyList)
{
    mastermap->drawMap(window);

    for (sf::Event::KeyEvent key : keyList)
    {
	switch(currentState)
	{
	case MatchScreenState::StartOfMatch:
	    if (key.code == sf::Keyboard::Return)
		currentState = MatchScreenState::Player1Input;
	    break;
	    
	case MatchScreenState::Player1Move:
	    if (activeSoldier == -1)
		activeSoldier = 0;
	    
	    switch (key.code)
	    {
	    case sf::Keyboard::D:
		moveList.push_back(Direction::E);
		break;

	    case sf::Keyboard::A:
	        moveList.push_back(Direction::W);
		break;

	    case sf::Keyboard::Return:
		currentState = MatchScreenState::Player1Action;
		break;
		
	    default:
		cout << "Unhandled key" << endl;
	    }

	    if (moveList.size() > 5)
	    {
		moveList.pop_back();
		cout << "No more movement actions!" << endl;
	    }
	    
	    if (!player1map->canMoveSoldier(activeSoldier, moveList))
	    {
		cout << "Can't move there!" << endl;
		moveList.pop_back();
	    }
	    
	    break;

	case MatchScreenState::Player1Action:
	    if (actionTile == sf::Vector2i(-1, -1))
		actionTile = getPosition(activeSoldier);

	    switch (key.code)
	    {
	    case sf::Keyboard::D:
		actionTile.x++;
		break;

	    case sf::Keyboard::A:
	        actionTile.x--;
		break;

	    case sf::Keyboard::Return:
		currentState = MatchScreenState::Animation;
		break;
		
	    default:
		cout << "Unhandled key" << endl;
	    }

	    break;

	case MatchScreenState::Animation:
	    mastermap->executeTurn(moveList, actionTile, ActionType::Shoot);
	    break;
	    
	default:
	    cout << "Unhandled state" << endl;
	}
    }

    switch(currentState)
    {
    case MatchScreenState::Animation:
    case MatchScreenState::StartOfGame:
	mastermap->drawMap(window);
	break;

    case MatchScreenState::Player1Move:
    case MatchScreenState::Player1Action:
	player1map->drawMap(window);
	break;

    case MatchScreenState::Player2Move:
    case MatchScreenState::Player2Action:
	player2map->drawMap(window);
	break;

    default:
	cout << "Unhandled state2" << endl;
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
