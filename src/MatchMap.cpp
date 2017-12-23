#include "MatchMap.hpp"

#include "WallTile.hpp"
#include "EmptyTile.hpp"

#include <iostream>

using namespace std;

MatchMap::MatchMap(string _mapName, sf::Vector2u windowsize)
{
    mapName = _mapName;

    if (mapName == "Test Map")
    {
	cout << "Making \"Test Map\"" << endl;
	backgroundColor = sf::Color(200, 200, 200);
	mapsize = sf::Vector2i(30, 30);
	
	for (int i = 0; i < mapsize.x; i++)
	{
	    //cout << "1" << endl;
	    tileArray.push_back({});
	    //cout << "2" << endl;
	    //cout << tileArray.size() << endl;
	    for (int j = 0; j < mapsize.y; j++)
		tileArray[i].push_back(new EmptyTile);
	}

	for (int i = 1; i < mapsize.x-1; i++)
	{
	    delete tileArray[i][0];
	    delete tileArray[i][29];
	    tileArray[i][0] = new WallTile(sf::Color::Black, 500);
	    tileArray[i][29] = new WallTile(sf::Color::Black, 500);
	}
	
	for (int j = 0; j < mapsize.y; j++)
	{
	    delete tileArray[0][j];
	    delete tileArray[29][j];
	    tileArray[0][j] = new WallTile(sf::Color::Black, 500);
	    tileArray[29][j] = new WallTile(sf::Color::Black, 500);
	}

	cout << "Made \"Test Map\"" << endl;
	/*
	  MapWall *wall;

	  wall = new MapWall(25, 10, 50, 10, sf::Color::Green);
	  wall->setHardness(100);
	  entityList.push_back(wall);

	  wall = new MapWall(25, 80, 50, 10, sf::Color::Green);
	  wall->setHardness(50);
	  entityList.push_back(wall);
	*/
    }
    else
	cout << "No matching map" << endl;

    updateShapes(windowsize);
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
