#include <SFML/Graphics.hpp>
#include "Card.hpp"
#include "TextureManager.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode({1920, 1200}), "SFML works!", sf::Style::None, sf::State::Fullscreen);

    TextureManager textureManager;
    Card cardPrototype("Artichoke", textureManager.getTexture("card_back"));

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>() or sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
                window.close();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
                cardPrototype.getSprite().setTexture(textureManager.getTexture("card_artichoke"));
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
                cardPrototype.getSprite().setTexture(textureManager.getTexture("card_back"));
        }

        window.clear();
        window.draw(cardPrototype.getSprite());
        window.display();
    }
}