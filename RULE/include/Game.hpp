//
// Created by pc on 2/10/25.
//

#ifndef GAME_HPP
#define GAME_HPP

#include "Enum.hpp"

class Game {
private:
      int Victory_Condition;      // 승리 조건 -> 상대방 카드가 15장 이상이면 승리
      int Turn;                   // 턴 수

public:
      void Start_Games();         // 게임 시작(플레이어에게 카드 나눠주고 만약 한 사람에게 조커 두 장이면 다시 나눠주기)
      void Finish_Games();        // 승리 조건에 맞으면 게임 종료
      void Play();                // 조건에 맞는 카드를 내기 -> 같은 숫자인 경우, 여러 개의 카드를 내기 or 같은 문양인 경우, 한 장의 카드 가능

};

#endif //GAME_HPP
