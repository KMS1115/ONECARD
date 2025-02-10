//
// Created by pc on 2/10/25.
//

#include "Card.hpp"
#include <iostream>

Card::Card(int special, int emblem, int number, int color)
{
    this->special = special;
    this->Card_Emblem = emblem;
    this->Card_Number = number;
    this->Card_Color = color;
}

void Card::Display()
{
    std::cout << "문양 : " << Card_Emblem << std::endl;
    std::cout << "숫자 : " << Card_Number << std::endl;
    std::cout << "색깔 : " << Card_Color << std::endl;

    if (isSpecial())
    {
        switch (special)
        {
            case ATTACK: std::cout << "공격" << std::endl;
            case DEFEND: std::cout << "방어" << std::endl;
            case CHANGE: std::cout << "문양 변경" << std::endl;
            case AGAIN: std::cout << "턴 추가" << std::endl;
        }
    }
}

bool Card::isSpecial()
{
    if (this->special != 0) return true;
    else return false;
}

bool Card::isRightCard(Card& topcard)
{
    if (this->Card_Emblem == topcard.Card_Emblem) return true;                                                        // 문양 같으면 낼 수 있다
    if (this->Card_Number == topcard.Card_Number) return true;                                                        // 숫자 같으면 낼 수 있다
    if (this->Card_Emblem == JOKER && this->Card_Color == RED && topcard.Card_Color == RED) return true;        // 컬러 조커는 빨간색이면 낼 수 있다
    if (this->Card_Emblem == JOKER && this->Card_Color == BLACK && topcard.Card_Color == BLACK) return true;    // 흑백 조커는 검은색이면 낼 수 있다

    return false;
}

bool Card::isChangeEmblem()
{
    if (this->Card_Number == SEVEN) return true;
}

int Card::ReturnAttackPower()
{
    if (this->special == ATTACK)
    {
        if (this->Card_Number == TWO) return 2;
        else if (this->Card_Number == ACE && this->Card_Emblem == SPADE) return 5;
        else if (this->Card_Number == ACE && this->Card_Emblem != SPADE) return 3;
        else if (this->Card_Number == JOKER && this->Card_Color == RED) return 7;
        else if (this->Card_Number == JOKER && this->Card_Color == BLACK) return 5;
    }
    else return 0;
}

bool Card::isDefend(Card& topcard)
{
    if (this->Card_Number == THREE && topcard.Card_Number == TWO)
    {
        return true;
    }
}