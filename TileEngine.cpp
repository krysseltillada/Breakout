#include "TileEngine.hpp"

TileEngine::TileEngine () :
    tileMap (new std::vector <std::vector <sf::Vector2i> > ()),
    tileSprite (new std::vector <std::vector <sf::Sprite> > ()),
    tileSpriteTexture (new sf::Texture) {}

TileEngine::~TileEngine () { }

TileEngine &TileEngine::setTileMap (const std::string &file) {
    std::vector <sf::Vector2i> temptileMap;
    std::vector <sf::Sprite> tempSprite;

    std::ifstream readFile (file);

    std::string fileBuffer;

    if (!readFile)
        std::cerr << "error loading file " << std::endl;

    readFile >> TileFile;

    if (!tileSpriteTexture->loadFromFile (TileFile))
        std::cerr << "error loading " + TileFile << std::endl;


    while (std::getline (readFile, fileBuffer)) {
        std::istringstream buf (fileBuffer);
        std::string strbuffer;
        while (buf >> strbuffer) {
                char x = strbuffer[0], y = strbuffer[2];

                if (!isdigit (x) || !isdigit (y))
                    temptileMap.push_back (sf::Vector2i (-1, -1));
                else
                    temptileMap.push_back (sf::Vector2i (x - '0', y - '0'));

        }

        tileMap->push_back (temptileMap);
        temptileMap.clear ();
    }

    for (unsigned x = 0; x != tileMap->size (); ++x) {
        for (unsigned y = 0; y != tileMap->at(x).size (); ++y) {

                if (tileMap->at(x).at(y).x != -1 && tileMap->at(x).at(y).y != -1) {
                sf::Sprite tile;

                tile.setTexture (getTexture ());
                tile.setScale (1, 0.50);
                tile.setTextureRect (sf::IntRect (tileMap->at(x).at(y).x * 32,
                                                  tileMap->at(x).at(y).y * 32,
                                                  32,
                                                  32));

                tile.setPosition (y * 32, x * 32);

                tempSprite.push_back (tile);

                ++tileCount;

                }

        }

        tileSprite->push_back (tempSprite);
        tempSprite.clear ();
    }

    return *this;
}

int &TileEngine::getTileCount () {
    return tileCount;
}

sf::Sprite &TileEngine::getSprite (const float &x, const float &y) {
    return tileSprite->at(x).at(y);
}

sf::Texture &TileEngine::getTexture () {
    return *tileSpriteTexture;
}

std::vector <std::vector <sf::Vector2i> > &TileEngine::getTileMap () {
    return *tileMap;
}

std::vector <std::vector <sf::Sprite> > &TileEngine::getSpriteMap () {
    return *tileSprite;
}

TileEngine &TileEngine::clearTileCount () {
    tileCount = 0;
    return *this;
}


