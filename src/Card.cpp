#include "Card.hpp"

Card::Card(const std::string& name, const sf::Texture& backTexture, const sf::Texture& frontTexture, const VegetableType& type)
    :   _name(name),
        _cardSprite(backTexture),
        _backTexture(const_cast<sf::Texture*>(&backTexture)),
        _frontTexture(const_cast<sf::Texture*>(&frontTexture)),
        _type(type)
{
    _cardSprite.setScale({0.309f, 0.309f}); // Scale to fit the window
    setOnClick([this](Clickable&){
        this->flipCard();
    });
}

Card::Card(const std::string &name, TextureManager& textureManager)
    :   _name(name),
        _cardSprite(textureManager.getTexture("card_back")),
        _backTexture(&textureManager.getTexture("card_back"))
{
        _frontTexture = &textureManager.getTexture("card_" + name);
        _type = VegetableType::ARTICHOKE; // Temporary, should map name to type
        _cardSprite.setScale({0.309f, 0.309f}); // Scale to fit the window
        setOnClick([this](Clickable&){
            this->flipCard();
        });
}

Card::Card(const Card::VegetableType &type, TextureManager &textureManager)
    :   _cardSprite(textureManager.getTexture("card_back")),
        _backTexture(&textureManager.getTexture("card_back")),
        _type(type)
{
    switch (type) {
        case VegetableType::ARTICHOKE:
            _name = "artichoke";
            break;
        case VegetableType::ONION:
            _name = "onion";
            break;
        case VegetableType::CORN:
            _name = "corn";
            break;
        case VegetableType::POTATO:
            _name = "potato";
            break;
        case VegetableType::EGGPLANT:
            _name = "eggplant";
            break;
        case VegetableType::PEAS:
            _name = "peas";
            break;
        case VegetableType::CARROT:
            _name = "carrot";
            break;
        case VegetableType::BROCCOLI:
            _name = "broccoli";
            break;
        case VegetableType::LEEK:
            _name = "leek";
            break;
        case VegetableType::RHUBARB:
            _name = "rhubarb";
            break;
        case VegetableType::BELLPEPPER:
            _name = "bellpepper";
            break;
        case VegetableType::BEETROOT:
            _name = "beetroot";
            break;
        default:
            _name = "artichoke";
            break;
    }
    _frontTexture = &textureManager.getTexture("card_" + _name);
    _cardSprite.setScale({0.309f, 0.309f}); // Scale to fit the window
    setOnClick([this](Clickable&){
        this->flipCard();
    });
}


Card::~Card()
{
}

void Card::setOnClick(ClickCallback callback)
{
    _onClick = std::move(callback);
}

void Card::handleEvent(const sf::Event& event, const sf::RenderWindow& window)
{
    if (const auto mouseButtonPressed = event.getIf<sf::Event::MouseButtonPressed>())
    {
        if (mouseButtonPressed->button == sf::Mouse::Button::Left)
        {
            const auto mousePos = window.mapPixelToCoords({mouseButtonPressed->position});

            if (_cardSprite.getGlobalBounds().contains(mousePos))
            {
                if (_onClick)
                    _onClick(*this);
            }
        }
    }
}

void Card::flipCard()
{
    (this->_currentFace == Face::BACK) ? showFront() : showBack();
}

void Card::showFront()
{
    _cardSprite.setTexture(*_frontTexture);
    _currentFace = Face::FRONT;
}

void Card::showBack()
{
    _cardSprite.setTexture(*_backTexture);
    _currentFace = Face::BACK;
}
