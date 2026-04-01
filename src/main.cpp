#include "lib/Random.hpp"
#include "Game.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode({1920, 1200}), "SFML works!", sf::Style::None, sf::State::Fullscreen);
    sf::CircleShape cursor(3.f);

    Game game;

    std::uniform_int_distribution<int> distribution(1, 11);

    game.init();

    for (int i = 0; i < 5; i++) { // Will be done by CardManager in v0.5.0
        Card::VegetableType type = static_cast<Card::VegetableType>(distribution(Random::engine()));
        Card* newCard = new Card(type, game.getTextureManager());
        game.getPotager().addCard(newCard, i);
        game.getInputManager().registerClickable(newCard);
        newCard->setPosition({ static_cast<float>(350 + i * 250), 400.f });
    }

    window.setKeyRepeatEnabled(false); // Disable key repeat to prevent multiple draws from the deck when holding space
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