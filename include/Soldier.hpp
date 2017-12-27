#ifndef SOLDIER_H
#define SOLDIER_H

#include <SFML/Graphics.hpp>

enum class ActionType
{
    Shoot
};

class Soldier
{
public:
    Soldier(int xpos, int ypos);
    ~Soldier();

    void setPosition(sf::Vector2i _position);
    void setPosition(int xpos, int ypos);
    sf::Vector2i getPosition();

    void setMoved(bool _hasMoved);
    bool isReadyToMove();
    
private:
    sf::Vector2i position;
    int health;
    bool hasMoved;
    bool alive;
};

#endif
