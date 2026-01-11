#include <SFML/Graphics.hpp>
#include "Card.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode({1920, 1080}), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    sf::Texture texture("assets/images/cards/card_back.png");
    sf::Texture texture2("assets/images/cards/card_artichoke.png");
    sf::Sprite sprite(texture);

    // if (!texture.loadFromFile("assets/images/cards/card_back.png")
    //     || !texture2.loadFromFile("assets/images/cards/card_artichoke.png"))
    // {
    //     return -1; // Error loading texture
    // }

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();

            if (const auto keyEvent = event->get<sf::Event::KeyPressed>())
            {
                if (keyEvent->code == sf::Keyboard::Space)
                    sprite.setTexture(texture2);
                if (keyEvent->code == sf::Keyboard::A)
                    sprite.setTexture(texture);
            }
                // window.close();
        }

        window.clear();
        window.draw(shape);
        window.draw(sprite);
        window.display();
    }
}