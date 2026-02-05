#pragma once

#include <vector>
#include "Clickable.hpp"

class InputManager {
    private:
        std::vector<Clickable*> _clickables;
        Clickable* _lastClicked = nullptr;
        sf::Clock _lastClickClock;
        const sf::Time _doubleClickThreshold = sf::milliseconds(300);

    public:
        void registerClickable(Clickable* clickable);
        void handleEvent(const sf::Event& event, const sf::RenderWindow& window);
};