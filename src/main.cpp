#include <SFML/Graphics.hpp>
#include "Card.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode({1920, 1080}), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Texture texture2;

    if (!texture.loadFromFile("assets/images/cards/card_back.png")
        || !texture2.loadFromFile("assets/images/cards/card_artichoke.png"))
    {
        return -1; // Error loading texture
    }

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();

            if (event->is<sf::Event::KeyPressed>(sf::Keyboard::Key::A))
                sprite.setTexture(texture);
            if (event->is<sf::Event::KeyPressed>(sf::Keyboard::Key::Z))
                sprite.setTexture(texture2);
                // window.close();
        }

        window.clear();
        window.draw(shape);
        window.draw(sprite);
        window.display();
    }
}