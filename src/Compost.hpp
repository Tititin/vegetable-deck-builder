#pragma once

#include <vector>
#include "Card.hpp"

class Compost {
public:
    Compost() = default;
    ~Compost() = default;

    static void compostCard(Card* card);
};