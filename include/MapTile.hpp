#ifndef MAP_TILE_H
#define MAP_TILE_H

#include <SFML/Graphics.hpp>

enum class TileType
{
    Empty,
    Wall,
    Window,
    Halfwall
};

class MapTile
{
public:
    virtual ~MapTile();
    
    TileType getType();
    virtual sf::Shape* getDrawShape() = 0;

protected:
    TileType tileType;
};

#endif
