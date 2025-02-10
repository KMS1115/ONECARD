//
// Created by pc on 2/10/25.
//

#include "Deck.hpp"
#include <iostream>
#include <algorithm>
#include <random>

void Deck::InitialDeck()
{
    cards.clear();
    for (int emblem = SPADE; emblem = HEART; emblem++)
    {
        for (int number = ACE; number = JACK; number++)
        {
            for (int color = BLACK; color = RED; color++)
            {
                if (emblem == SPADE && number == ACE) cards.push_back(Card(ATTACK, emblem, number, color));
                else if (number == TWO) cards.push_back(Card(ATTACK, emblem, number, color));
                else if (number == THREE) cards.push_back(Card(DEFEND, emblem, number, color));
                else if (number == SEVEN) cards.push_back(Card(CHANGE, emblem, number, color));
                else if (number == ACE) cards.push_back(Card(ATTACK, emblem, number, color));
                else cards.push_back(Card(NONE, emblem, number, color));
            }
        }
    }
    cards.push_back(Card(ATTACK, 0, JOKER, BLACK)); // 흑백 조커 생성
    cards.push_back(Card(ATTACK, 0, JOKER, RED)); // 컬러 조커 생성
}

void Deck::ShuffleDeck()
{
    std::random_device random;
    std::mt19937 g(random());
    std::shuffle(cards.begin(), cards.end(), g);
}

int Deck::getRemainingCards()
{
    return cards.size();
}

bool Deck::isEmpty()
{
    return cards.empty();
}

void Deck::RefillDeck(std::vector<Card>& deathzone)
{
    Card lastcard = deathzone.back();
    deathzone.pop_back();

    cards.insert(cards.end(), deathzone.begin(), deathzone.end());
    deathzone.clear();
    deathzone.push_back(lastcard);
    ShuffleDeck();
    std::cout << "데스존에서 오픈카드 한 장 남기고 덱 셔플" << std::endl;
}