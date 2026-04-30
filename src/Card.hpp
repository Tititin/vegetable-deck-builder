#ifndef CARD_HPP_
#define CARD_HPP_

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <optional>
#include <functional>
#include "SpriteClickable.hpp"
#include "ui/TextBox.hpp"
#include "TextureManager.hpp"

class Card : public SpriteClickable
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
    sf::Texture*    _backTexture;
    sf::Texture*    _frontTexture;
    sf::Font*       _ruleFont;


    // Game Attributes
    std::string     _name;
    Face            _currentFace = Face::BACK;
    VegetableType   _type;

    // UI Attributes
    TextBox         _ruleTextBox;

public:
    Card(const Card::VegetableType& type, TextureManager& textureManager, sf::Font& ruleFont);
    ~Card();

    virtual void init() override;

    // Getters
    const VegetableType& getType() const { return _type; }

    // Sprite and Position
    void updateScale(const float& scale);

    // Callbacks
    void setOnClick(ClickCallback callback);
    void setOnClickRelease(ClickReleaseCallback callback);
    void setOnDoubleClick(ClickCallback callback);

    // Event Handling
    virtual void handleEvent(const sf::Event& event, const sf::RenderWindow& window) override;
    void flipCard();
    void setClickState(ClickState state);
    virtual void click(MouseClickState clickState) override;

    // Display
    void showFront();
    void showBack();
};

#endif // CARD_HPP_