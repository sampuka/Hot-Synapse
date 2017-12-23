#ifndef GAME_SCREEN_H
#define GAME_SCREEN_H

#include <vector>

enum class GameState
{
    MainManu,
    Match
};

class GameScreen
{
public:
    virtual void update(std::vector<sf::Event::KeyEvent> keyList) = 0;
    virtual GameState nextScreen() = 0;
};

#endif
