//
// Created by pc on 2/10/25.
//

#ifndef CARD_HPP
#define CARD_HPP

#include "Enum.hpp"
#include <iostream>

class Card
{
private:
    int Card_Number;                        // 특수 능력
    int Card_Emblem;                        // 카드 문양
    int Card_Color;                         // 카드 색깔
    int Card_special;                       // 특수 능력
public:

    Card();
    Card(int number, int emblem, int color, int special);

    void DisplayCard();                     // 카드 정보 출력
    bool isSpecialCard();                   // 특수 카드인지 확인
    bool isAttackCard();                    // 공격 카드인지 확인
    bool isDefendCard();                    // 방어 카드인지 확인
    bool isAgainCard();                     // 턴 추가하는 카드인지 확인
    bool isEmblemChangeCard();              // 문양 바꾸는 카드인지 확인
    bool isTurnJumpCard();                  // 턴 점프하는 카드인지 확인
    bool isTurnChangeCard();                // 턴 바꾸는 카드인지 확인
    int getAttackPower();                   // 공격 카드의 데미지를 반환

    int getNumber() const;
    int getEmblem() const;
    int getColor() const;
    int getSpecial() const;

    std::string getNumberString() const;
};

#endif //CARD_HPP
