//
// Created by pc on 2/10/25.
//

#ifndef CARD_HPP
#define CARD_HPP

#include "Enum.hpp"
#include "Deck.hpp"
#include "Game.hpp"
#include "Player.hpp"

class Card
{
public:
      int special;                                             // 특수 능력(아니면 0)
      int Card_Emblem;                                         // 카드 문양
      int Card_Number;                                         // 카드 숫자
      int Card_Color;                                          // 카드 색깔
      Card();
      Card(int special, int emblem, int number, int color);    // 생성자

      void Display();                                          // 카드 정보 출력
      bool isSpecial();                                        // 특수 카드 여부 확인
      bool isRightCard(Card& topcard);                         // 낼 수 있는 카드인지 확인
      bool isChangeEmblem();                                   // 문양을 바꿀 수 있는 카드인지 확인
      int ReturnAttackPower();                                 // 공격 카드인지 확인하고 공격 카드이면 몇 장 먹어야하는지 반환
      bool isDefend(Card& topcard);                            // 방어 가능 여부 확인
};

#endif //CARD_HPP
