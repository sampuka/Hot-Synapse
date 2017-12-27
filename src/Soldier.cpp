#include "Soldier.hpp"

Soldier::Soldier(int xpos, int ypos)
{
    position = sf::Vector2i(xpos, ypos);
    health = 100;
    hasMoved = false;
    alive = true;
}

Soldier::~Soldier()
{
}

void Soldier::setPosition(sf::Vector2i _position)
{
    position = _position;
}

void Soldier::setPosition(int xpos, int ypos)
{
    position = sf::Vector2i(xpos, ypos);
}

sf::Vector2i Soldier::getPosition()
{
    return position;
}

void Soldier::setMoved(bool _hasMoved)
{
    hasMoved = _hasMoved;
}

bool Soldier::isReadyToMove()
{
    return hasMoved && alive;
}
