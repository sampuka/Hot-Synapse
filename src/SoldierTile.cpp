#include "SoldierTile.hpp"

SoldierTile::SoldierTile()
{
    tileType = TileType::Soldier;
}

SoldierTile::~SoldierTile()
{
}

sf::Shape* SoldierTile::getDrawShape()
{
    sf::CircleShape *shape = new sf::CircleShape(10);
    shape->setFillColor(sf::Color::Green);

    return shape;
}
