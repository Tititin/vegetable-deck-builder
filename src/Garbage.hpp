#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <map>
#include "Clickable.hpp"
#include "Card.hpp"
#include "TextureManager.hpp"
#include "InputManager.hpp"

class Garbage : public Clickable {
private:
    std::vector<Card*> _cardsInGarbage;

    InputManager* _inputManager;
    TextureManager* _textureManager;

public:
    Garbage(InputManager& inputManager, TextureManager& textureManager);
    ~Garbage();

    void addCard(Card* card);
    const std::vector<Card*>& getCardsInGarbage() const { return _cardsInGarbage; }

    // Callbacks
    void setOnClick(ClickCallback callback);
    void setOnClickRelease(ClickReleaseCallback callback);

    // Event Handling
    void handleEvent(const sf::Event& event, const sf::RenderWindow& window) override;
    void click();

    // Display
    void draw(sf::RenderTarget& target) const { target.draw(_sprite); }
};