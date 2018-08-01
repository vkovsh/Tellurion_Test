#include <string>
#include <iostream>
#include "TicTacToe.hpp"

int main()
{
    TicTacToe   playboard;
    std::cout << "Welcome to tic-tac-toe game!" << std::endl;
    playboard.game_loop();
    return 0;
}