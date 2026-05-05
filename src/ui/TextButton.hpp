#pragma once

#include "BasicButton.hpp"
#include "../FontManager.hpp"

class TextButton : public BasicButton {
    protected:
        sf::Text _buttonText;

        FontManager*    _fontManager;

    public:
        TextButton(const std::string& text, FontManager& fontManager);
        TextButton(const std::string& text, const sf::Font& font);
        ~TextButton() = default;

        virtual void init() override;

        virtual void setPosition(const sf::Vector2f& position) override;

        void setText(const std::string& text) { _buttonText.setString(text); }
        void setTextColor(const sf::Color& color) { _buttonText.setFillColor(color); }
        void setCharacterSize(unsigned int size) { _buttonText.setCharacterSize(size); }

        void draw(sf::RenderTarget& target) const { target.draw(_buttonShape); target.draw(_buttonText); }
};