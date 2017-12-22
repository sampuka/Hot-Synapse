#ifndef MAP_ENTITY_H
#define MAP_ENTITY_H

#include <SFML/Graphics.hpp>

enum class EntityType
{
    Wall,
    Window,
    HalfWall
};

class MapEntity
{
public:
//    MapEntity();
//    ~MapEntity();
    
//    void setShape(sf::Shape *shape);
    virtual void updateShape(sf::Vector2u windowsize) = 0;
    virtual sf::Shape* getShape() = 0;

    void setHardness(float _hardness);
    float getHardness();

    void setPosition(float xpos, float ypos);
    void setPosition(sf::Vector2f _position);
    sf::Vector2f getPosition();
    
protected:
    sf::Vector2f position;
    float hardness;
    EntityType entityType;
};

#endif
