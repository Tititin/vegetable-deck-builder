#include "Deck.hpp"

Deck::Deck(InputManager& inputManager, TextureManager& textureManager, FontManager& fontManager)
:   SpriteClickable(textureManager.getTexture("card_back")),
    _inputManager(&inputManager),
    _textureManager(&textureManager),
    _fontManager(&fontManager),
    _deckTexture(&textureManager.getTexture("card_back")),
    _deckCountText(fontManager.getFont("CreatoDisplay-Regular"))
{
    _sprite.setPosition({50.f, 800.f});
    _sprite.setScale({CARD_SPRITE_SCALE, CARD_SPRITE_SCALE}); // Scale to fit the window
    setOnClick([this](Clickable&){
            this->setClickState(ClickState::PRESSED);
            this->setState(DeckState::PICKINGCARDS);
    });
    setOnClickRelease([this](Clickable&){
            this->setClickState(ClickState::NONE);
    });
}

Deck::~Deck()
{
    for (auto* card : _cards) {
        delete card;
    }
    _cards.clear();
}

void Deck::init()
{
}

void Deck::addCard(Card *card)
{
    _cards.push_back(std::move(card));
}

Card *Deck::drawRandomCard()
{
    std::uniform_int_distribution<int> distribution(0, _cards.size() - 1);

    if (!_cards.empty()) {
        int randomIndex = distribution(Random::engine());
        Card* drawnCard = _cards[randomIndex];
        _cards.erase(_cards.begin() + randomIndex); // Remove the drawn card from the deck
        return drawnCard;
    }
    return nullptr;
}

void Deck::setOnClick(ClickCallback callback)
{
    _onClick = std::move(callback);
}

void Deck::setOnClickRelease(ClickReleaseCallback callback)
{
    _onClickRelease = std::move(callback);
}

void Deck::handleEvent(const sf::Event &event, const sf::RenderWindow &window)
{
}

void Deck::click(MouseClickState clickState)
{
}

void Deck::draw(sf::RenderTarget &target)
{
    if (_cards.empty()) {
        _sprite.setTexture(_textureManager->getTexture("potager_slot"));
    }
    else
        _sprite.setTexture(*_deckTexture);
    target.draw(_sprite);
}

void Deck::drawContent(sf::RenderTarget &target)
{
    std::map<Card::VegetableType, int> cardCounts;
    for (const auto* card : _cards) {
        cardCounts[card->getType()]++;
    }
    std::string countText = "Deck Content:\n";
    for (const auto& [type, count] : cardCounts) {
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
            case Card::VegetableType::BROCCOLI:
                typeName = "Broccoli";
                break;
            case Card::VegetableType::LEEK:
                typeName = "Leek";
                break;
            case Card::VegetableType::RHUBARB:
                typeName = "Rhubarb";
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
    _deckCountText.setPosition({50.f, 50.f});
    target.draw(_deckCountText);
}
