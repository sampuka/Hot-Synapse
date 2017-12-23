#include "EmptyTile.hpp"

EmptyTile::EmptyTile()
{
    tileType = TileType::Empty;
}

EmptyTile::~EmptyTile()
{
}



sf::Shape* EmptyTile::getDrawShape()
{
    sf::RectangleShape *shape = new sf::RectangleShape(sf::Vector2f(10,10));
    shape->setFillColor(sf::Color(200,200,200));
    
    return shape;
}
