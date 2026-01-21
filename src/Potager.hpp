#pragma once

// #include <SFML/Graphics.hpp>
#include <vector>
#include "Clickable.hpp"

class Potager {
private:
    std::vector<Clickable*> _elements;
public:
    Potager();
    ~Potager();

    void addElement(Clickable* element);
    
    std::vector<Clickable*>& getElements() { return _elements; }
};