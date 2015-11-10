#include "Ball.hpp"

Ball::Ball () :
           Entity (sf::Vector2f (0, 0), sf::Vector2f (0, 0), sf::Color::White, sf::Vector2i (0, 0)),
           Radius (0) { }

Ball::Ball (const float &sz, const sf::Color &c, const sf::Vector2f &p,
            const float &s, const sf::Vector2i &a) : Entity (p, sf::Vector2f (s, s), c, a), Radius (sz) { }

Ball::operator sf::CircleShape & () {
    return circle;
}

Ball &Ball::setPosition (const float &x, const float &y) {
    position = sf::Vector2f (x, y);
    return *this;
}

Ball &Ball::setSpeed    (const float &s)  {
    position = sf::Vector2f (s, s);
    return *this;
}

Ball &Ball::setColor    (const sf::Color &c) {
    objectColor = c;
    return *this;
}

Ball &Ball::setAngle (const sf::Vector2i &a) {
    angle = a;
    return *this;
}

Ball &Ball::setSize (const float &r) {
    Radius = r;
    return *this;
}

sf::Vector2f &Ball::getPosition () {
    return position;
}

sf::Vector2f Ball::getSpeed () const {
    return speed;
}

sf::Color Ball::getColor () const {
    return objectColor;
}

float Ball::getSize () const {
    return Radius;
}

sf::Vector2i &Ball::getAngle ()  {
    return angle;
}

Ball &Ball::Update () {
    circle.setRadius (Radius);
    circle.setFillColor (objectColor);
    circle.setPosition (position.x, position.y);
    return *this;
}
