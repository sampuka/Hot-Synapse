#ifndef MATCH_SCREEN_H
#define MATCH_SCREEN_H

#include <SFML/Graphics.hpp>

#include "GameScreen.hpp"
#include "MatchMap.hpp"

enum class MatchScreenState
{
    StartOfMatch,
    Player1Move,
    Player1Action,
    Player2Move,
    Player2Action,
    Animation
};

class MatchScreen : public GameScreen
{
public:
    MatchScreen(sf::RenderWindow *_window);
    ~MatchScreen();

    void update(std::vector<sf::Event::KeyEvent> keyList) override;
    GameState nextScreen() override;

private:
    MatchScreenState currentState;
    int activeSoldier;
    //int movesLeft;
    
    sf::RenderWindow *window;
    MatchMap *mastermap;
    MatchMap *player1map;
    MatchMap *player2map;

    std::vector<Direction> moveList;
    sf::Vector2i actionTile;
    
    float i; //For the test circle animation
};

#endif
