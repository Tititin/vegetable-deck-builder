#include <SFML/Graphics.hpp>
#include "Card.hpp"
#include "Potager.hpp"
#include "TextureManager.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode({1920, 1200}), "SFML works!", sf::Style::None, sf::State::Fullscreen);

    TextureManager textureManager;
    Card cardPrototype("Artichoke", textureManager.getTexture("card_back"), textureManager.getTexture("card_artichoke"), Card::VegetableType::ARTICHOKE);
    Card cardOnion("Onion", textureManager.getTexture("card_back"), textureManager.getTexture("card_onion"), Card::VegetableType::ONION);

    Potager potager(textureManager.getTexture("potager_slot"));

    cardPrototype.setPosition({350.f, 400.f});
    cardOnion.setPosition({600.f, 400.f});
    potager.loadSlots();

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>() or sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
                window.close();

            cardPrototype.handleEvent(event.value(), window);
            cardOnion.handleEvent(event.value(), window);
        }

        window.clear();
        potager.draw(window);
        window.draw(cardPrototype.getSprite());
        window.draw(cardOnion.getSprite());
        window.display();
    }
}