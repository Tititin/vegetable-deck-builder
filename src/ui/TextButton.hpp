#pragma once

#include "BasicButton.hpp"

class TextButton : public BasicButton {
    protected:
        sf::Text _buttonText;
        sf::Font _buttonFont;

    public:
        TextButton(const std::string& text);
        ~TextButton() = default;

        virtual void init() override;

        void draw(sf::RenderTarget& target) const { target.draw(_buttonShape); target.draw(_buttonText); }
};