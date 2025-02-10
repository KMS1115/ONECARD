//
// Created by pc on 2/10/25.
//

#ifndef CARD_HPP
#define CARD_HPP

#include "Enum.hpp"

class Card {
private:
      int Number;                 // 가지고 있는 카드 개수
      int Penalty_Card;           // 공격 카드로 먹을 카드 개수
      int Card_Emblem;            // 카드 문양
      int Card_Number;            // 카드 숫자
      int Card_Color;             // 카드 색깔
public:
      void Attack();              // 공격
      void Defend();              // 방어(3번)
      void Change();              // 문양 바꾸기(7번)
      void Again();               // K 카드인 경우 한 번 더 내기 -> 쓰레드를 돌려서 항상 체크하거나 or if문으로 구현하기
};

#endif //CARD_HPP
