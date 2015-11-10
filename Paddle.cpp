#include "Paddle.hpp"

Paddle::Paddle () :
        Entity (sf::Vector2f (0, 0), sf::Vector2f (0, 0), sf::Color::White, sf::Vector2i (0, 0)),
        RectSize (sf::Vector2f (0, 0)) { }

Paddle::Paddle (const sf::Vector2f &rs, const sf::Vector2f &p, const sf::Color &c, const float &s,
                const sf::Vector2i &a) :
                Entity (p, sf::Vector2f (s, s), c, a), RectSize(rs) { }

Paddle::operator sf::RectangleShape & () {
    return Rect;
}

Paddle &Paddle::setPosition (const float &x, const float &y) {
    position = sf::Vector2f (x, y);
    return *this;
}

Paddle &Paddle::setSpeed    (const float &s) {
    speed = sf::Vector2f (s, s);
    return *this;
}

Paddle &Paddle::setColor    (const sf::Color &c) {
    objectColor = c;
    return *this;
}

Paddle &Paddle::setAngle    (const sf::Vector2i &a) {
    angle = a;
    return *this;
}

Paddle &Paddle::setWidth (const float &w) {
    RectSize.x = w;
    return *this;
}

Paddle &Paddle::setHeight (const float &h) {
    RectSize.y = h;
    return *this;
}

sf::RectangleShape &Paddle::getRect () {
    return Rect;
}

sf::Vector2f &Paddle::getPosition () {
    return position;
}

sf::Vector2f Paddle::getSpeed    () const {
    return speed;
}

sf::RectangleShape &Paddle::getObj () {
    return Rect;
}

float Paddle::getWidth () const {
    return RectSize.x;
}

float Paddle::getHeight () const {
    return RectSize.y;
}

sf::Vector2i &Paddle::getAngle () {
    return angle;
}

sf::Color Paddle::getColor () const {
    return objectColor;
}

Paddle &Paddle::Update () {
    Rect.setFillColor (objectColor);
    Rect.setPosition (position.x, position.y);
    Rect.setSize (RectSize);

    return *this;
}


