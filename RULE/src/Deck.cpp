//
// Created by pc on 2/10/25.
//

#include "Deck.hpp"

Deck::Deck()
{
    InitialDeck();
    ShuffleDeck();
}

std::vector<Card>& Deck::getDeck()
{
    return deck;
}

void Deck::InitialDeck()
{
    deck.clear();
    for (int number = ACE; number < JOKER; ++number)
    {
        for (int emblem = SPADE; emblem <= HEART; ++emblem)
        {
            int color = (emblem == SPADE || emblem == CLOVER) ? BLACK : RED;
            int special = GENERAL;
            if (number == TWO || number == ACE) special = ATTACK;
            if (number == SEVEN) special = EMBLEM_CHANGE;
            if (number == JACK) special = TURN_JUMP;
            if (number == QUEEN) special = TURN_CHANGE;
            if (number == KING) special = AGAIN;

            Card newcard(number, emblem, color, special);
            deck.push_back(newcard);
        }
    }

    Card blackjoker(JOKER, -1, BLACK, ATTACK);
    Card colorjoker(JOKER, -1, RED, ATTACK);

    deck.push_back(blackjoker);
    deck.push_back(colorjoker);
}

void Deck::ShuffleDeck() {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(deck.begin(), deck.end(), g);
}

void Deck::RefillDeck(std::vector<Card>& deathzone)
{
    if (deathzone.size() <= 1) return;

    Card opencard = deathzone.back();
    deathzone.pop_back();

    deck = deathzone;
    deathzone.clear();
    deathzone.push_back(opencard);

    ShuffleDeck();
}

bool Deck::isEmpty() {
    return deck.empty();
}

int Deck::getRemainingDeck() {
    return deck.size();
}

Card Deck::drawCard()
{
    if (!deck.empty())
    {
        Card drawnCard = deck.back();
        deck.pop_back();
        return drawnCard;
    }
    return Card();
}