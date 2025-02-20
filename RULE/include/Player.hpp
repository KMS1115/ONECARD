//
// Created by pc on 2/10/25.
//

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Deck.hpp"
#include "Card.hpp"
#include <string>


class Player
{
public:
        std::string name;                                                       // 플레이어 이름
        std::vector<Card> hand;                                                 // 플레이어가 가진 카드 목록
        bool isTurn;                                                            // 현재 플레이어 턴 여부
        Player();
        Player(std::string pname);                                              // 생성자(이름 설정)
        void DrawCard(std::vector<Card>& deck);                                 // 덱에서 카드를 한 장 가져와 플레이어 패에 추가
        bool PlayCard(int index, Card& topcard, std::vector<Card>& deathzone);  // 현재 패에서 특정 카드를 선택하여 버림 -> 카드를 내면 패에서 제거, 오픈 카드로 보냄
        void ShowHand();                                                        // 플레이어의 패를 출력
        void ReturnIndex(Card& topcard, std::vector<Card>& deathzone);          // 현재 패에서 오픈 카드와 비교해서 낼 수 있는 카드가 존재하는지 확인
        int getCardCount();                                                     // 현재 패의 카드 개수 반환 -> 승리 조건 검사 시 사용
        bool isBothJoker();                                                     // 컬러 조커와 흑백 조커 두개 다 있는지 확인 -> 승리 조건 검사 시 사용
        bool isZero();                                                          // 패의 카드 개수가 0개인지 확인
        bool CanDefend(Card& topcard);                                          // 공격을 방어할 수 있는 상황인지 파악
        bool CanAttack(Card& topcard);                                          // 공격 받는 상황에서 자신이 낼 수 있는 공격 카드가 있는지 확인
        bool CanMultipleCard(Card& topcard);                                    // 패에 같은 숫자의 카드가 2장 이상 있는 경우, true 반환
        void PlayMultipleCards(Card& topcard, std::vector<Card>& deathzone);    // 패에 같은 숫자의 카드가 2장 이상 있는 경우, 원하는 만큼 낼 수 있게함
};

#endif //PLAYER_HPP
