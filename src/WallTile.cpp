#include "WallTile.hpp"

WallTile::WallTile(sf::Color _color, float _hardness)
{
    color = _color;
    hardness = _hardness;
}

WallTile::~WallTile()
{
}

sf::Shape* WallTile::getDrawShape()
{
    sf::RectangleShape *shape = new sf::RectangleShape(sf::Vector2f(10,10));
    shape->setFillColor(color);

    return shape;
}

void WallTile::setHardness(float _hardness)
{
    hardness = _hardness;
}

float WallTile::getHardness()
{
    return hardness;
}
