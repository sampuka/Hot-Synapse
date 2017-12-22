#ifndef MAP_WALL_H
#define MAP_WALL_H

#include "MapEntity.hpp"

class MapWall : public MapEntity
{
public:
    MapWall(float xpos, float ypos, float xsize, float ysize, sf::Color color);
    ~MapWall();

    void updateShape(sf::Vector2u windowsize) override;
    sf::Shape* getShape() override;

private:
    sf::Vector2f size;
    sf::RectangleShape *shape;
};

#endif
