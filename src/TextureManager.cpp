#include "TextureManager.hpp"

TextureManager::TextureManager() { // Temporary constructor loading some textures
    _textures["card_back"] = sf::Texture("assets/images/cards/card_back.png");
    _textures["card_artichoke"] = sf::Texture("assets/images/cards/card_artichoke.png");
    _textures["card_onion"] = sf::Texture("assets/images/cards/card_onion.png");
    _textures["card_corn"] = sf::Texture("assets/images/cards/card_corn.png");
    _textures["card_potato"] = sf::Texture("assets/images/cards/card_potato.png");
    _textures["card_eggplant"] = sf::Texture("assets/images/cards/card_eggplant.png");
    _textures["card_peas"] = sf::Texture("assets/images/cards/card_peas.png");
    _textures["card_carrot"] = sf::Texture("assets/images/cards/card_carrot.png");
    _textures["card_broccoli"] = sf::Texture("assets/images/cards/card_broccoli.png");
    _textures["card_leek"] = sf::Texture("assets/images/cards/card_leek.png");
    _textures["card_rhubarb"] = sf::Texture("assets/images/cards/card_rhubarb.png");
    _textures["card_bellpepper"] = sf::Texture("assets/images/cards/card_bellpepper.png");
    _textures["card_beetroot"] = sf::Texture("assets/images/cards/card_beetroot.png");
    
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