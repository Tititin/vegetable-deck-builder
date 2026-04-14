#pragma once

#include "BasicButton.hpp"
#include "../FontManager.hpp"

class TextButton : public BasicButton {
    protected:
        sf::Text _buttonText;
        // sf::Font _buttonFont;

        FontManager*    _fontManager;

    public:
        TextButton(const std::string& text, FontManager& fontManager);
        ~TextButton() = default;

        virtual void init() override;

        void draw(sf::RenderTarget& target) const { target.draw(_buttonShape); target.draw(_buttonText); }
};