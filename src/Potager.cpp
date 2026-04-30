#include "Potager.hpp"
#include "Card.hpp"

Potager::Potager(const sf::Texture& slotTexture) 
    :   _slotTexture(const_cast<sf::Texture*>(&slotTexture))
{
    _elements = std::vector<SpriteClickable*>(5);
}

Potager::~Potager() {
    for (auto& element : _elements) {
        delete element;
    }
    _elements.clear();
}

void Potager::loadSlots()
{
    sf::Sprite slot(*_slotTexture);
    for (int i = 0; i < 5; i++) {
        slot.setPosition({ static_cast<float>(300 + i * 260), 400.f });
        slot.setScale({CARD_SPRITE_SCALE, CARD_SPRITE_SCALE});
        slot.setColor(sf::Color(255, 255, 255, 64)); // Slightly transparent
        _slots.push_back(slot);
    }
}

void Potager::addCard(SpriteClickable *card, const int &index)
{
    _elements[index] = card;
}

void Potager::draw(sf::RenderTarget &target) const
{
    for (const auto& slot : _slots) {
        target.draw(slot);
    }
    for (const auto& element : _elements) {
        if (element)
        {
            // target.draw(element->getSprite());
            // if (element->isClicked())
            //     target.draw(element->getBorder());
            element->draw(target);
        }
    }
}
