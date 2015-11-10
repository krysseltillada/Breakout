#ifndef GAME_HEADER
#define GAME_HEADER

#include "Ball.hpp"
#include "Paddle.hpp"
#include "Collision.hpp"
#include "TileEngine.hpp"
#include "GameInfo.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <windows.h>

#include <iostream>
#include <string>
#include <memory>
#include <cstdlib>
#include <iomanip>
#include <random>

class Game {
public:
    enum GameStatus {
        GAME_EXIT_SUCCESS,
        GAME_EXIT_FAILURE,
    };

    enum InGameStatus {
        GAME_OVER,
        GAME_START,
        GAME_BEGIN,
        GAME_RESET,
        GAME_WIN,
    };

    enum class KeyInputs {
        LEFT,
        RIGHT
    };

public:
    static void Run ();
    static void Init ();
    static void Event (const sf::Event &, sf::RenderWindow &, KeyInputs &);
    static void Update (Paddle &, Ball &, KeyInputs &, const float &, std::default_random_engine &, TileEngine &, GameInfo &, std::vector <sf::Sound> &);
    static void Draw (Paddle &, Ball &, sf::RenderWindow &, TileEngine &, GameInfo &);

private:
    static int status;
    static const std::string GameName;
    static const int gameWidth;
    static const int gameHeight;


};

#endif // GAME_HEADER
