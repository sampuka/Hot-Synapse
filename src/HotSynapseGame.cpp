#include <SFML/System.hpp>

#include "HotSynapseGame.hpp"
#include "MatchScreen.hpp"

#include <iostream>

using namespace std;

HotSynapseGame::HotSynapseGame()
{
    window = new sf::RenderWindow(sf::VideoMode(600, 600), "Hot Synapse");
    window->clear();
    cout << "test" << endl;
    main_loop();
}

HotSynapseGame::~HotSynapseGame()
{
    delete window;
}

bool HotSynapseGame::isGameClosed()
{
    return gameClosed;
}

void HotSynapseGame::main_loop()
{
    gameClosed = false;
    gameState = GameState::Match;
    gameScreen = new MatchScreen(window);
    
    while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
        }

	switch (gameState)
	{
	    
	case GameState::Match:
	    if (gameScreen->nextScreen() != GameState::Match)
	    {
		cout << "Went from Match" << endl;
	    }
	    gameScreen->update();
	    break;

	default:
	    cout << "Not Match gameState?" << endl;
	    break;
	}
	sf::sleep(sf::milliseconds(50)); //20 FPS (max)
	window->display();
	window->clear();
	
    }
    gameClosed = true;
}
