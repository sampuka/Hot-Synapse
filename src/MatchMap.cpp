#include "MatchMap.hpp"

#include "WallTile.hpp"
#include "EmptyTile.hpp"
#include "SoldierTile.hpp"
#include "OccupancyTile.hpp"

#include <iostream>

using namespace std;

MatchMap::MatchMap(string _mapName, sf::Vector2u windowsize)
{
    mapName = _mapName;
    //soldiers.clear(); //needed?

    if (mapName == "Test Map")
    {
	cout << "Making \"Test Map\"" << endl;
	backgroundColor = sf::Color(200, 200, 200);
	mapsize = sf::Vector2i(30, 30);
	
	for (int i = 0; i < mapsize.x; i++)
	{
	    tileArray.push_back({});
	    for (int j = 0; j < mapsize.y; j++)
		tileArray[i].push_back(new EmptyTile);
	}

	for (int i = 1; i < mapsize.x-1; i++)
	{
	    setWallTile(i, 0, sf::Color::Black, 500);
	    setWallTile(i, 29, sf::Color::Black, 500);   
	    /*
	    delete tileArray[i][0];
	    delete tileArray[i][29];
	    tileArray[i][0] = new WallTile(sf::Color::Black, 500);
	    tileArray[i][29] = new WallTile(sf::Color::Black, 500);
	    */
	}
	
	for (int j = 0; j < mapsize.y; j++)
	{
	    setWallTile(0, j, sf::Color::Black, 500);
	    setWallTile(29, j, sf::Color::Black, 500);
	    /*
	    delete tileArray[0][j];
	    delete tileArray[29][j];
	    tileArray[0][j] = new WallTile(sf::Color::Black, 500);
	    tileArray[29][j] = new WallTile(sf::Color::Black, 500);
	    */
	}

	spawnSoldier(2, 2);

	cout << "Made \"Test Map\"" << endl;
    }
    else
	cout << "No matching map" << endl;

    //updateShapes(windowsize);
}

MatchMap::~MatchMap()
{
}

void MatchMap::updateShapes(sf::Vector2u windowsize)
{
    cout << "Updating shapes" << endl;
    /*
      for (MapEntity *ent : entityList)
      ent->updateShape(windowsize);
    */
}

void MatchMap::drawMap(sf::RenderWindow *window)
{
    //cout << "Begin drawMap" << endl;
    window->clear(backgroundColor);
    for (int i = 0; i < mapsize.x; i++)
	for (int j = 0; j < mapsize.y; j++)
	{
	    sf::Shape *shape = tileArray[i][j]->getDrawShape();
	    shape->setPosition(20*i, 20*j);
	    shape->setScale(20.f/10, 20.f/10);
	    window->draw(*shape);
	    delete shape;
	}
    
/*     
       sf::RectangleShape rect(sf::Vector2f(20,20));
       
       for (int i = 0; i < mapsize.x; i++)
       for (int j = 0; j < mapsize.y; j++)
       {
       rect.setPosition(20*i, 20*j);
       rect.setFillColor(sf::Color(i*10, j*10, 0));
       window->draw(rect);
       }
*/
    
/*
  window->clear(backgroundColor);
  for (MapEntity *ent : entityList)
  {
  window->draw(*(ent->getShape()), sf::RenderStates::Default);
  }
*/
}

void MatchMap::setEmptyTile(int xpos, int ypos)
{
    delete tileArray[xpos][ypos];
    tileArray[xpos][ypos] = new EmptyTile;
}

void MatchMap::setWallTile(int xpos, int ypos, sf::Color color, float hardness)
{
    delete tileArray[xpos][ypos];
    tileArray[xpos][ypos] = new WallTile(color, hardness);
}

void MatchMap::spawnSoldier(int xpos, int ypos)
{
    setSoldierTile  (xpos, ypos);
    setOccupancyTile(xpos+1, ypos  , xpos, ypos);
    setOccupancyTile(xpos  , ypos+1, xpos, ypos);
    setOccupancyTile(xpos+1, ypos+1, xpos, ypos);

    soldiers.push_back(sf::Vector2i(xpos, ypos));
}

bool MatchMap::moveSoldier(int soldierNumber, Direction dir)
{
    cout << "Moving Soldier" << endl;
    sf::Vector2i soldierPos = soldiers[soldierNumber]; //segfault possible?
    switch (dir)
    {
    case Direction::E:
	if (
	    isTileClear(soldierPos.x+2, soldierPos.y  ) &&
	    isTileClear(soldierPos.x+2, soldierPos.y+1)
	    )
	{
	    setEmptyTile(soldierPos.x, soldierPos.y  );
	    setEmptyTile(soldierPos.x, soldierPos.y+1);
	    spawnSoldier(soldierPos.x+1, soldierPos.y);
	    return true;
	}
	else
	    return false;
	break;

    default:
	cout << "Unhandled direction" << endl;
	return false;
    }
}

bool MatchMap::isTileClear(int xpos, int ypos)
{
    TileType type = tileArray[xpos][ypos]->getType();

    return type == TileType::Empty;
}

void MatchMap::setSoldierTile(int xpos, int ypos)
{
    delete tileArray[xpos][ypos];
    tileArray[xpos][ypos] = new SoldierTile;
}

void MatchMap::setOccupancyTile(int xpos, int ypos, int xppos, int yppos)
{
    delete tileArray[xpos][ypos];
    tileArray[xpos][ypos] = new OccupancyTile(xppos, yppos);
}
