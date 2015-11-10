#include "Game.hpp"

const std::string Game::GameName = "breakout";

const int Game::gameWidth = 640;
const int Game::gameHeight = 480;

int Game::status = InGameStatus::GAME_BEGIN;

void Game::Run () {
        Game::Init ();
}

void Game::Init () {
    std::default_random_engine gen;

    std::unique_ptr <sf::RenderWindow> sp_gameWindow (new sf::RenderWindow (sf::VideoMode (gameWidth, gameHeight), GameName));
    std::unique_ptr <sf::Event> sp_gameEvent (new sf::Event);

    std::unique_ptr <Ball> sp_ball (new Ball (10, sf::Color(255, 198, 238), sf::Vector2f (gameHeight / 2, gameWidth / 2), 0.40f, sf::Vector2i(0, 90)));
    std::unique_ptr <Paddle> sp_paddle (new Paddle (sf::Vector2f (100, 10), sf::Vector2f (gameWidth / 2, 450), sf::Color(255, 198, 238), 8000, sf::Vector2i (0, 90)));

    sp_paddle->getObj ().setOutlineThickness (2);
    sp_paddle->getObj ().setOutlineColor (sf::Color(255, 81, 233));

    KeyInputs playerInput;

    sf::Font font;
    sf::Text message;

    std::vector <sf::SoundBuffer> vecBuffer(2);
    std::vector <sf::Sound> vecSound;

    vecBuffer.push_back (sf::SoundBuffer ());
    vecBuffer.push_back (sf::SoundBuffer ());

    vecSound.push_back (sf::Sound ());
    vecSound.push_back (sf::Sound ());

    vecBuffer[0].loadFromFile ("bounce.wav");
    vecBuffer[1].loadFromFile ("gameover.wav");

    vecSound[0].setBuffer (vecBuffer[0]);
    vecSound[1].setBuffer (vecBuffer[1]);


    font.loadFromFile("minecraft/Minecraft.ttf");
    message.setFont(font);

    message.setCharacterSize (20);
    message.setPosition (220, 180);
    message.setString ("press any key to start");
    message.setColor (sf::Color(255, 81, 233));

    TileEngine test;
    GameInfo info ("minecraft/Minecraft.ttf", 3, 0);

    info.textPosition.x = gameWidth - 150;
    info.textPosition.y = gameHeight - 100;

    info.setFontSize (30);
    info.setMultiplier(10);
    info.generateInfo();

    test.setTileMap ("tilemap.txt");

    sf::Clock gameClock;

    // TODO MAKE A MESSAGE TO DISPLAY FROM A USER

    while (sp_gameWindow->isOpen ()) {
            sf::Time time = gameClock.restart ();
            while (sp_gameWindow->pollEvent (*sp_gameEvent)) {
                    Game::Event (*sp_gameEvent, *sp_gameWindow, playerInput);
            }

            if (status == Game::InGameStatus::GAME_START) {

            Game::Update (*sp_paddle, *sp_ball, playerInput, time.asSeconds (), gen, test, info, vecSound);

            Game::Draw (*sp_paddle, *sp_ball, *sp_gameWindow, test, info);

            } else if (status == Game::InGameStatus::GAME_OVER) {

                message.setString("try again? press any arrow keys ");

                if (sp_gameEvent->type == sf::Event::KeyPressed) {
                    vecSound[1].play ();

                    info.setPlayerLives(3);
                    info.setPlayerScore(0);

                    sp_ball->setPosition (250, 320);

                    test.getTileMap().clear ();
                    test.getSpriteMap().clear ();
                    test.clearTileCount();
                    test.setTileMap("tilemap.txt");

                    status = Game::InGameStatus::GAME_START;
                }

                sp_gameWindow->draw (message);
                sp_gameWindow->display ();
                sp_gameWindow->clear (sf::Color::White);
            } else if (status == Game::InGameStatus::GAME_BEGIN) {
                message.setString ("Breakout \n press any arrow keys");

                if (sp_gameEvent->type == sf::Event::KeyPressed)
                    status = Game::InGameStatus::GAME_START;

                sp_gameWindow->draw (message);
                sp_gameWindow->display ();
                sp_gameWindow->clear (sf::Color::White);
            } else if (status == Game::InGameStatus::GAME_RESET) {

                if (sp_gameEvent->type ==sf::Event::KeyPressed) {
                    status = Game::InGameStatus::GAME_START;

                    --info.getPlayerLives();
                    sp_ball->setPosition (250, 320);

                }else {
                    message.setString ("press any arrows keys to continue");
                    message.setPosition (160, 290);

                    sp_gameWindow->draw (message);
                }

                Game::Draw (*sp_paddle, *sp_ball, *sp_gameWindow, test, info);

            } else if (status == Game::InGameStatus::GAME_WIN) {

                    if (sp_gameEvent->type == sf::Event::KeyPressed) {
                        info.setPlayerLives(3);
                        info.setPlayerScore(0);

                        sp_ball->setPosition (250, 320);

                        test.getTileMap().clear ();
                        test.getSpriteMap().clear ();
                        test.setTileMap("tilemap.txt");

                        status = Game::InGameStatus::GAME_START;
                    } else {
                    message.setString ("you win :D thanks for playing \n press any arrow key to start again");
                    message.setPosition (160, 290);

                    sp_gameWindow->draw (message);
                    }

                    Game::Draw (*sp_paddle, *sp_ball, *sp_gameWindow, test, info);

                }


        }

}

void Game::Event (const sf::Event &gameEvent, sf::RenderWindow &gameWindow, KeyInputs &keyinput) {
    if (gameEvent.type == sf::Event::Closed)
        gameWindow.close ();

    if (gameEvent.type == sf::Event::KeyPressed) {

        if (sf::Keyboard::isKeyPressed (sf::Keyboard::Left))
                keyinput = KeyInputs::LEFT;
        else if (sf::Keyboard::isKeyPressed (sf::Keyboard::Right))
                keyinput = KeyInputs::RIGHT;
    }

}

void Game::Update (Paddle &p, Ball &b, KeyInputs &keyinput, const float &deltaTime, std::default_random_engine &gen, TileEngine &test, GameInfo &info, std::vector <sf::Sound> &sounds) {
    std::uniform_int_distribution <int> Anglex1 (110, 230);
    std::uniform_int_distribution <int> Anglex2 (20, 80);
    std::uniform_int_distribution <int> Angley1 (220, 300);
    std::uniform_int_distribution <int> Angley2 (1, 70);

    // TO DO MAKE A BOUNDARY ON EACH WALL OF THE WINDOW

    sf::FloatRect bounds = p.getRect ().getGlobalBounds ();

    if (!bounds.contains (sf::Vector2f (0, 450))) {

    if (keyinput == KeyInputs::LEFT) {

        p.getPosition ().x -= deltaTime * p.getSpeed ().x;
        keyinput = static_cast <KeyInputs> (3);
    }

    }

    if (!bounds.contains (sf::Vector2f (gameWidth, 450))) {


    if (keyinput == KeyInputs::RIGHT) {
                        p.getPosition ().x += deltaTime * p.getSpeed ().x;
                        keyinput = static_cast <KeyInputs> (3);
                        }

    }

    if (b.getPosition ().y >= gameHeight) {
            status = Game::InGameStatus::GAME_RESET;
            if (info.getPlayerLives() == 0) {
                status = Game::InGameStatus::GAME_OVER;
            }
    }

    if (b.getPosition ().y <= gameHeight - gameHeight) {
        sounds[0].play ();
        b.setAngle(sf::Vector2i (Anglex1 (gen), Angley2(gen)));

    }

    if (b.getPosition ().x >= gameWidth) {
            sounds[0].play ();
            b.setAngle (sf::Vector2i(Anglex1 (gen), b.getAngle().y));
    }

    if (b.getPosition ().x <= gameWidth - gameWidth) {
            sounds[0].play ();
            b.setAngle (sf::Vector2i (Anglex2 (gen), b.getAngle().y));
    }

    if (Collision::CircleToRectangle(b.getPosition().x, b.getPosition().y, b.getSize(),
                                     p.getPosition().x, p.getPosition().y, p.getWidth(), p.getHeight())) {
                                        sounds[0].play ();
                                        b.setAngle(sf::Vector2i(b.getAngle().x,Angley1(gen)));
                                     }

    for (unsigned x = 0; x != test.getTileMap().size (); ++x) {
            for (unsigned y = 0; y != test.getTileMap().at (x).size (); ++y) {
                if (test.getTileMap().at (x).at(y).x != -1 &&
                    test.getTileMap().at (x).at(y).y != -1) {
                           if (Collision::CircleToTile(b.getPosition().x, b.getPosition().y,
                                            test.getSprite(x, y).getPosition ().x,
                                            test.getSprite(x, y).getPosition ().y,
                                            test.getSprite(x, y).getGlobalBounds ().width,
                                            test.getSprite(x, y).getGlobalBounds ().height)) {

                                                test.getTileMap().at (x).at(y).x = -1;
                                                test.getTileMap().at (x).at(y).y = -1;
                                                --test.getTileCount ();

                                                sounds[0].play ();

                                                b.setAngle(sf::Vector2i(b.getAngle().x, -b.getAngle().y));

                                                std::cout << test.getTileCount() << std::endl;

                                                info.increaseScore();
                                            }

                    }
            }
    }

    //std::cout << test.getTileCount () << std::endl;

    if (test.getTileCount () == 0) {
        status = Game::InGameStatus::GAME_WIN;
    }


    b.getPosition ().x += std::cos (b.getAngle().x * Ball::PI / 180) * b.getSpeed().x;
    b.getPosition ().y += std::sin (b.getAngle().y * Ball::PI / 180) * b.getSpeed().x;

    p.Update ();
    b.Update ();
    info.Update();
}

void Game::Draw (Paddle &p, Ball &b, sf::RenderWindow &gameWindow, TileEngine &test, GameInfo &info) {

    for (unsigned x = 0; x != test.getTileMap().size (); ++x) {
        for (unsigned y = 0; y != test.getTileMap().at (x).size (); ++y) {
            if (test.getTileMap().at(x).at(y).x != -1 &&
                test.getTileMap().at(x).at(y).y != -1)
                    gameWindow.draw (test.getSprite(x, y));
        }
    }

    gameWindow.draw (info.GetObj2());
    gameWindow.draw (info.GetObj1());

    gameWindow.draw (p);
    gameWindow.draw (b);
    gameWindow.display ();
    gameWindow.clear (sf::Color::White);
}




