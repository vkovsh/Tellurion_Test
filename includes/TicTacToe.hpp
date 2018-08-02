#ifndef TICTACTOE_HPP
# define TICTACTOE_HPP
# include <iostream>
# include <cstdlib>
# include "HumanPlayer.hpp"
# include "ArtificialPlayer.hpp"
# include <regex>

class   TicTacToe   {
    private:
        static const int _width = 3;
        static const int _height = 3;
        char _board[_height][_width];
		bool _gameover;
        IPlayer *_player1;
		IPlayer *_player2;
    
    public:
		TicTacToe();
        ~TicTacToe();
        void    	setMarker(int row, int column, char marker);
        char    	getMarker(int row, int column);
        static int	getWidth();
		static int	getHeight();
        bool    	checkWinConditions(char marker);
        void    	print_board();
        void    	print_info();
		void		game_loop();
};

#endif