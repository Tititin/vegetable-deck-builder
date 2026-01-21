#include "TextureManager.hpp"

TextureManager::TextureManager() { // Temporary constructor loading some textures
    _textures["card_back"] = sf::Texture("assets/images/cards/card_back.png");
    _textures["card_artichoke"] = sf::Texture("assets/images/cards/card_artichoke.png");
    _textures["card_onion"] = sf::Texture("assets/images/cards/card_onion.png");
    
    _textures["potager_slot"] = sf::Texture("assets/images/potager/potager_slot.png");
}

TextureManager::~TextureManager() {}

bool TextureManager::loadTexture(const std::string& filePath) {
    sf::Texture texture;
    if (!texture.loadFromFile(filePath)) {
        return false;
    }
    _textures[filePath] = texture;
    return true;
}

sf::Texture& TextureManager::getTexture(const std::string& filePath) {
    if (_textures.find(filePath) == _textures.end()) {
        loadTexture(filePath);
    }
    return _textures[filePath];
}