#include <SFML/Graphics.hpp>
#include "lib/Random.hpp"
#include "Card.hpp"
#include "Potager.hpp"
#include "Deck.hpp"
#include "TextureManager.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode({1920, 1200}), "SFML works!", sf::Style::None, sf::State::Fullscreen);

    TextureManager textureManager;
    Potager potager(textureManager.getTexture("potager_slot"));
    std::uniform_int_distribution<int> distribution(1, 9);

    potager.loadSlots();

    for (int i = 0; i < 5; i++) {
        Card::VegetableType type = static_cast<Card::VegetableType>(distribution(Random::engine()));
        Card* newCard = new Card(type, textureManager);
        potager.addCard(newCard, i);
        newCard->setPosition({ static_cast<float>(350 + i * 250), 400.f });
    }

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>() or sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
                window.close();

            for (int i = 0; i < potager.getElements().size(); i++) {
                potager.getElements()[i]->handleEvent(event.value(), window);
            }
        }

        window.clear();
        potager.draw(window);
        window.display();
    }
}