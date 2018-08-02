#ifndef HUMANPLAYER_HPP
# define HUMANPLAYER_HPP
# include "IPlayer.hpp"

class	HumanPlayer : public IPlayer {
	private:
		char	_marker;

	public:
		HumanPlayer(char marker = 'X');
		~HumanPlayer();
		virtual void doTurn(TicTacToe & t);
		virtual char getMarker();
};

#endif