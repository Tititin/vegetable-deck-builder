#pragma once

#include <vector>
#include "Clickable.hpp"

class InputManager {
    private:
        std::vector<Clickable*> _clickables;

    public:
        void registerClickable(Clickable* clickable);
        void handleEvent(const sf::Event& event, const sf::RenderWindow& window);
};