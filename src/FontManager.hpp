# pragma once

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <string>

class FontManager {
    private:
        std::unordered_map<std::string, sf::Font> _fonts;
        
    public:
        FontManager();
        ~FontManager();

        sf::Font& getFont(const std::string& filePath);
        bool loadFont(const std::string& filePath);
};