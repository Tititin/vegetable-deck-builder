#pragma once

#include "../Clickable.hpp"
#include "../InputManager.hpp"
#include "../TextureManager.hpp"

class BasicButton : public Clickable {
    protected:

    public:
        BasicButton(TextureManager& textureManager);
        ~BasicButton() = default;

        void init() override;
        void handleEvent(const sf::Event& event, const sf::RenderWindow& window) override;
        void click() override;
};