#include "MapEntity.hpp"

/*
MapEntity::MapEntity()
{
}

MapEntity::~MapEntity()
{
}
*/

/*
void setShape(sf::Shape *_shape)
{
    shape = _shape;
}
*/

/*
void MapEntity::updateShape()
{
    return shape;
}
*/

void MapEntity::setHardness(float _hardness)
{
    hardness = _hardness;
}

float MapEntity::getHardness()
{
    return hardness;
}

void MapEntity::setPosition(float xpos, float ypos)
{
    position.x = xpos;
    position.y = ypos;
}

void MapEntity::setPosition(sf::Vector2f _position)
{
    position = _position;
}

sf::Vector2f MapEntity::getPosition()
{
    return position;
}
