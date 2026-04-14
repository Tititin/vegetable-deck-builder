#include "FontManager.hpp"

FontManager::FontManager()
{
    _fonts["CreatoDisplay-Regular"] = sf::Font("assets/fonts/CreatoDisplay-Regular.otf");
}

FontManager::~FontManager()
{
}

sf::Font &FontManager::getFont(const std::string &filePath)
{
    if (_fonts.find(filePath) == _fonts.end()) {
        loadFont(filePath);
    }
    return _fonts[filePath];
}

bool FontManager::loadFont(const std::string &filePath)
{
    sf::Font font;
    if (!font.openFromFile(filePath)) {
        return false;
    }
    _fonts[filePath] = font;
    return true;
}
