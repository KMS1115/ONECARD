//
// Created by pc on 2/10/25.
//

#include "Card.hpp"
#include <iostream>

Card::Card() : special(0), Card_Emblem(0), Card_Number(0), Card_Color(0){}

Card::Card(int special, int emblem, int number, int color)
{
    this->special = special;
    this->Card_Emblem = emblem;
    this->Card_Number = number;
    this->Card_Color = color;
}

void Card::Display()
{
    std::string rankStr, emblemStr, colorStr, specialStr;

    switch (Card_Emblem)
    {
        case 0: emblemStr = "♠ "; break;
        case 1: emblemStr = "♦ "; break;
        case 2: emblemStr = "♣ "; break;
        case 3: emblemStr = "♥ "; break;
    }

    switch (Card_Number)
    {
        case 1: rankStr = "A"; break;
        case 11: rankStr = "K"; break;
        case 12: rankStr = "Q"; break;
        case 13: rankStr = "J"; break;
        case 14: rankStr = "JOKER"; break;
        default: rankStr = std::to_string(Card_Number); break;
    }

    switch (Card_Color)
    {
        case BLACK: colorStr = "검정"; break;
        case RED: colorStr = "빨강"; break;
    }

    // 특수 기능 변환
    if (isSpecial()) {
        switch (special) {
            case ATTACK: specialStr = " (공격 카드)"; break;
            case DEFEND: specialStr = " (방어 카드)"; break;
            case CHANGE: specialStr = " (문양 변경)"; break;
            case AGAIN: specialStr = " (턴 추가)"; break;
        }
    }

    std::cout << "[" << emblemStr << " " << rankStr << " " << colorStr << "]" << specialStr << std::endl;
}


bool Card::isSpecial()
{
    if (this->special != 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Card::isRightCard(Card& topcard)
{

    if (this->Card_Emblem == topcard.Card_Emblem) return true;                                                        // 문양 같으면 낼 수 있다
    if (this->Card_Number == topcard.Card_Number) return true;                                                        // 숫자 같으면 낼 수 있다
    if (this->Card_Number == JOKER && this->Card_Color == RED && topcard.Card_Color == RED) return true;              // 컬러 조커는 빨간색이면 낼 수 있다
    if (this->Card_Number == JOKER && this->Card_Color == BLACK && topcard.Card_Color == BLACK) return true;          // 흑백 조커는 검은색이면 낼 수 있다

    return false;
}

bool Card::isChangeEmblem()
{
    if (this->Card_Number == SEVEN) return true;
    return false;
}

bool Card::isAttackCard()
{
    if (this->special == ATTACK)
    {
        return true;
    }
    return false;
}

int Card::ReturnAttackPower()
{
    if (this->special == ATTACK)
    {
        switch (this->Card_Number)
        {
            case TWO:
                return 2;
            case ACE:
                return (this->Card_Emblem == SPADE) ? 5 : 3;
            case JOKER:
                return (this->Card_Color == RED) ? 7 : 5;
            default:
                return 0;
        }
    }
    return 0;
}


bool Card::isDefend(Card& topcard)
{
    if (this->Card_Number == THREE && topcard.Card_Number == TWO)
    {
        return true;
    }
    return false;
}

bool Card::isExtraTurn()
{
    if (this->special == AGAIN)
    {
        switch (this->Card_Number)
        {
            case KING:
            case QUEEN:
            case JACK:
                return true;
            default:
                return false;
        }
    }
}
