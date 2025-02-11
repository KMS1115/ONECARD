//
// Created by pc on 2/10/25.
//

#include "Player.hpp"
#include <iostream>

Player::Player()
{
    name = "Unknown";
}

Player::Player(std::string pname)
{
    name = pname;
}

void Player::DrawCard(Card& topcard)
{
    hand.push_back(topcard);
}

bool Player::PlayCard(int index, Card& topcard, std::vector<Card>& deathzone) {
    std::cin >> index;
    Card selectedcard = hand[index];

    if (selectedcard.isRightCard(topcard))
    {
        deathzone.push_back(topcard);
        topcard = selectedcard;
    }

    hand.erase(hand.begin() + index);
    selectedcard.Display();
    return true;
}

void Player::ShowHand()
{
    int len = hand.size();
    for (int idx = 0; idx < len; idx++)
    {
        hand[idx].Display();
    }
}

int Player::getCardCount()
{
    int size = hand.size();
    return size;
}

void Player::ReturnIndex(Card& topcard, std::vector<Card>& deathzone)
{
    std::vector<int> ans;
    int size = hand.size();
    for (int idx = 0; idx < size; idx++)
    {
        Card selectedcard = hand[idx];
        if (selectedcard.isRightCard(topcard))
        {
            ans.push_back(idx);
        }
    }
    int len = ans.size();
    if (len == 0)
    {
        DrawCard(topcard);
    }
    else
    {
        std::cout << "낼 수 있는 카드의 인덱스는 : ";
        for (int idx = 0; idx < len; idx++)
    {
        std::cout << ans[idx] << " ";
    }
    }
    std::cout << std::endl;
}

bool Player::isBothJoker()
{
    int size = hand.size();
    int count = 0;
    for (int idx = 0; idx < size; idx++)
    {
        Card selectedcard = hand[idx];
        if (selectedcard.Card_Number == JOKER) count++;
    }
    if (count == 2) return true;
    else return false;
}

bool Player::isZero()
{
    if (hand.size() == 0) return true;
}
