#include "TicTacToe.hpp"

TicTacToe::TicTacToe() :_gameover(false) {
    std::string input;
    std::regex digit("[1-2]");
    std::cout << "Choose gamemode:" << std::endl;
    while (true) {
        std::cout << "Type 1 for Human-Human and 2 for Human-Computer: " << std::endl;
        getline(std::cin, input);
        if (std::regex_match(input, digit)) {
			if (input == "1") {
				_player1 = new HumanPlayer('X');
				_player2 = new HumanPlayer('O');
			}
			else {
				while (true) {
					std::cout << "Type 1 for Human-Computer and 2 for Computer-Human: " << std::endl;
					getline(std::cin, input);
					if (std::regex_match(input, digit)) {
						if (input == "1") {
							_player1 = new HumanPlayer('X');
							_player2 = new ArtificialPlayer('O');
						}
						else {
							_player1 = new ArtificialPlayer('X');
							_player2 = new HumanPlayer('O');
						}
						break ;
					}
					else {
						std::cout << "Invalid input!" << std::endl;
					}
				}
			}
			break ;
		}
		else
 			std::cout << "Invalid input!" << std::endl;
    }
    for (int i = 0; i < _height; ++i) {
        for (int j = 0; j < _width; ++j) {
            _board[i][j] = '.';
        }
    }
}

TicTacToe::~TicTacToe(){}

bool    TicTacToe::checkWinConditions(char marker) {
	int	sum;
	for (int i = 0; i < _height; ++i) {
		sum = 0;
		for (int j = 0; j < _width; ++j) {
			if (_board[i][j] != marker) {
				break ;
			}
			else {
				++sum;
			}
		}
		if (sum == 3) {
			return true;
		}
	}
	for (int i = 0; i < _width; ++i) {
		sum = 0;
		for (int j = 0; j < _height; ++j) {
			if (_board[j][i] != marker) {
				break ;
			}
			else {
				sum++;
			}
		}
		if (sum == 3) {
			return true;
		}
	}
	if (_board[1][1] == marker) {
		if (_board[0][0] == marker && _board[2][2] == marker) {
			return true;
		}
		else if (_board[0][2] == marker && _board[2][0] == marker) {
			return true;
		}
	}
	return false;
}

int	TicTacToe::getWidth() {
	return _width;
}

int	TicTacToe::getHeight() {
	return _height;
}

void	TicTacToe::game_loop() {
	while (_gameover == false) {
		print_board();
		_player1->doTurn(*this);
		print_board();
		if (checkWinConditions(_player1->getMarker())) {
			std::cout << "Player1 Won!" << std::endl;
			break ;
		}
		_player2->doTurn(*this);
		print_board();
		if (checkWinConditions(_player2->getMarker())) {
			std::cout << "Player2 Won!" << std::endl;
			break ;
		}
		std::cout << "Type Q to exit or ENTER to continue" << std::endl;
		std::string command;
		std::getline(std::cin, command);
		std::regex reg("[q|Q]");
		if (std::regex_match(command, reg)) {
			std::cout << "Good bye!" << std::endl;
			_gameover = true;
		}
	}
}

void    TicTacToe::print_info() {
    std::cout << "Game info:" << std::endl;
	std::cout << "Player1 marker is " << _player1->getMarker() << std::endl;
	std::cout << "Player2 marker is " << _player2->getMarker() << std::endl;
}

void    TicTacToe::setMarker(int row, int column, char marker) {
	_board[row][column] = marker;
	std::cout << marker << " set on " << row << " " << column << std::endl;
}

char    TicTacToe::getMarker(int row, int column) {
	return _board[row][column];
}

void    TicTacToe::print_board() {
	print_info();
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