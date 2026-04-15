#include "FontManager.hpp"

FontManager::FontManager()
{
    _fonts["CreatoDisplay-Regular"] = sf::Font("assets/fonts/CreatoDisplay-Regular.otf");
}

FontManager::~FontManager()
{
}

sf::Font& FontManager::getFont(const std::string &key)
{    
    if (_fonts.find(key) == _fonts.end()) {
        throw std::runtime_error("Font not found: " + key);
    }
    return _fonts[key];
}

bool FontManager::loadFont(const std::string &filePath, const std::string &key)
{
    sf::Font font;
    if (!font.openFromFile(filePath)) {
        return false;
    }
    _fonts[key] = font;
    return true;
}
