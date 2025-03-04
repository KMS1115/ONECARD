//
// Created by pc on 2/10/25.
//

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <sstream>
#include "Deck.hpp"

class Player
{
private:
    std::string name;                                                       // 플레이어 이름
    std::vector<Card> hand;                                                 // 플레이어 패
    bool IsEliminated;                                                      // 탈락 여부
    int JokerCount;                                                         // 플레이어가 가진 조커 개수
public:

    Player();
    Player(std::string name);

    void DrawCard(Deck& deck, std::vector<Card>& deathzone);                // 덱에서 카드를 한 장 뽑아 플레이어 패에 추가
    void ShowHand(bool showIndex);                                          // 플레이어의 패를 출력
    int getCardCount();                                                     // 현재 패의 카드 개수 반환
    bool canDropCard(Card& openCard);                                       // 낼 수 있는 카드가 있는지 확인
    Card DropCard(int cardindex);                                           // 특정 인덱스 카드를 제출
    void TakePenalty(int count, Deck& deck, std::vector<Card>& deathzone);  // 공격을 받아 막지 못한 경우 카드를 패에 추가
    bool HasDefendCard();                                                   // 패에 방어 카드가 존재하는지 반환
    bool HasSpecialCard();                                                  // 특수 카드 보유 여부(Jack, Queen, King 등)
    void SetEliminated(bool status);                                        // 탈락 상태 변경
    bool isEliminated();                                                    // 탈락 여부 반환

    std::string getName() const;
    std::vector<Card>& getHand();
    int getJokerCount() const;
};

#endif //PLAYER_HPP
