#include "Card.hpp"

Card::Card(const Card::VegetableType &type, TextureManager &textureManager, sf::Font &ruleFont)
    :   SpriteClickable(textureManager.getTexture("card_back")),
        _backTexture(&textureManager.getTexture("card_back")),
        _ruleFont(&ruleFont),
        _ruleTextBox(*_ruleFont, "<rule placeholder>", 20),
        _ruleButton("i", *_ruleFont),
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
    _sprite.setScale({CARD_SPRITE_SCALE, CARD_SPRITE_SCALE}); // Scale to fit the window

    _border.setSize({_sprite.getGlobalBounds().size.x, _sprite.getGlobalBounds().size.y});
    _border.setOutlineColor(sf::Color::Yellow);
    _border.setOutlineThickness(2.f);
    _border.setFillColor(sf::Color::Transparent);

    _ruleTextBox.setString("Rule for " + _name); // Placeholder rule text, to be replaced with actual rules
    _ruleTextBox.setVisible(true); // Set to true for testing, can be set to false if you want to hide the rule text box by default
    _ruleTextBox.setSize({_sprite.getGlobalBounds().size.x, _sprite.getGlobalBounds().size.y / 3.f});
    _ruleTextBox.setPosition({_sprite.getPosition().x, _sprite.getPosition().y + _sprite.getGlobalBounds().size.y / 3.f * 2.f});

    _ruleButton.setPosition({_sprite.getPosition().x + 5.f, _sprite.getPosition().y + 5.f});
    _ruleButton.setSize({20.f, 20.f});
    _ruleButton.setCharacterSize(16);
    _ruleButton.setFillColor(sf::Color(0, 128, 0, 200));
    _ruleButton.setTextColor(sf::Color::White);

    setOnClick([this](Clickable&){
        click(MouseClickState::PRESSED);
    });
    setOnClickRelease([this](Clickable&){
        click(MouseClickState::RELEASED);
    });
    setOnDoubleClick([this](Clickable&){
        this->setClickState(ClickState::NONE);
        _isClicked = false;
    });
    flipCard();
}

Card::~Card()
{
}

void Card::init()
{
}

void Card::updateScale(const float &scale)
{    
    _sprite.setScale({scale, scale});
    _border.setSize({_sprite.getGlobalBounds().size.x, _sprite.getGlobalBounds().size.y});
    _ruleTextBox.setSize({_sprite.getGlobalBounds().size.x, _sprite.getGlobalBounds().size.y / 3.f});
}

void Card::setPosition(const sf::Vector2f &position)
{
    _sprite.setPosition(position);
    _border.setPosition(position);
    _ruleTextBox.setPosition({position.x, position.y + _sprite.getGlobalBounds().size.y / 3.f * 2.f});
    _ruleButton.setPosition({position.x + 30.f, position.y + 40.f});
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

void Card::click(MouseClickState clickState)
{
    if (clickState == MouseClickState::PRESSED)
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

void Card::draw(sf::RenderTarget &target) const
{
    SpriteClickable::draw(target);
    _ruleButton.draw(target);
    if (_ruleTextBox.isVisible()) {
        _ruleTextBox.draw(target);
    }
}
