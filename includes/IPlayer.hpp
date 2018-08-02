#ifndef IPLAYER_HPP
# define IPLAYER_HPP
# include <iostream>
# include <regex>

class   TicTacToe;

class	IPlayer {
    public:
        virtual ~IPlayer() {}
        virtual void doTurn(TicTacToe & t) = 0;
        virtual char getMarker() = 0;
};

#endif