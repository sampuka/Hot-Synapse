#ifndef MATCH_SCREEN_H
#define MATCH_SCREEN_H

#include <SFML/Graphics.hpp>

#include "GameScreen.hpp"
#include "MatchMap.hpp"

enum class MatchScreenState
{
    SoldierInput,
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
    int movesLeft;
    
    sf::RenderWindow *window;
    MatchMap *map;
    float i;
};

#endif
