#include "HumanPlayer.hpp"
#include "TicTacToe.hpp"

HumanPlayer::HumanPlayer(char marker):_marker(marker){
	std::cout << "Human player created!" << std::endl;
}

HumanPlayer::~HumanPlayer(){}

void HumanPlayer::doTurn(TicTacToe & t)
{
	std::string input;
	std::regex digit("[0-2]");
	int row, column;
	do {
		while (true) {
			std::cout << "Input row [0-2]:" << std::endl;
			getline(std::cin, input);
			if (std::regex_match(input, digit)) {
				row = input[0] - '0';
				break ;
			}
			else {
				std::cout << "Invalid input!" << std::endl;
			}
		}
		while (true) {
			std::cout << "Input column [0-2]:" << std::endl;
			getline(std::cin, input);
			if (std::regex_match(input, digit)) {
				column = input[0] - '0';
				break ;
			}
			else {
				std::cout << "Invalid input!" << std::endl;
			}
		}
	}
	while (t.getMarker(row, column) != '.');
	t.setMarker(row, column, _marker);
}

char HumanPlayer::getMarker() {
	return _marker;
}