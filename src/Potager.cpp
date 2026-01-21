#include "Potager.hpp"

Potager::Potager() {
    _elements = std::vector<Clickable*>();
}

Potager::~Potager() {
    _elements.clear();
}

void Potager::addElement(Clickable* element) {
    _elements.push_back(element);
}