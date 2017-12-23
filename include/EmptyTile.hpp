#ifndef EMPTY_TILE_H
#define EMPTY_TILE_H

#include "MapTile.hpp"

class EmptyTile : public MapTile
{
public:
    EmptyTile();
    ~EmptyTile();

//    sf::Shape* getDrawShape() override;
};

#endif
