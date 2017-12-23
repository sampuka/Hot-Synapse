#ifndef OCCUPANCY_TILE_H
#define OCCUPANCY_TILE_H

#include "MapTile.hpp"

class OccupancyTile : public MapTile
{
public:
    OccupancyTile(int _xppos, int _yppos);
    ~OccupancyTile();

    //sf::Shape* getDrawShape() override;
    
private:
    int xppos;
    int yppos;
};

#endif
