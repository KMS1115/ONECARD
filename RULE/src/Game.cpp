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
    if (topcard.isAttackCard())  // ✅ 현재 오픈 카드가 공격 카드인지 확인
    {
        std::cout << opponent->name << " is Under Attack!" << std::endl;

        std::vector<int> defendIndexes;  // ✅ 방어할 수 있는 카드의 인덱스를 저장할 벡터

        for (int i = 0; i < opponent->hand.size(); i++)
        {
            if (opponent->hand[i].isDefend(topcard))
            {
                defendIndexes.push_back(i);
            }
        }

        if (!defendIndexes.empty())
        {
            std::cout << "방어할 수 있는 카드가 패에 존재합니다! 만약 방어하려면 1을 입력하세요" << std::endl;
            int choice;
            std::cin >> choice;

            if (choice == 1)
            {
                std::cout << "방어 카드 목록 : " << std::endl;
                for (int i = 0; i < defendIndexes.size(); i++)
                {
                    std::cout << i + 1 << "번 카드 : ";
                    opponent->hand[defendIndexes[i]].Display();
                }

                int index;
                std::cout << "낼 방어 카드의 인덱스를 입력하세요 : ";
                std::cin >> index;

                if (index >= 1 && index <= defendIndexes.size())
                {
                    int realIndex = defendIndexes[index - 1];  // ✅ 실제 인덱스로 변환
                    Card selectedCard = opponent->hand[realIndex];

                    if (selectedCard.isDefend(topcard))
                    {
                        std::cout << opponent->name << "가 방어 카드를 사용하여 공격을 막았습니다!" << std::endl;

                        // ✅ 방어 카드 제출
                        if (!opponent->PlayCard(realIndex, topcard, deathzone))
                        {
                            std::cout << "방어 카드 제출 실패! 다시 시도하세요." << std::endl;
                            return;
                        }

                        // ✅ 방어 성공 후 topcard를 일반 카드로 변경
                        topcard.special = NONE;
                        return;  // ✅ 공격 차단
                    }
                }
                std::cout << "잘못된 선택입니다. 방어할 수 없는 카드를 선택했습니다!" << std::endl;
                return;  // ✅ 잘못된 입력 방지
            }
        }

        // ✅ 방어도 공격도 못하는 경우, 카드 드로우 실행
        AccumulatedAttackPower += topcard.ReturnAttackPower();
        std::cout << opponent->name << " can not defend -> "
                  << AccumulatedAttackPower << " Draw..." << std::endl;

        // 🔥 덱이 부족한 경우, 덱을 리필
        if (deck.isEmpty()) {
            deck.RefillDeck(deathzone);
        }

        // ✅ 공격량만큼 카드 드로우
        for (int idx = 0; idx < AccumulatedAttackPower; idx++)
        {
            if (deck.isEmpty()) {
                std::cout << "덱에 남은 카드가 부족하여 더 이상 드로우할 수 없습니다!" << std::endl;
                break;  // ✅ 덱이 완전히 소진되면 중단
            }
            opponent->DrawCard(deck.cards);  // ✅ 상대방(opponent)이 카드를 뽑도록 변경
        }

        // ✅ 공격 후 턴 자동 변경
        AccumulatedAttackPower = 0;
        topcard.special = NONE;  // ✅ 공격이 끝나면 topcard를 일반 카드로 변경
        NextTurn();  // ✅ 공격을 막지 못하면 턴을 넘김!
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

        if (currentplayer->CanMultipleCard(topcard))
        {
            currentplayer->PlayMultipleCards(topcard, deathzone);
        }

        if (CheckWinCondition())
        {
            break;
        }
        if (!topcard.isAttackCard())
        {
            NextTurn();
        }

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