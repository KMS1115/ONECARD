//
// Created by pc on 2/10/25.
//

#include "Card.hpp"

Card::Card() : Card_Number(0), Card_Emblem(0), Card_Color(0), Card_special(0) {}
Card::Card(int number, int emblem, int color, int special)
    : Card_Number(number), Card_Emblem(emblem), Card_Color(color), Card_special(special) {}

std::string Card::getNumberString() const
{
    switch (Card_Number)
    {
        case ACE: return "A";
        case TWO: return "2";
        case THREE: return "3";
        case FOUR: return "4";
        case FIVE: return "5";
        case SIX: return "6";
        case SEVEN: return "7";
        case EIGHT: return "8";
        case NINE: return "9";
        case TEN: return "10";
        case JACK: return "J";
        case QUEEN: return "Q";
        case KING: return "K";
        case JOKER: return "JOKER";
        default: return std::to_string(Card_Number);
    }
}


void Card::DisplayCard() {
    const char* EmblemSymbols[] = {"♠", "♦", "♣", "♥"};
    const char* ColorNames[] = {"BLACK", "RED"};
    if (getNumberString() == "JOKER")
    {
        std::cout << "[" << getNumberString() << " " << ColorNames[Card_Color] << "]\n";
    }
    else
    {
        std::cout << "[" << getNumberString() << " " << EmblemSymbols[Card_Emblem] << " " << ColorNames[Card_Color] << "]\n";
    }
}

bool Card::isSpecialCard() {
    return Card_special != GENERAL;
}

bool Card::isAttackCard() {
    return Card_special == ATTACK;
}

bool Card::isDefendCard() {
    return Card_special == DEFEND;
}

bool Card::isAgainCard() {
    return Card_special == AGAIN;
}

bool Card::isEmblemChangeCard() {
    return Card_special == EMBLEM_CHANGE;
}

bool Card::isTurnJumpCard() {
    return Card_special == TURN_JUMP;
}

bool Card::isTurnChangeCard() {
    return Card_special == TURN_CHANGE;
}

int Card::getAttackPower() {
    if (Card_Number == TWO) return 2;
    if (Card_Number == ACE) return 3;
    if (Card_Number == JOKER) return 4;
    return 0;
}

int Card::getNumber() const {
    return Card_Number;
}

int Card::getEmblem() const {
    return Card_Emblem;
}

int Card::getColor() const {
    return Card_Color;
}

int Card::getSpecial() const {
    return Card_special;
}

