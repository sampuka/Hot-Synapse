#include "MatchScreen.hpp"

#include "math.h"
#include <iostream>

using namespace std;

ostream& operator<<(ostream& os, const MatchScreenState& state)
{
    switch (state)
    {
    case MatchScreenState::StartOfMatch:
	os << "StartOfMatch";
	break;
	
    case MatchScreenState::Player1Move:
	os << "Player1Move";
	break;
	
    case MatchScreenState::Player1Action:
	os << "Player1Action";
	break;
	
    case MatchScreenState::Player2Move:
	os << "Player2Move";
	break;
	
    case MatchScreenState::Player2Action:
	os << "Player2Action";
	break;
	
    case MatchScreenState::Animation:
	os << "Animation";
	break;

    default:
	os << "Unhandled State (in ostream overload)";
    }

    return os;
}

MatchScreen::MatchScreen(sf::RenderWindow *_window)
{
    maxMoves = 5;
    movesExecuted = 0;
    activeSoldier = -1;
    currentState = MatchScreenState::StartOfMatch;
    window = _window;
    i = 0;
    
    //Init game
    MatchMap::setupMaps("Test Map", &mastermap, &player1map, &player2map, window->getSize());
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
    cout << "Current state: " << currentState << endl;
    
    mastermap->drawMap(window);

    for (sf::Event::KeyEvent key : keyList)
    {
	//Handle keyboard input switch
	switch(currentState)
	{
	case MatchScreenState::StartOfMatch:
	    if (key.code == sf::Keyboard::Return)
		currentState = MatchScreenState::Player1Move;
	    break;
	    
	case MatchScreenState::Player1Move:
	    if (activeSoldier == -1)
		activeSoldier = 0;
	    
	    switch (key.code)
	    {
	    case sf::Keyboard::D:
		player1moves.push_back(Direction::E);
		break;

	    case sf::Keyboard::A:
	        player1moves.push_back(Direction::W);
		break;

	    case sf::Keyboard::Return:
		currentState = MatchScreenState::Player1Action;
		break;
		
	    default:
		cout << "Unhandled key" << endl;
	    }

	    if (player1moves.size() > maxMoves)
	    {
		player1moves.pop_back();
		cout << "No more movement actions!" << endl;
	    }
	    
	    if (!mastermap->canMoveSoldier(activeSoldier, player1moves))
	    { ///BØR NOK VÆRE player1map
		cout << "Can't move there!" << endl;
		player1moves.pop_back();
	    }
	    
	    break;

	case MatchScreenState::Player1Action:
	    if (player1actionTile == sf::Vector2i(-1, -1))
		player1actionTile = mastermap->getPosition(activeSoldier);

	    switch (key.code)
	    {
	    case sf::Keyboard::D:
		player1actionTile.x++;
		break;

	    case sf::Keyboard::A:
	        player1actionTile.x--;
		break;

	    case sf::Keyboard::Return:
		currentState = MatchScreenState::Animation;
		break;
		
	    default:
		cout << "Unhandled key" << endl;
	    }

	    break;
	    
	default:
	    cout << "Unhandled state" << endl;
	}
    }

    //Update things switch
    switch(currentState)
    {
    case MatchScreenState::Animation:
	if (movesExecuted < maxMoves)
	{
	    mastermap->executeMove(activeSoldier, player1moves[movesExecuted]);
	    movesExecuted++;
	}
	else
	{
	    mastermap->executeAction(activeSoldier, player1actionTile, ActionType::Shoot);
	    movesExecuted = 0;
	    player1moves.clear();
	    player1actionTile = sf::Vector2i(-1, -1);
	    currentState = MatchScreenState::Player1Move;
	}
	    
	break;

    default:
	break;
	}
    
    //What to display switch
    switch(currentState)
    {
    case MatchScreenState::Animation:
    case MatchScreenState::StartOfMatch:
	mastermap->drawMap(window);
	break;

    case MatchScreenState::Player1Move:
    case MatchScreenState::Player1Action:
	mastermap->drawMap(window);
	//player1map->drawMap(window);
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
