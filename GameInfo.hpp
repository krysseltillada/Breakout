#ifndef GAME_INFO_HEADER
#define GAME_INFO_HEADER

#include <SFML/Graphics.hpp>

#include <memory>
#include <iostream>
#include <sstream>

class GameInfo {
public:
    GameInfo () = default;
    GameInfo (const std::string &, const int &, const int &);

    GameInfo &setPlayerScore (const int &);
    GameInfo &setPlayerLives (const int &);
    GameInfo &setFontFile (const std::string &);
    GameInfo &setFontSize (const int &);
    GameInfo &generateInfo ();
    GameInfo &increaseScore ();
    GameInfo &decreaseScore ();
    GameInfo &setMultiplier (const int &);

    GameInfo &Update ();

    sf::Text &GetObj2 ();
    sf::Text &GetObj1 ();

    int &getPlayerLives ();
    int &getPlayerScore ();

    std::string getfontFile ();


public:
    sf::Vector2f textPosition;
    sf::Vector2f livePosition;

private:
    sf::Font scoreFont;
    sf::Text scoreText;
    sf::Text lives;

    std::string fontFile;

    int playerLives;
    int playerScore;
    int fontSize;
    int multiplier;
};

#endif // GAME_INFO_HEADER
