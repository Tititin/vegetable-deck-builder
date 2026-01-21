#ifndef CARD_HPP_
#define CARD_HPP_

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <optional>
#include <functional>
#include "Clickable.hpp"

class Card : public Clickable
{
private:
    // Enums
    enum class Face {
        FRONT,
        BACK
    };

    // SFML Attributes
    sf::Sprite      _cardSprite;
    sf::Texture*    _backTexture;
    sf::Texture*    _frontTexture;

    // Callbacks
    ClickCallback   _onClick;

    // Game Attributes
    std::string     _name;
    Face            _currentFace = Face::BACK;

public:
    Card(const std::string& name, const sf::Texture& backTexture, const sf::Texture& frontTexture);
    ~Card();

    // SFML Getters
    sf::Sprite& getSprite() { return _cardSprite; }
    sf::FloatRect getGlobalBounds() const { return _cardSprite.getGlobalBounds(); }

    // SFML Setters
    void    setPosition(const sf::Vector2f& position) { _cardSprite.setPosition(position); }

    // Callbacks
    void setOnClick(ClickCallback callback);

    // Event Handling
    void handleEvent(const sf::Event& event, const sf::RenderWindow& window);
    void flipCard();

    // Display
    void showFront();
    void showBack();
};

#endif // CARD_HPP_