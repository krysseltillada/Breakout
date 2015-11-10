#include "GameInfo.hpp"

GameInfo::GameInfo (const std::string &file, const int &lives, const int &score) :
    fontFile (file), playerLives (lives), playerScore (score) { }

GameInfo &GameInfo::setPlayerScore (const int &s) {
    playerScore = s;
    return *this;
}

GameInfo &GameInfo::setPlayerLives (const int &l) {
    playerLives = l;
    return *this;
}

GameInfo &GameInfo::setFontFile (const std::string &f) {
    fontFile = f;
    return *this;
}

GameInfo &GameInfo::setFontSize (const int &s) {
    fontSize = s;
    return *this;
}

GameInfo &GameInfo::increaseScore () {
    playerScore += 1 * multiplier;
    return *this;
}

GameInfo &GameInfo::decreaseScore () {
    playerScore -= 1 * multiplier;
    return *this;
}

GameInfo &GameInfo::generateInfo () {

    scoreFont.loadFromFile(fontFile);
    scoreText.setFont (scoreFont);
    scoreText.setPosition (textPosition.x, textPosition.y);
    scoreText.setCharacterSize (fontSize);
    scoreText.setColor(sf::Color(181, 57, 158));

    lives.setFont (scoreFont);
    lives.setPosition (livePosition.x, livePosition.y);
    lives.setCharacterSize (fontSize);
    lives.setColor(sf::Color(181, 57, 158));

    return *this;
}

GameInfo &GameInfo::Update () {
    std::ostringstream tostr, tostr2;
    std::string buf("lives: ");

    tostr << playerScore;
    tostr2 << playerLives;

    buf += tostr2.str ();

    scoreText.setString(tostr.str());
    lives.setString (buf);
    return *this;
}


sf::Text &GameInfo::GetObj2() {
    return scoreText;
}

sf::Text &GameInfo::GetObj1() {
    return lives;
}

GameInfo &GameInfo::setMultiplier (const int &m) {
    multiplier = m;
    return *this;
}

int &GameInfo::getPlayerLives () {
    return playerLives;
}

int &GameInfo::getPlayerScore () {
    return playerScore;
}

std::string GameInfo::getfontFile () {
    return fontFile;
}


