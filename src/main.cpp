#include <SFML/Graphics.hpp>
#include "lib/Random.hpp"
#include "Game.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode({1920, 1200}), "SFML works!", sf::Style::None, sf::State::Fullscreen);

    Game game;

    Potager         potager(game.getTextureManager().getTexture("potager_slot"));
    Deck            deck(game.getInputManager(), game.getTextureManager());
    std::uniform_int_distribution<int> distribution(1, 11);

    potager.loadSlots();

    for (int i = 0; i < 5; i++) {
        Card::VegetableType type = static_cast<Card::VegetableType>(distribution(Random::engine()));
        Card* newCard = new Card(type, game.getTextureManager());
        potager.addCard(newCard, i);
        game.getInputManager().registerClickable(newCard);
        newCard->setPosition({ static_cast<float>(350 + i * 250), 400.f });
    }

    game.getInputManager().registerClickable(&deck);

    window.setKeyRepeatEnabled(false); // Disable key repeat to prevent multiple draws from the deck when holding space

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>() or sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
                window.close();

            game.getInputManager().handleEvent(*event, window);
        }

        window.clear();
        potager.draw(window);
        deck.draw(window);
        for (auto* card : deck.getDrawnCards()) {
            window.draw(card->getSprite());
        }
        deck.drawContent(window);
        window.display();
    }
}