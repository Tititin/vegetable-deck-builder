#ifndef CARD_HPP_
#define CARD_HPP_

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <optional>

class Card
{
private:
    // SFML Attributes
    sf::Sprite  _cardSprite;

    // Game Attributes
    std::string _name;
public:
    Card(const std::string& name, const sf::Texture& backTexture);
    ~Card();

    sf::Sprite& getSprite() { return _cardSprite; }
};

#endif // CARD_HPP_