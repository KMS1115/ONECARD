#include "main.hpp"

int main()
{
    std::string playerNames;
    std::cout << "플레이어 이름을 쉼표로 구분하여 입력하세요 : ";
    std::getline(std::cin, playerNames);

    Game game;
    game.InitialGame(playerNames);
    std::cout << "\n게임을 시작합니다!\n";
    game.StartGame();
    std::cout << "게임이 종료되었습니다.\n";
    return 0;
}