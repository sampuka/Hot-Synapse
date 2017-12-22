#include "MapWall.hpp"

MapWall::MapWall(float xpos, float ypos, float xsize, float ysize, sf::Color color)
{
    position.x = xpos;
    position.y = ypos;
    size.x = xsize;
    size.y = ysize;

    shape = new sf::RectangleShape(size);
    shape->setPosition(position);
    shape->setFillColor(color);
}

MapWall::~MapWall()
{
    delete shape;
}

void MapWall::updateShape(sf::Vector2u windowsize)
{
    sf::Vector2f newpos;
    newpos.x = windowsize.x * position.x / 100.f;
    newpos.y = windowsize.y * position.y / 100.f;

    sf::Vector2f newsize;
    newsize.x = windowsize.x * size.x / 100.f;
    newsize.y = windowsize.y * size.y / 100.f;

    shape->setPosition(newpos);
    shape->setSize(newsize);
}

sf::Shape* MapWall::getShape()
{
    return shape;
}
