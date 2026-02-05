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
        ARTICHOKE = 0,
        ONION,
        CORN,
        POTATO,
        EGGPLANT,
        PEAS,
        CARROT,
        // BROCCOLI,
        LEEK,
        // RHUBARB,
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
    sf::Texture*    _backTexture;
    sf::Texture*    _frontTexture;


    // Game Attributes
    std::string     _name;
    Face            _currentFace = Face::BACK;
    VegetableType   _type;

public:
    Card(const Card::VegetableType& type, TextureManager& textureManager);
    ~Card();

    // Callbacks
    void setOnClick(ClickCallback callback);
    void setOnClickRelease(ClickReleaseCallback callback);

    // Event Handling
    void handleEvent(const sf::Event& event, const sf::RenderWindow& window);
    void flipCard();
    void setClickState(ClickState state);

    // Display
    void showFront();
    void showBack();
};

#endif // CARD_HPP_