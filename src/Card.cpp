#include "Card.hpp"

Card::Card(const Card::VegetableType &type, TextureManager &textureManager)
    :   Clickable(textureManager.getTexture("card_back")),
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
    _sprite.setScale({0.309f, 0.309f}); // Scale to fit the window

    _border.setSize({_sprite.getGlobalBounds().size.x, _sprite.getGlobalBounds().size.y});
    _border.setOutlineColor(sf::Color::Yellow);
    _border.setOutlineThickness(2.f);
    _border.setFillColor(sf::Color::Transparent);
    setOnClick([this](Clickable&){
            click();
    });
    setOnClickRelease([this](Clickable&){
        click();
    });
    setOnDoubleClick([this](Clickable&){
        flipCard();
        this->setClickState(ClickState::NONE);
        _isClicked = false;
    });
    flipCard();
}

Card::~Card()
{
}

void Card::setOnClick(ClickCallback callback)
{
    _onClick = std::move(callback);
}

void Card::setOnClickRelease(ClickReleaseCallback callback)
{
    _onClickRelease = std::move(callback);
}

void Card::setOnDoubleClick(ClickCallback callback)
{
    _onDoubleClick = std::move(callback);
}

void Card::handleEvent(const sf::Event& event, const sf::RenderWindow& window)
{
    if (const auto mouseButtonPressed = event.getIf<sf::Event::MouseButtonPressed>())
    {
        if (mouseButtonPressed->button == sf::Mouse::Button::Left)
        {
            const auto mousePos = window.mapPixelToCoords({mouseButtonPressed->position});

            if (_sprite.getGlobalBounds().contains(mousePos))
            {
                if (_onClick)
                    _onClick(*this);
            }
        }
    }
    if (const auto mouseButtonReleased = event.getIf<sf::Event::MouseButtonReleased>())
    {
        if (mouseButtonReleased->button == sf::Mouse::Button::Left)
        {
            if (_onClickRelease)
                _onClickRelease(*this);
        }
    }
}

void Card::flipCard()
{
    (this->_currentFace == Face::BACK) ? showFront() : showBack();
}

void Card::setClickState(ClickState state)
{
    _clickState = state;
}

void Card::click()
{
    if (this->getClickState() == ClickState::NONE)
    {
        this->setClickState(ClickState::PRESSED);
        _isClicked = true;
        _border.setPosition(_sprite.getPosition());
    }
    else
    {
        this->setClickState(ClickState::NONE);
        _isClicked = false;
    }
}

void Card::showFront()
{
    _sprite.setTexture(*_frontTexture);
    _currentFace = Face::FRONT;
}

void Card::showBack()
{
    _sprite.setTexture(*_backTexture);
    _currentFace = Face::BACK;
}
