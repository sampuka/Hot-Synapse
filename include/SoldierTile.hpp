#ifndef SOLDIER_TILE_H
#define SOLDIER_TILE_H

#include "MapTile.hpp"

class SoldierTile : public MapTile
{
public:
    SoldierTile();
    ~SoldierTile();

    sf::Shape* getDrawShape() override;
};

#endif
