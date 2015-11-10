#ifndef PADDLE_HEADER
#define PADDLE_HEADER

#include "Entity.hpp"

class Paddle final : protected Entity {
public:
    Paddle ();

    Paddle (const sf::Vector2f &, const sf::Vector2f &, const sf::Color &, const float &,
            const sf::Vector2i &);

    ~Paddle () = default;

    operator sf::RectangleShape& ();

    Paddle &setPosition (const float &, const float &) override;
    Paddle &setSpeed    (const float &) override;
    Paddle &setColor    (const sf::Color &) override;
    Paddle &setAngle    (const sf::Vector2i &) override;


    sf::RectangleShape &getObj ();

    Paddle &setWidth (const float &);
    Paddle &setHeight (const float &);

    sf::RectangleShape &getRect ();

    sf::Vector2f &getPosition ();
    sf::Vector2f getSpeed    () const;

    float getWidth () const;
    float getHeight () const;

    sf::Vector2i &getAngle ();

    sf::Color getColor () const;

    Paddle &Update ();

private:
    sf::RectangleShape Rect;
    sf::Vector2f RectSize;

};

#endif // PADDLE_HEADER
