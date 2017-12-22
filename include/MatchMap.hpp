#ifndef MATCH_MAP_H
#define MATCH_MAP_H

#include "MapEntity.hpp"

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

class MatchMap
{
public:
    MatchMap(std::string _mapName, sf::Vector2u windowsize);
    ~MatchMap();

    void updateShapes(sf::Vector2u windowsize);
    void drawMap(sf::RenderWindow *window);
    
private:
    std::string mapName;
    sf::Color backgroundColor;
    std::vector<MapEntity*> entityList;
};

#endif
