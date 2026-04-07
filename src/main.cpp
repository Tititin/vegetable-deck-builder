#include "lib/Random.hpp"
#include "Game.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode({1920, 1200}), "SFML works!", sf::Style::None, sf::State::Fullscreen);
    sf::CircleShape cursor(3.f);

    Game game;

    game.init();

    window.setKeyRepeatEnabled(false); // Disable key repeat to prevent multiple draws from the deck when holding space
    window.setMouseCursorVisible(false); // Hide the default mouse cursor
    cursor.setFillColor(sf::Color::Red);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>() or sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
                window.close();

            game.handleEvent(*event, window);
            cursor.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));
        }

        game.display(window);
        window.draw(cursor);
        window.display();
    }
}