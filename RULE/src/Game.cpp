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

// void Game::NextTurn()
// {
//     Player& currentPlayer = players[CurrentPlayerIndex];
//
//     if (currentPlayer.isEliminated())
//     {
//         CurrentPlayerIndex = (ReverseTurn) ? (CurrentPlayerIndex - 1 + players.size()) % players.size() : (CurrentPlayerIndex + 1) % players.size();
//         return;
//     }
//
//     currentPlayer.ShowHand();
//
//     if (!currentPlayer.canDropCard(opencard))
//     {
//         std::cout << "낼 수 있는 카드가 없어 한 장 뽑습니다" << std::endl;
//         currentPlayer.DrawCard(deck, deathzone);
//     }
//     else
//     {
//         while (true)
//         {
//             int cardIndex;
//             std::cout << "낼 카드를 선택하세요 (1부터 시작) : ";
//             std::cin >> cardIndex;
//             Card playedCard = currentPlayer.DropCard(cardIndex);
//             opencard = playedCard;
//
//             bool hasMoreSameNumber = false;
//             for (const auto& card : currentPlayer.getHand())
//             {
//                 if (card.getNumber() == playedCard.getNumber())
//                 {
//                     hasMoreSameNumber = true;
//                     break;
//                 }
//             }
//
//             if (hasMoreSameNumber)
//             {
//                 char choice;
//                 std::cout << "같은 숫자의 카드를 더 내시겠습니까? (y/n) : ";
//                 std::cin >> choice;
//                 if (choice == 'y' || 'Y')
//                 {
//                     bool validCardExists = false;
//                     for (const auto& card : currentPlayer.getHand())
//                     {
//                         if (card.getNumber() == playedCard.getNumber())
//                         {
//                             validCardExists = true;
//                             break;
//                         }
//                     }
//                     if (validCardExists) continue;
//                 }
//             }
//
//             HandleCardEffect(currentPlayer, playedCard);
//             break;
//         }
//     }
//
//     CurrentPlayerIndex = (ReverseTurn) ? (CurrentPlayerIndex - 1 + players.size()) % players.size() : (CurrentPlayerIndex + 1) % players.size();
// }

void Game::NextTurn()
{
    Player& currentPlayer = players[CurrentPlayerIndex];

    if (currentPlayer.isEliminated())
    {
        CurrentPlayerIndex = (ReverseTurn)
            ? (CurrentPlayerIndex - 1 + players.size()) % players.size()
            : (CurrentPlayerIndex + 1) % players.size();
        return;
    }

    currentPlayer.ShowHand(true); // ✅ 패 출력 (인덱스 포함)

    // ✅ 낼 카드가 없는 경우 자동으로 드로우 후 턴 종료
    if (!currentPlayer.canDropCard(opencard))
    {
        std::cout << "낼 수 있는 카드가 없어 한 장 뽑습니다.\n";
        currentPlayer.DrawCard(deck, deathzone);

        // 🔥 턴을 종료하고 다음 플레이어로 넘김
        CurrentPlayerIndex = (ReverseTurn)
            ? (CurrentPlayerIndex - 1 + players.size()) % players.size()
            : (CurrentPlayerIndex + 1) % players.size();
        return;
    }

    bool extraTurn = false; // 🔥 턴 한 번 더 여부
    Card lastPlayedCard;

    while (true) // 플레이어가 유효한 행동을 할 때까지 반복
    {
        int cardIndex;
        std::cout << "낼 카드를 선택하세요 (1부터 시작, 0 입력 시 드로우) : ";
        std::cin >> cardIndex;

        if (cardIndex == 0) // ✅ 0을 입력하면 한 장 드로우 후 턴 종료
        {
            std::cout << currentPlayer.getName() << "가 한 장 드로우했습니다.\n";
            currentPlayer.DrawCard(deck, deathzone);

            // 🔥 드로우 후 턴 종료
            CurrentPlayerIndex = (ReverseTurn)
                ? (CurrentPlayerIndex - 1 + players.size()) % players.size()
                : (CurrentPlayerIndex + 1) % players.size();
            return;
        }

        if (cardIndex < 1 || cardIndex > currentPlayer.getCardCount())
        {
            std::cout << "잘못된 선택입니다. 다시 입력하세요.\n";
            continue;
        }

        Card playedCard = currentPlayer.DropCard(cardIndex);

        // ✅ 유효한 카드인지 다시 검사
        if (lastPlayedCard.getNumber() != 0 && playedCard.getNumber() != lastPlayedCard.getNumber())
        {
            std::cout << "잘못된 선택입니다. 다시 입력하세요.\n";
            currentPlayer.getHand().insert(currentPlayer.getHand().begin() + (cardIndex - 1), playedCard); // 다시 패에 넣음
            continue;
        }

        lastPlayedCard = playedCard;
        opencard = playedCard;
        HandleCardEffect(currentPlayer, playedCard);

        // ✅ 패를 다시 출력해서 보기 쉽게 함
        currentPlayer.ShowHand(true);

        // ✅ `"턴 한 번 더"` 카드 확인
        if (playedCard.isAgainCard())
        {
            extraTurn = true;
            std::cout << currentPlayer.getName() << "의 턴이 한 번 더 진행됩니다!\n";
        }

        // ✅ 같은 숫자의 카드 추가 제출 확인
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
            if (choice == 'y' || choice == 'Y')
            {
                continue;  // 같은 숫자 카드를 추가로 낼 경우 루프 유지
            }
        }

        break;
    }

    // 🔥 `"턴 한 번 더"` 효과가 있는 경우, 턴을 유지해야 함.
    if (extraTurn)
    {
        return;
    }

    // 턴 변경이 적용되었는지 확인 후 올바른 플레이어로 이동
    if (!ReverseTurn)
    {
        CurrentPlayerIndex = (CurrentPlayerIndex + 1) % players.size();
    }
    else
    {
        CurrentPlayerIndex = (CurrentPlayerIndex - 1 + players.size()) % players.size();
    }
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

// void Game::HandleCardEffect(Player& player, Card playcard)
// {
//     static int accumulatedAttack = 0;
//     int jumpCount = 1;
//
//     if (playcard.getSpecial() == ATTACK)
//     {
//         accumulatedAttack += playcard.getAttackPower();
//
//         bool hasMoreSameNumber = false;
//         for (const auto& card : player.getHand())
//         {
//             if (card.getNumber() == playcard.getNumber())
//             {
//                 hasMoreSameNumber = true;
//                 break;
//             }
//         }
//
//         if (hasMoreSameNumber)
//         {
//             char choice;
//             std::cout << "같은 숫자의 카드를 더 내시겠습니까? (y/n): ";
//             std::cin >> choice;
//             if (choice == 'y' || choice == 'Y')
//             {
//                 return;
//             }
//         }
//
//         Player& nextPlayer = players[(CurrentPlayerIndex + 1) % players.size()];
//         std::cout << nextPlayer.getName() << "가 공격을 받았습니다! (" << accumulatedAttack << "장)\n";
//
//         if (nextPlayer.HasDefendCard())
//         {
//             std::cout << nextPlayer.getName() << "가 방어에 성공했습니다!\n";
//             opencard = Card(opencard.getNumber(), opencard.getEmblem(), opencard.getColor(), GENERAL);
//         }
//         else
//         {
//             nextPlayer.TakePenalty(accumulatedAttack, deck, deathzone);
//             std::cout << nextPlayer.getName() << "가 " << accumulatedAttack << "장의 카드를 받습니다.\n";
//
//             if (nextPlayer.getJokerCount() >= 2)
//             {
//                 nextPlayer.SetEliminated(true);
//                 std::cout << nextPlayer.getName() << "가 조커 2장을 보유하여 탈락했습니다!\n";
//             }
//         }
//
//         accumulatedAttack = 0;
//     }
//     else
//     {
//         accumulatedAttack = 0;
//
//         switch (playcard.getSpecial())
//         {
//             case TURN_JUMP:
//                 if (ReverseTurn)
//                 {
//                     CurrentPlayerIndex = CurrentPlayerIndex - 1;
//                     if (CurrentPlayerIndex < 0)
//                     {
//                         CurrentPlayerIndex = CurrentPlayerIndex + players.size();
//                     }
//                 }
//
//                 CurrentPlayerIndex = CurrentPlayerIndex + 1;
//                 std::cout << players[CurrentPlayerIndex].getName() << "의 턴이 건너뛰어졌습니다!\n";
//                 break;
//             case TURN_CHANGE:
//                 std::cout << "턴 순서가 변경되었습니다!\n";
//                 ReverseTurn = !ReverseTurn;
//                 CurrentPlayerIndex = (CurrentPlayerIndex + (ReverseTurn ? -1 : 1) + players.size()) % players.size();
//                 break;
//             case AGAIN:
//                 std::cout << player.getName() << "의 턴이 한 번 더 진행됩니다!\n";
//                 return;
//             case EMBLEM_CHANGE:
//                 int newEmblem;
//                 std::cout << "문양 변경 카드가 사용되었습니다! 새로운 문양을 선택하세요 (0:♠, 1:♦, 2:♣, 3:♥): ";
//                 std::cin >> newEmblem;
//                 opencard = Card(opencard.getNumber(), newEmblem, opencard.getColor(), GENERAL);
//                 break;
//             default:
//                 break;
//         }
//     }
// }


void Game::HandleCardEffect(Player& player, Card playcard)
{
    static int accumulatedAttack = 0; // 🔥 공격량 누적 변수
    bool skipTurn = false;
    bool extraTurn = false; // 턴을 한 번 더 하는지 여부

    // 🔥 공격 카드 처리 (누적 공격량 증가)
    if (playcard.isAttackCard())
    {
        accumulatedAttack += playcard.getAttackPower();
        std::cout << player.getName() << "가 공격을 날렸습니다! (현재 누적 공격: " << accumulatedAttack << "장 추가)\n";
        return; // 공격 카드 연속으로 낼 경우 턴을 유지
    }
    else if (playcard.isDefendCard())
    {
        std::cout << player.getName() << "가 방어했습니다! 공격이 초기화됩니다.\n";
        accumulatedAttack = 0;
    }
    else if (playcard.isTurnJumpCard())
    {
        skipTurn = true;
        std::cout << "턴이 건너뛰어졌습니다!\n";
    }
    else if (playcard.isTurnChangeCard())
    {
        ReverseTurn = !ReverseTurn;
        std::cout << "턴 순서가 변경되었습니다!\n";
    }
    else if (playcard.isAgainCard())
    {
        extraTurn = true;
        std::cout << player.getName() << "의 턴이 한 번 더 진행됩니다!\n";
    }
    else if (playcard.isEmblemChangeCard())
    {
        int newEmblem;
        std::cout << "문양 변경 카드가 사용되었습니다! 새로운 문양을 선택하세요 (0:♠, 1:♦, 2:♣, 3:♥): ";
        std::cin >> newEmblem;

        int newColor = (newEmblem == SPADE || newEmblem == CLOVER) ? BLACK : RED;
        opencard = Card(opencard.getNumber(), newEmblem, newColor, GENERAL);
        std::cout << "새로운 문양: " << newEmblem << ", 색깔: " << (newColor == BLACK ? "BLACK" : "RED") << "\n";
    }

    // 🔥 공격이 모두 끝난 후, 최종적으로 공격을 받는 플레이어 처리
    if (accumulatedAttack > 0)
    {
        Player& nextPlayer = players[(CurrentPlayerIndex + 1) % players.size()];

        // 🔥 방어 카드(같은 문양의 3)가 있는지 확인
        bool hasBlockCard = false;
        for (const auto& card : nextPlayer.getHand())
        {
            if (card.getNumber() == THREE && card.getEmblem() == opencard.getEmblem())
            {
                hasBlockCard = true;
                break;
            }
        }

        if (hasBlockCard)
        {
            char choice;
            std::cout << nextPlayer.getName() << "가 같은 문양의 3을 가지고 있습니다! 방어하시겠습니까? (y/n): ";
            std::cin >> choice;

            if (choice == 'y' || choice == 'Y')
            {
                std::cout << nextPlayer.getName() << "가 방어했습니다! 공격이 초기화됩니다.\n";
                accumulatedAttack = 0;
                return;
            }
        }

        int beforePenaltyCards = nextPlayer.getCardCount();
        std::cout << nextPlayer.getName() << "가 총 " << accumulatedAttack << "장의 공격을 받습니다!\n";
        nextPlayer.TakePenalty(accumulatedAttack, deck, deathzone);
        int afterPenaltyCards = nextPlayer.getCardCount();

        // ✅ 디버깅 메시지 추가
        std::cout << nextPlayer.getName() << "의 패에 " << (afterPenaltyCards - beforePenaltyCards) << "장이 추가되었습니다.\n";

        accumulatedAttack = 0;
        return;
    }

    // 턴 점프가 발생하면 다음 플레이어로 건너뜀
    if (skipTurn)
    {
        CurrentPlayerIndex = (ReverseTurn)
            ? (CurrentPlayerIndex - 1 + players.size()) % players.size()
            : (CurrentPlayerIndex + 1) % players.size();
    }

    // 턴 한 번 더 효과 적용
    if (extraTurn)
    {
        return; // 🚀 턴을 유지하고 그대로 진행 (다음 플레이어로 넘어가지 않음)
    }
}




void Game::DisplayGameState()
{
    std::cout << "\n현재 오픈 카드 : ";
    opencard.DisplayCard();
    std::cout << "현재 턴 : " << players[CurrentPlayerIndex].getName() << "\n";

}

