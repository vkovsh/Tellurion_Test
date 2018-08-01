#include "TicTacToe.hpp"

TicTacToe::TicTacToe():_gameover(false)
{
    for (int i = 0; i < _height; ++i)
    {
        for (int j = 0; j < _width; ++j)
        {
            _board[i][j] = '.';
        }
    }
}

TicTacToe::~TicTacToe(){}

void	TicTacToe::game_loop() {
	while (_gameover == false) {
		print_board();
		std::string name;
		std::getline (std::cin,name);
		system("clear");
	}
}

void    TicTacToe::print_board() {
    std::cout << "*******" << std::endl;
    for (int i = 0; i < _height; ++i) {
        std::cout << "* ";
        for (int j = 0; j < _width; ++j) {
            std::cout << _board[i][j];
        }
        std::cout << " *" << std::endl;
    }
    std::cout << "*     *" << std::endl;
    std::cout << "*******" << std::endl;
    std::cout << std::endl;
}