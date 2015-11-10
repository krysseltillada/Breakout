#ifndef TILE_ENGINE_HEADER
#define TILE_ENGINE_HEADER

#include <SFML/Graphics.hpp>

#include <vector>
#include <memory>
#include <stdexcept>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cctype>

class TileEngine {
public:
    TileEngine ();
    ~TileEngine ();

    TileEngine &setTileMap (const std::string &);

    sf::Sprite &getSprite (const float &, const float &);

    sf::Texture &getTexture ();

    int &getTileCount ();

    TileEngine &clearTileCount ();


    std::vector <std::vector <sf::Vector2i> > &getTileMap ();
    std::vector <std::vector <sf::Sprite> > &getSpriteMap ();

private:
    std::string TileFile;

    std::unique_ptr <std::vector <std::vector <sf::Vector2i> > > tileMap;
    std::unique_ptr <std::vector <std::vector <sf::Sprite> > > tileSprite;
    std::unique_ptr <sf::Texture> tileSpriteTexture;

    int tileCount = 0;

};
#endif // TILE_ENGINE_HEADER
