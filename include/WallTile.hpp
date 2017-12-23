#ifndef WALL_TILE_H
#define WALL_TILE_H

#include "MapTile.hpp"

class WallTile : public MapTile
{
public:
    WallTile(sf::Color _color, float _hardness);
    ~WallTile();

    sf::Shape* getDrawShape() override;

    void setHardness(float _hardness);
    float getHardness();
    
private:
    sf::Color color;
    float hardness;
};

#endif
