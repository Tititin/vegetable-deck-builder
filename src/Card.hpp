#ifndef CARD_HPP_
#define CARD_HPP_

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <optional>
#include <functional>
#include "Clickable.hpp"
#include "TextureManager.hpp"

class Card : public Clickable
{
public:
    enum class VegetableType {
        ARTICHOKE,
        ONION,
        CORN,
        POTATO,
        EGGPLANT,
        PEAS,
        CARROT,
        BROCCOLI,
        LEEK,
        RHUBARB,
        BELLPEPPER,
        BEETROOT
    };

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
    VegetableType   _type;

public:
    [[deprecated("Use Card(const Card::VegetableType& type, TextureManager& textureManager) instead.")]]
    Card(const std::string& name, const sf::Texture& backTexture, const sf::Texture& frontTexture, const VegetableType& type);

    [[deprecated("Use Card(const Card::VegetableType& type, TextureManager& textureManager) instead.")]]
    Card(const std::string& name, TextureManager& textureManager);
    
    Card(const Card::VegetableType& type, TextureManager& textureManager);
    ~Card();

    // SFML Getters
    sf::Sprite& getSprite() { return _cardSprite; }
    sf::FloatRect getGlobalBounds() const { return _cardSprite.getGlobalBounds(); }
    sf::Vector2f getPosition() const { return _cardSprite.getPosition(); }

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