//
// Created by pc on 2/10/25.
//

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Enum.hpp"
#include "Deck.hpp"
#include "Card.hpp"
#include "Game.hpp"
#include <string>


class Player
{
private:
        std::string name;                               // 플레이어 이름
        std::vector<Card> hand;                         // 플레이어가 가진 카드 목록
        bool isTurn;                                    // 현재 플레이어 턴 여부
public:
        Player(std::string name);                       // 생성자(이름 설정)
        void DrawCard();                                // 덱에서 카드를 한 장 가져와 플레이어 패에 추가
        bool PlayCard();                                // 현재 패에서 특정 카드를 선택하여 버림 -> 카드를 내면 패에서 제거, 오픈 카드로 보냄
        void ShowCard();                                // 플레이어의 패를 출력
        bool isValidMove();                             // 현재 패에서 오픈 카드와 비교해서 낼 수 있는 카드가 존재하는지 확인
        void RemoveCard();                              // 현재 패에서 낸 카드를 패에서 삭제
        int getCardCount();                             // 현재 패의 카드 개수 반환 -> 승리 조건 검사 시 사용
        bool isBothJoker();                             // 컬러 조커와 흑백 조커 두개 다 있는지 확인 -> 승리 조건 검사 시 사용
        bool isWinner();                                // 패의 카드 개수가 0개인지 확인
};

#endif //PLAYER_HPP
