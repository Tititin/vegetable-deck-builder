#include <SFML/Graphics.hpp>
#include "lib/Random.hpp"
#include "Card.hpp"
#include "Potager.hpp"
#include "Deck.hpp"
#include "InputManager.hpp"
#include "TextureManager.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode({1920, 1200}), "SFML works!", sf::Style::None, sf::State::Fullscreen);

    InputManager    inputManager;
    TextureManager  textureManager;
    Potager         potager(textureManager.getTexture("potager_slot"));
    Deck            deck(textureManager);
    std::uniform_int_distribution<int> distribution(1, 9);

    potager.loadSlots();

    for (int i = 0; i < 5; i++) {
        Card::VegetableType type = static_cast<Card::VegetableType>(distribution(Random::engine()));
        Card* newCard = new Card(type, textureManager);
        potager.addCard(newCard, i);
        inputManager.registerClickable(newCard);
        newCard->setPosition({ static_cast<float>(350 + i * 250), 400.f });
    }

    inputManager.registerClickable(&deck);

    // Prototype for drawing cards from the deck
    // Card::VegetableType deckCardType = deck.drawCard();
    // Card deckCard(deckCardType, textureManager);
    // deckCard.setPosition({850.f, 800.f});

    window.setKeyRepeatEnabled(false); // Disable key repeat to prevent multiple draws from the deck when holding space

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>() or sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
                window.close();

            inputManager.handleEvent(*event, window);
        }

        window.clear();
        potager.draw(window);
        deck.draw(window);
        deck.drawContent(window);
        window.display();
    }
}