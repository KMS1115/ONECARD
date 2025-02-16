#include "main.hpp"
#include <iostream>

int main()
{
    std::string player1_name, player2_name;

    std::cout << "플레이어 1의 이름을 입력하세요 : ";
    std::cin >> player1_name;
    std::cout << "플레이어 2의 이름을 입력하세요 : ";
    std::cin >> player2_name;

    Game game(player1_name, player2_name);
    game.StartGame();

    return 0;
}