#ifndef GAME_SCREEN_H
#define GAME_SCREEN_H

enum class GameState
{
    MainManu,
    Match
};

class GameScreen
{
public:
    virtual void update() = 0;
    virtual GameState nextScreen() = 0;
};

#endif
