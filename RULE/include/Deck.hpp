//
// Created by pc on 2/10/25.
//

#ifndef DECK_HPP
#define DECK_HPP

#include <algorithm>
#include <vector>
#include <random>
#include "Card.hpp"

class Deck
{
private:
    std::vector<Card> deck;                        // 덱
public:

    Deck();

    Card drawCard();                               // 덱에서 카드 한 장 드로우
    void InitialDeck();                            // 덱을 생성
    void ShuffleDeck();                            // 랜덤으로 덱을 셔플
    void RefillDeck(std::vector<Card>& deathzone); // 덱이 0장일 때 데스존에서 오픈카드를 제외한 나머지 카드들을 섞어서 다시 덱을 생성
    bool isEmpty();                                // 덱이 비어있는지 확인
    int getRemainingDeck();                        // 덱에 남아있는 카드 개수를 반환

    std::vector<Card>& getDeck();

};

#endif //DECK_HPP
