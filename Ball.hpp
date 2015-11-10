#ifndef BALL_HEADER
#define BALL_HEADER

#include "Entity.hpp"

class Ball final : protected Entity {
public:
    Ball ();

    Ball (const float &, const sf::Color &, const sf::Vector2f &,
          const float &, const sf::Vector2i &);

    operator sf::CircleShape & ();

    ~Ball () = default;

    Ball &setPosition (const float &, const float &) override;
    Ball &setSpeed    (const float &) override;
    Ball &setColor    (const sf::Color &) override;
    Ball &setAngle    (const sf::Vector2i &) override;

    Ball &setSize (const float &);

    sf::Vector2f &getPosition ();
    sf::Vector2f getSpeed () const;

    sf::Color getColor () const;

    float getSize () const;

    sf::Vector2i &getAngle ();

    Ball &Update ();

public:
    static constexpr float PI = 3.14159265359;

private:
    sf::CircleShape circle;
    float Radius = 0;

};

#endif // BALL_HEADER
