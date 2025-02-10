//
// Created by pc on 2/10/25.
//

#ifndef DECK_HPP
#define DECK_HPP

#include <vector>
#include "Enum.hpp"
#include "Card.hpp"
#include "Game.hpp"
#include "Player.hpp"

class Deck
{
private:
        std::vector<Card> cards;                                             // 덱에 있는 카드들
public:
        Deck();

        void InitialDeck();                                                  // 게임에 필요한 카드를 생성하고 덱에 추가하는 함수
        void ShuffleDeck();                                                  // 카드 덱을 셔플하는 함수(일정 주기마다? or 플레이어들이 카드를 일정 횟수 이상 먹었을 경우)
        int getRemainingCards();                                             // 현재 덱에 남아있는 카드 개수를 반환
        bool isEmpty();                                                      // 덱이 비어있는지 확인
        void RefillDeck(std::vector<Card>& deathzone);                       // 버린 카드들과 기존의 덱을 섞어서 덱 최종 재생성
};

#endif //DECK_HPP
