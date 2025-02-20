//
// Created by pc on 2/10/25.
//

#ifndef GAME_HPP
#define GAME_HPP

#include "Player.hpp"

class Game
{
private:
    Card opencard;                                          // 오픈 카드
    std::vector<Card> deathzone;                            // 데스존(오픈 카드를 포함하는 플레이어가 버린 카드들의 배열)
    Deck deck;                                              // 덱
    std::vector<Player> players;                            // 게임에 참여하는 플레이어 목록

    int CurrentPlayerIndex;                                 // 현재 턴인 플레이어 추적하는 인덱스
    int VictoryCardCount;                                   // 승리 조건 : 상대방 카드가 x장 이상이면 승리
    int Turn;                                               // 턴 수
    bool isGameOver;                                        // 게임 종료 여부 추가
    bool ReverseTurn;                                       // true면 턴 순서를 반대로 진행

public:

    Game();

    void InitialGame(int numplayers);                       // 게임 초기화(플레이어 생성, 카드 배분)
    void StartGame();                                       // 게임 시작
    void NextTurn();                                        // 턴 진행
    bool CheckWinCondition();                               // 승리 조건 체크
    bool CheckElimination(Player &player);                  // 플레이어 탈락 체크
    void HandleCardEffect(Player &player, Card playcard);   // 특수 카드 효과 처리
    void DisplayGameState();                                // 현재 게임 상태 출력
};

#endif //GAME_HPP
