#include "Potager.hpp"

Potager::Potager(const sf::Texture& slotTexture) 
    :   _slotTexture(const_cast<sf::Texture*>(&slotTexture))
{
    _elements = std::vector<Clickable*>();
}

Potager::~Potager() {
    _elements.clear();
}

void Potager::loadSlots()
{
    sf::Sprite slot(*_slotTexture);
    for (int i = 0; i < 5; i++) {
        slot.setPosition({ static_cast<float>(350 + i * 250), 400.f });
        slot.setScale({0.309f, 0.309f});
        slot.setColor(sf::Color(255, 255, 255, 64)); // Slightly transparent
        _slots.push_back(slot);
    }
}

void Potager::addElement(Clickable* element) {
    _elements.push_back(element);
}

void Potager::draw(sf::RenderTarget &target) const
{
    for (const auto& slot : _slots) {
        target.draw(slot);
    }
}
