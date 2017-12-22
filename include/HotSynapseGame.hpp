#ifndef HOT_SYNAPSE_GAME_H
#define HOT_SYNAPSE_GAME_H

#include <SFML/Graphics.hpp>

#include "GameScreen.hpp"

class HotSynapseGame
{
public:
    HotSynapseGame();
    ~HotSynapseGame();

    bool isGameClosed();

private:
    void main_loop();
    
    sf::RenderWindow *window;
    bool gameClosed;
    GameState gameState;
    GameScreen *gameScreen;
};

#endif
