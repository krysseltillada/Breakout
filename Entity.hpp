#ifndef ENTITY_HEADER
#define ENTITY_HEADER

#include <SFML/Graphics.hpp>

#include <iostream>

class Entity {
protected:
    Entity (const sf::Vector2f &p, const sf::Vector2f &s,
            const sf::Color &c, const sf::Vector2i &a) :
                position (p), speed (s), objectColor (c), angle (a) { }

    virtual Entity &setPosition (const float &, const float &) = 0;
    virtual Entity &setSpeed    (const float &) = 0;
    virtual Entity &setColor    (const sf::Color &) = 0;
    virtual Entity &setAngle    (const sf::Vector2i &) = 0;

protected:
    sf::Vector2f position;
    sf::Vector2f speed;

    sf::Color objectColor;

    sf::Vector2i angle;
};

#endif // ENTITY_HEADER
