#ifndef ARTIFICIALPLAYER_HPP
# define ARTIFICIALPLAYER_HPP
# include "IPlayer.hpp"

class	ArtificialPlayer : public IPlayer {
	private:
		char	_marker;

	public:
		ArtificialPlayer(char marker = 'X');
		~ArtificialPlayer();
		virtual void doTurn(TicTacToe & t);
		virtual char getMarker();
};

#endif