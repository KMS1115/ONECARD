//
// Created by pc on 2/10/25.
//

#ifndef GAME_HPP
#define GAME_HPP

#include "Enum.hpp"
#include "Deck.hpp"
#include "Card.hpp"
#include "Player.hpp"

class Game {
private:
      int VictoryCondition;            // 승리 조건 -> 상대방 카드가 15장 이상이면 승리
      int Turn;                        // 턴 수
      Deck deck;
      Player* currentplayer;           // 현재 플레이어가 누군지 알려줌

public:
      void StartGame();                // 게임 시작(플레이어에게 카드 나눠주고 만약 한 사람에게 조커 두 장이면 다시 나눠주기)
      void OpenCard();                 // 플레이어에게 나눠준 후 오픈 카드 한 장을 랜덤으로 오픈
      bool CheckWinCondition();        // 승리 조건을 만족하는지 검사하는 함수(항상 돌고 있어야 함 -> 쓰레드 파는 것도 괜찮아 보임)
      void FinishGame();               // 승리 조건에 맞으면 게임 종료 -> 승자 출력
      void Play();                     // 조건에 맞는 카드를 내기 -> 같은 숫자인 경우, 여러 개의 카드를 내기 or 같은 문양인 경우, 한 장의 카드 가능
      void NextTurn();                 // 플레이어가 오픈 카드에서 카드를 한 장 먹었거나, 유효한 카드를 냈을 경우 턴을 넘김
      bool isValidCard();              // 플레이어가 낸 카드가 유효한 카드인지를 검사
      bool isSpecialCard();            // 플레이어가 낸 카드가 특수 능력 카드인지를 검사
      void LogMove();                  // 플레이어의 카드 사용 기록을 남김
      bool isShuffleDeck();            // 게임 진행 중 덱을 섞어야 할 타이밍을 정함
};

#endif //GAME_HPP
