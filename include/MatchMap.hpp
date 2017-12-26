#ifndef MATCH_MAP_H
#define MATCH_MAP_H

#include "MapTile.hpp"
#include "Soldier.hpp"

//#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

enum class Direction
{
    N,
    E,
    S,
    W,
    NE,
    SE,
    SW,
    NW
};

class MatchMap
{
public:
    MatchMap(std::string _mapName, sf::Vector2u windowsize);
    ~MatchMap();

    void updateShapes(sf::Vector2u windowsize);
    void drawMap(sf::RenderWindow *window);

    void setEmptyTile(int xpos, int ypos);
    void setWallTile(int xpos, int ypos, sf::Color color, float hardness);

    void spawnSoldier(int xpos, int ypos);
    bool moveSoldier(int soldierNumber, Direction dir);
    int getSoldiers();
    sf::Vector2i getPosition(int soldier);
    bool canMoveSoldier(int activeSoldier, std::vector<Direction> moves);

    static void setupMaps(std::string _mapName, MatchMap **mastermap, MatchMap **player1map, MatchMap **player2map, sf::Vector2u windowsize);

    void executeMove(int activeSoldier, Direction dir);
    void executeAction(int activeSoldier, sf::Vector2i actionTile, ActionType action); 
    
private:
    bool isTileClear(int xpos, int ypos);
    void setSoldierTile(int xpos, int ypos);
    void setOccupancyTile(int xpos, int ypos, int xppos, int yppos);
    
    std::string mapName;
    sf::Vector2i mapsize;
    sf::Color backgroundColor;
    std::vector< std::vector<MapTile*> > tileArray;

    std::vector<sf::Vector2i> soldiers;
};

#endif
