#include "MatchMap.hpp"

#include "MapWall.hpp"

#include <iostream>

using namespace std;

MatchMap::MatchMap(string _mapName, sf::Vector2u windowsize)
{
    mapName = _mapName;

    if (mapName == "Test Map")
    {
	backgroundColor = sf::Color(200, 200, 200);
	MapWall *wall;

	wall = new MapWall(25, 10, 50, 10, sf::Color::Green);
	wall->setHardness(100);
	entityList.push_back(wall);

	wall = new MapWall(25, 80, 50, 10, sf::Color::Green);
	wall->setHardness(50);
	entityList.push_back(wall);
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
    for (MapEntity *ent : entityList)
	ent->updateShape(windowsize);
}

void MatchMap::drawMap(sf::RenderWindow *window)
{
    window->clear(backgroundColor);
    for (MapEntity *ent : entityList)
    {
	window->draw(*(ent->getShape()), sf::RenderStates::Default);
    }
}
