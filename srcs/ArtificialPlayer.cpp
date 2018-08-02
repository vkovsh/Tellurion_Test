#include "ArtificialPlayer.hpp"
#include "TicTacToe.hpp"

ArtificialPlayer::ArtificialPlayer(char marker):_marker(marker){
	std::cout << "Artificial player created!" << std::endl;
}

ArtificialPlayer::~ArtificialPlayer(){}

void ArtificialPlayer::doTurn(TicTacToe & t) {
	int height = TicTacToe::getHeight();
	int width = TicTacToe::getWidth();
	if (t.getMarker(1, 1) == '.') {
		t.setMarker(1, 1, _marker);
		return ;
	}
	else {
		for (int i = 0; i < height; ++i) {
			int sum = 0;
			int input_pos = -1;
			for (int j = 0; j < width; ++j) {
				if (t.getMarker(i, j) == '.') {
					input_pos = j;
				}
				else if (t.getMarker(i, j) != _marker) {
					sum++;
				}
			}
			if (sum == 2 && input_pos >= 0) {
				t.setMarker(i, input_pos, _marker);
				return ;
			}
		}
		for (int i = 0; i < width; ++i) {
			int sum = 0;
			int input_pos = -1;
			for (int j = 0; j < height; ++j) {
				if (t.getMarker(j, i) == '.') {
					input_pos = j;
				}
				else if (t.getMarker(j, i) != _marker) {
					sum++;
				}
			}
			if (sum == 2 && input_pos >= 0) {
				t.setMarker(input_pos, i, _marker);
				return ;
			}
		}
		for (int i = 0; i < height; ++i) {
			for (int j = 0; j < width; ++j) {
				if (t.getMarker(i, j) == '.') {
					t.setMarker(i, j, _marker);
					return ;
				}
			}
		}
	}
}

char ArtificialPlayer::getMarker() {
	return _marker;
}