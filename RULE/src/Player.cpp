//
// Created by pc on 2/10/25.
//

#include "Player.hpp"
#include <iostream>
#include <sstream>

Player::Player()
{
    name = "Unknown";
}

Player::Player(std::string pname)
{
    name = pname;
}

void Player::DrawCard(std::vector<Card>& deck)
{
    hand.push_back(deck.back());
    deck.pop_back();
}

bool Player::PlayCard(int index, Card& topcard, std::vector<Card>& deathzone) {
    if (index < 0 || index >= hand.size()) return false;  // 유효한 인덱스 확인

    Card selectedcard = hand[index];

    // ✅ 공격을 받을 때 방어 카드가 제출되었는지 확인
    if (topcard.isAttackCard() && selectedcard.isDefend(topcard)) {
        std::cout << this->name << "가 방어 카드 [" << selectedcard.Card_Number << "] 를 사용하여 공격을 막았습니다!" << std::endl;

        deathzone.push_back(topcard);  // 이전 오픈 카드를 버림
        topcard = selectedcard;  // 오픈 카드 갱신
        hand.erase(hand.begin() + index);  // 플레이어 패에서 제거

        return true;  // 방어 성공
    }

    // ✅ 일반 카드 제출 처리 (기존 로직 유지)
    if (!selectedcard.isRightCard(topcard)) {
        return false;  // 올바른 카드가 아니라면 반환
    }

    deathzone.push_back(topcard);
    topcard = selectedcard;  // 오픈 카드 변경
    hand.erase(hand.begin() + index);  // 플레이어 패에서 제거
    return true;
}


bool Player::CanMultipleCard(Card& topcard)
{
    int count = 0;
    for (const auto& card : hand)
    {
        if (card.Card_Number == topcard.Card_Number)
        {
            count++;
        }
    }
    return count > 1;
}

void Player::PlayMultipleCards(Card& topcard, std::vector<Card>& deathzone)
{
    std::vector<int> remove;
    std::cout << "연속으로 낼 수 있는 카드가 있습니다 선택하십시오 (쉼표로 구분, 예 : 1,3,4)";
    std::string input;
    std::cin >> input;

    std::stringstream ss(input);
    std::string token;

    while (std::getline(ss, token, ','))
    {
        int index = std::stoi(token);
        if (index >= 0 && index <hand.size() && hand[index].Card_Number == topcard.Card_Number)
        {
            remove.push_back(index);
        }
        else
        {
            std::cout << "잘못된 선택입니다. 올바른 카드를 선택하세요" << std::endl;
            return;
        }
    }
    std::sort(remove.begin(), remove.end(), [&](int a, int b) {
        return hand[a].Card_Emblem == topcard.Card_Emblem;
    });

    for (int idx = remove.size() - 1; idx >= 0; idx--) {
        int index = remove[idx];
        deathzone.push_back(topcard);
        topcard = hand[index];
        hand.erase(hand.begin() + index);
    }

    std::cout << "카드를 연속으로 냈습니다! 현재 오픈 카드: ";
    topcard.Display();
}


void Player::ShowHand()
{
    int len = hand.size();
    for (int idx = 0; idx < len; idx++)
    {
        std::cout << idx + 1 << "번 카드 : ";
        hand[idx].Display();
    }
}

bool Player::CanAttack(Card& topcard)
{
    for (const auto &card : hand)
    {
        if ((card.Card_Emblem == topcard.Card_Emblem && card.special == ATTACK) || (card.Card_Number == JOKER && card.Card_Color == topcard.Card_Color))
        {
            return true;
        }
    }
    return false;
}

bool Player::CanDefend(Card& topcard)
{
    for (const auto &card : hand)
    {
        if (card.Card_Number == THREE && topcard.Card_Number == TWO && card.Card_Emblem == topcard.Card_Emblem)
        {
            return true;
        }
    }
    return false;
}

int Player::getCardCount()
{
    int size = hand.size();
    return size;
}

void Player::ReturnIndex(Card& topcard, std::vector<Card>& deck)
{
    bool canPlay = false;
    for (int idx = 0; idx < hand.size(); idx++)
    {
        if (hand[idx].isRightCard(topcard))
        {
            std::cout << "낼 수 있는 카드의 인덱스: " << idx << std::endl;
            canPlay = true;
        }
    }

    if (!canPlay)
    {
        std::cout << "낼 수 있는 카드가 없습니다. 한 장 뽑습니다." << std::endl;
        DrawCard(deck);

        if (hand.back().isRightCard(topcard)) {
            std::cout << "새로 뽑은 카드가 낼 수 있는 카드입니다!" << std::endl;
        }
    }
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
    return hand.empty();
}
