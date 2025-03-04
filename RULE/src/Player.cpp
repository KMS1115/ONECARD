//
// Created by pc on 2/10/25.
//

#include "Player.hpp"

Player::Player() : name(""), IsEliminated(false), JokerCount(0) {}

Player::Player(std::string name) : name(name), IsEliminated(false), JokerCount(0) {}

std::string Player::getName() const
{
    return name;
}

std::vector<Card>& Player::getHand()
{
    return hand;
}

int Player::getJokerCount() const
{
    return JokerCount;
}

void Player::DrawCard(Deck& deck, std::vector<Card>& deathzone)
{
    if (deck.isEmpty())
    {
        deck.RefillDeck(deathzone);
    }
    hand.push_back(deck.drawCard());
}

void Player::ShowHand(bool showIndex)
{
    std::cout << name << "의 패: \n";
    for (size_t i = 0; i < hand.size(); i++)
    {
        if (showIndex)
        {
            std::cout << (i + 1) << ". ";
        }
        hand[i].DisplayCard();
    }
    std::cout << std::endl;
}


int Player::getCardCount()
{
    return hand.size();
}

bool Player::canDropCard(Card& openCard)
{
    for (const auto& card : hand)
    {
        if (openCard.getNumber() == JOKER && card.getColor() == openCard.getColor())
        {
            return true;
        }
        if (card.getNumber() == JOKER && card.getColor() == openCard.getColor())
        {
            return true;
        }
        if (card.getEmblem() == openCard.getEmblem() || card.getNumber() == openCard.getNumber())
        {
            return true;
        }
    }
    return false;
}

Card Player::DropCard(int cardIndex)
{
    cardIndex -= 1;
    Card droppedCard = hand[cardIndex];
    hand.erase(hand.begin() + cardIndex);
    return droppedCard;
}

void Player::TakePenalty(int count, Deck& deck, std::vector<Card>& deathzone)
{
    for (int i = 0; i < count; i++)
    {
        DrawCard(deck, deathzone);
    }
}

bool Player::HasDefendCard()
{
    for (auto& card : hand)
    {
        if (card.isDefendCard()) return true;
    }
    return false;
}

bool Player::HasSpecialCard()
{
    for (auto& card : hand)
    {
        if (card.isSpecialCard()) return true;
    }
    return false;
}

void Player::SetEliminated(bool status)
{
    IsEliminated = status;
}

bool Player::isEliminated()
{
    return IsEliminated;
}