//
// Created by pc on 2/10/25.
//

#include "Game.hpp"
#include <iostream>
#include <vector>

Game::Game()
{
    player1 = Player();
    player2 = Player();
    currentplayer = nullptr;
    opponent = nullptr;
    VictoryCondition = 15;
    Turn = 0;
}

Game::Game(std::string name1, std::string name2)
{
    player1 = Player(name1);
    player2 = Player(name2);
    currentplayer = &player1;
    opponent = &player2;
    VictoryCondition = 15;
    Turn = 0;
}

void Game::isUnderAttack()
{
    AccumulatedAttackPower = 0;
    if (topcard.isAttackCard())
    {
        std::cout << currentplayer->name << " is Under Attack!" << std::endl;

        if (currentplayer->CanDefend(topcard))
        {
            std::cout << currentplayer->name << " can defend! 공격을 막았습니다!" << std::endl;
            return;
        }
        if (currentplayer->CanAttack(topcard))
        {
            std::cout << "연속 공격할 수 있는 카드가 존재합니다" << std::endl;
            AccumulatedAttackPower += topcard.ReturnAttackPower();
            return;
        }
        AccumulatedAttackPower += topcard.ReturnAttackPower();
        std::cout << currentplayer->name << " can not defend -> " << AccumulatedAttackPower << "Draw..." << std::endl;
        if (deck.isEmpty())
        {
            deck.RefillDeck(deathzone);
        }
        for (int idx = 0; idx < AccumulatedAttackPower; idx++)
        {
            if (deck.isEmpty())
            {
                deck.RefillDeck(deathzone);
            }
            currentplayer->DrawCard(deck.cards);
        }
        AccumulatedAttackPower = 0;
    }
}

void Game::StartGame()
{
    deck.InitialDeck();
    deck.ShuffleDeck();

    for (int idx = 0; idx < 7; idx++)
    {
        player1.DrawCard(deck.cards);
        player2.DrawCard(deck.cards);
    }

    OpenCard();

    std::cout << "게임 시작" << std::endl;

    Play();
}

void Game::OpenCard()
{
    topcard = deck.cards.back();
    deck.cards.pop_back();
    topcard.special = NONE;
    std::cout << "오픈 카드는 : ";
    topcard.Display();
}

bool Game::CheckWinCondition()
{
    return (currentplayer->isBothJoker() || currentplayer->isZero() || currentplayer->getCardCount() >= VictoryCondition);
}

void Game::Play()
{
    bool isFirstTurn = true;
    while (!CheckWinCondition())
    {
        std::cout << currentplayer->name << "의 턴입니다" << std::endl;
        currentplayer->ShowHand();

        int index;
        std::cout << "낼 카드의 번호를 입력하세요 (없으면 -1 입력) : ";
        std::cin >> index;

        if (index == -1)
        {
            currentplayer->DrawCard(deck.cards);
        }
        else
        {
            if (!currentplayer->PlayCard(index, topcard, deathzone))
            {
                std::cout << "잘못된 선택입니다 다시 고르세요" << std::endl;
                std::cout << "오픈 카드: ";
                topcard.Display();
                continue;
            }
        }
        if (topcard.isExtraTurn() && !isFirstTurn)
        {
            std::cout << currentplayer->name << "가 ";
            if (topcard.Card_Number == KING) std::cout << "KING을 내서 추가 턴을 받습니다" << std::endl;
            else if (topcard.Card_Number == QUEEN) std::cout << "QUEEN을 내서 추가 턴을 받습니다" << std::endl;
            else if (topcard.Card_Number == JACK) std::cout << "JACK을 내서 추가 턴을 받습니다" << std::endl;
            continue;
        }

        isFirstTurn = false;

        if (currentplayer->CanMultipleCard(topcard)) {
            currentplayer->PlayMultipleCards(topcard, deathzone);
        }

        if (CheckWinCondition())
        {
            break;
        }
        NextTurn();
        isUnderAttack();
    }
    if (CheckWinCondition())
    {
        FinishGame();
    }
}

void Game::NextTurn()
{
    std::swap(currentplayer, opponent);
    Turn++;
    std::cout << "\n==============================\n";
    std::cout << "턴이 넘어갑니다! 현재 턴: " << Turn << "턴\n";
    std::cout << "오픈 카드: ";
    topcard.Display();  // ✅ 오픈 카드 다시 보여주기
    std::cout << "==============================\n";
}

void Game::FinishGame()
{
    std::cout << "게임 종료!" << std::endl;
    std::cout << "승리자 : " << opponent->name << std::endl;
}