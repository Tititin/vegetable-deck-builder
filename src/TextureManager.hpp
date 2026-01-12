#pragma once

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <string>

class TextureManager {
    private:
        std::unordered_map<std::string, sf::Texture> _textures;
    public:
        TextureManager();
        ~TextureManager();

        sf::Texture& getTexture(const std::string& filePath);
        bool loadTexture(const std::string& filePath);
};