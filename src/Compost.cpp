#include "Compost.hpp"

void Compost::compostCard(Card *card)
{
    delete card; // This will free the memory allocated for the card
}