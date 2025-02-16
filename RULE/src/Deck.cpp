//
// Created by pc on 2/10/25.
//

#include "Deck.hpp"
#include <iostream>
#include <algorithm>
#include <random>

Deck::Deck() {}

void Deck::InitialDeck()
{
    cards.clear();
    for (int emblem = SPADE; emblem <= HEART; emblem++)
    {
        for (int number = ACE; number <= JACK; number++)
        {
            int special = NONE;
            int color = BLACK;

            if (number == ACE || number == TWO) special = ATTACK;
            else if (number == THREE) special = DEFEND;
            else if (number == SEVEN) special = CHANGE;
            else if (number == KING || number == JACK || number == QUEEN) special = AGAIN;

            switch (emblem)
            {
                case SPADE:
                    color = BLACK;
                    break;
                case DIAMOND:
                    color = RED;
                    break;
                case CLOVER:
                    color = BLACK;
                    break;
                case HEART:
                    color = RED;
                    break;
            }
            cards.push_back(Card(special, emblem, number, color));
        }
    }
    cards.push_back(Card(ATTACK, 0, JOKER, BLACK)); // 흑백 조커 생성
    cards.push_back(Card(ATTACK, 0, JOKER, RED)); // 컬러 조커 생성

    std::cout << "총 카드 개수 : " << cards.size() << "장" << std::endl;
}

void Deck::ShuffleDeck()
{
    static std::mt19937 g(std::random_device{}());  // 전역적으로 유지
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

void Deck::RefillDeck(std::vector<Card>& deathzone) // deathzone : 오픈 카드를 포함한 플레이어가 낸 카드들이 모인 곳
{
    if (deathzone.empty()) return; // 데스존이 비어있으면 실행 안함

    Card lastcard = deathzone.back();
    deathzone.pop_back();

    cards.insert(cards.end(), deathzone.begin(), deathzone.end());
    deathzone.erase(deathzone.begin(), deathzone.end());
    deathzone.push_back(lastcard);

    ShuffleDeck();
    std::cout << "DEATH ZONE 카드들과 덱을 합쳐 셔플" << std::endl;
}