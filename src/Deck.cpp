#include "Deck.hpp"

Deck::Deck(TextureManager& textureManager)
:   _deckSprite(textureManager.getTexture("card_back")),
    _deckTexture(&textureManager.getTexture("card_back")),
    _deckFont("assets/fonts/CreatoDisplay-Regular.otf"),
    _deckCountText(_deckFont)
{
    _cardCounts[Card::VegetableType::ARTICHOKE] = 10;

    _deckSprite.setPosition({600.f, 800.f});
    _deckSprite.setScale({0.309f, 0.309f}); // Scale to fit the window
}

Deck::~Deck()
{
}

Card::VegetableType Deck::drawCard()
{
    Card::VegetableType drawnType;
    std::uniform_int_distribution<int> distribution(0, 0); // Currently only one type of card available
    drawnType = static_cast<Card::VegetableType>(distribution(Random::engine()));

    while (!_cardCounts.contains(drawnType) or _cardCounts[drawnType] <= 0)
        drawnType = static_cast<Card::VegetableType>(distribution(Random::engine()));

    if (_cardCounts[drawnType] > 0) {
        _cardCounts[drawnType]--;
        return drawnType;
    }

    return (Card::VegetableType::ARTICHOKE);
}

void Deck::drawContent(sf::RenderTarget &target)
{
    std::string countText = "Deck Content:\n";
    for (const auto& [type, count] : _cardCounts) {
        std::string typeName;
        switch (type) {
            case Card::VegetableType::ARTICHOKE:
                typeName = "Artichoke";
                break;
            case Card::VegetableType::ONION:
                typeName = "Onion";
                break;
            case Card::VegetableType::CORN:
                typeName = "Corn";
                break;
            case Card::VegetableType::POTATO:
                typeName = "Potato";
                break;
            case Card::VegetableType::EGGPLANT:
                typeName = "Eggplant";
                break;
            case Card::VegetableType::PEAS:
                typeName = "Peas";
                break;
            case Card::VegetableType::CARROT:
                typeName = "Carrot";
                break;
            case Card::VegetableType::LEEK:
                typeName = "Leek";
                break;
            case Card::VegetableType::BELLPEPPER:
                typeName = "Bellpepper";
                break;
            case Card::VegetableType::BEETROOT:
                typeName = "Beetroot";
                break;
            default:
                typeName = "Unknown";
                break;
        }
        countText += typeName + ": " + std::to_string(count) + "\n";
    }
    _deckCountText.setString(countText);
    _deckCountText.setCharacterSize(48);
    _deckCountText.setPosition({ _deckSprite.getPosition().x - 350.f, _deckSprite.getPosition().y });
    target.draw(_deckCountText);
}
