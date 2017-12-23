#include "MapTile.hpp"

MapTile::~MapTile()
{
}

TileType MapTile::getType()
{
    return tileType;
}

sf::Shape* MapTile::getDrawShape()
{
    sf::RectangleShape *shape = new sf::RectangleShape(sf::Vector2f(1,1));
    shape->setFillColor(sf::Color(0,0,0,0));

    return shape;
}
