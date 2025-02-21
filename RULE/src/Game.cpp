//
// Created by pc on 2/10/25.
//

#include "Game.hpp"

Game::Game() : CurrentPlayerIndex(0), Turn(0), isGameOver(false), ReverseTurn(false) {}

std::vector<Player>& Game::getPlayers()
{
    return players;
}

Deck& Game::getDeck()
{
    return deck;
}

Card& Game::getOpenCard()
{
    return opencard;
}

int Game::getCurrentPlayerIndex() const
{
    return CurrentPlayerIndex;
}

bool Game::isGameOverStatus() const
{
    return isGameOver;
}

void Game::InitialGame(std::string playernames)
{
    deck.InitialDeck();
    deck.ShuffleDeck();

    players.clear();
    std::stringstream ss(playernames);
    std::string name;
    while (std::getline(ss, name, ','))
    {
        players.emplace_back(name);
    }

    for (auto& player : players)
    {
        for (int j = 0; j < 5; ++j)
        {
            player.DrawCard(deck, deathzone);
        }
    }

    opencard = deck.drawCard();
}

void Game::StartGame()
{
    while (!isGameOver)
    {
        DisplayGameState();
        NextTurn();
        isGameOver = CheckWinCondition();
    }
    std::cout << "게임 종료!" << std::endl;
}

void Game::NextTurn()
{
    Player& currentPlayer = players[CurrentPlayerIndex];

    if (currentPlayer.isEliminated())
    {
        CurrentPlayerIndex = (ReverseTurn) ? (CurrentPlayerIndex - 1 + players.size()) % players.size() : (CurrentPlayerIndex + 1) % players.size();
        return;
    }

    currentPlayer.ShowHand();

    if (!currentPlayer.canDropCard(opencard))
    {
        std::cout << "낼 수 있는 카드가 없어 한 장 뽑습니다" << std::endl;
        currentPlayer.DrawCard(deck, deathzone);
    }
    else
    {
        while (true)
        {
            int cardIndex;
            std::cout << "낼 카드를 선택하세요 (1부터 시작) : ";
            std::cin >> cardIndex;
            Card playedCard = currentPlayer.DropCard(cardIndex);
            opencard = playedCard;

            bool hasMoreSameNumber = false;
            for (const auto& card : currentPlayer.getHand())
            {
                if (card.getNumber() == playedCard.getNumber())
                {
                    hasMoreSameNumber = true;
                    break;
                }
            }

            if (hasMoreSameNumber)
            {
                char choice;
                std::cout << "같은 숫자의 카드를 더 내시겠습니까? (y/n) : ";
                std::cin >> choice;
                if (choice == 'y' || 'Y')
                {
                    bool validCardExists = false;
                    for (const auto& card : currentPlayer.getHand())
                    {
                        if (card.getNumber() == playedCard.getNumber())
                        {
                            validCardExists = true;
                            break;
                        }
                    }
                    if (validCardExists) continue;
                }
            }

            HandleCardEffect(currentPlayer, playedCard);
            break;
        }
    }

    CurrentPlayerIndex = (ReverseTurn) ? (CurrentPlayerIndex - 1 + players.size()) % players.size() : (CurrentPlayerIndex + 1) % players.size();
}

bool Game::CheckWinCondition()
{
    for (auto& player : players)
    {
        if (player.getCardCount() == 0)
        {
            std::cout << player.getName() << "가 승리했습니다!" << std::endl;
            return true;
        }
    }
    return false;
}

bool Game::CheckElimination(Player& player)
{
    if (player.getCardCount() >= 10 || player.getJokerCount() == 2)
    {
        player.SetEliminated(true);
        std::cout << player.getName() << "가 탈락했습니다!" << std::endl;
        return true;
    }
    return false;
}

void Game::HandleCardEffect(Player& player, Card playcard)
{
    static int accumulatedAttack = 0;
    int jumpCount = 1;

    if (playcard.getSpecial() == ATTACK)
    {
        accumulatedAttack += playcard.getAttackPower();

        bool hasMoreSameNumber = false;
        for (const auto& card : player.getHand())
        {
            if (card.getNumber() == playcard.getNumber())
            {
                hasMoreSameNumber = true;
                break;
            }
        }

        if (hasMoreSameNumber)
        {
            char choice;
            std::cout << "같은 숫자의 카드를 더 내시겠습니까? (y/n): ";
            std::cin >> choice;
            if (choice == 'y' || choice == 'Y')
            {
                return;
            }
        }

        Player& nextPlayer = players[(CurrentPlayerIndex + 1) % players.size()];
        std::cout << nextPlayer.getName() << "가 공격을 받았습니다! (" << accumulatedAttack << "장)\n";

        if (nextPlayer.HasDefendCard())
        {
            std::cout << nextPlayer.getName() << "가 방어에 성공했습니다!\n";
            opencard = Card(opencard.getNumber(), opencard.getEmblem(), opencard.getColor(), GENERAL);
        }
        else
        {
            nextPlayer.TakePenalty(accumulatedAttack, deck, deathzone);
            std::cout << nextPlayer.getName() << "가 " << accumulatedAttack << "장의 카드를 받습니다.\n";

            if (nextPlayer.getJokerCount() >= 2)
            {
                nextPlayer.SetEliminated(true);
                std::cout << nextPlayer.getName() << "가 조커 2장을 보유하여 탈락했습니다!\n";
            }
        }

        accumulatedAttack = 0;
    }
    else
    {
        accumulatedAttack = 0;

        switch (playcard.getSpecial())
        {
            case TURN_JUMP:
                if (ReverseTurn)
                {
                    CurrentPlayerIndex = CurrentPlayerIndex - 1;
                    if (CurrentPlayerIndex < 0)
                    {
                        CurrentPlayerIndex = CurrentPlayerIndex + players.size();
                    }
                }

                CurrentPlayerIndex = CurrentPlayerIndex + 1;
                std::cout << players[CurrentPlayerIndex].getName() << "의 턴이 건너뛰어졌습니다!\n";
                break;
            case TURN_CHANGE:
                std::cout << "턴 순서가 변경되었습니다!\n";
                ReverseTurn = !ReverseTurn;
                CurrentPlayerIndex = (CurrentPlayerIndex + (ReverseTurn ? -1 : 1) + players.size()) % players.size();
                break;
            case AGAIN:
                std::cout << player.getName() << "의 턴이 한 번 더 진행됩니다!\n";
                return;
            case EMBLEM_CHANGE:
                int newEmblem;
                std::cout << "문양 변경 카드가 사용되었습니다! 새로운 문양을 선택하세요 (0:♠, 1:♦, 2:♣, 3:♥): ";
                std::cin >> newEmblem;
                opencard = Card(opencard.getNumber(), newEmblem, opencard.getColor(), GENERAL);
                break;
            default:
                break;
        }
    }
}

void Game::DisplayGameState()
{
    std::cout << "\n현재 오픈 카드 : ";
    opencard.DisplayCard();
    std::cout << "현재 턴 : " << players[CurrentPlayerIndex].getName() << "\n";

}

