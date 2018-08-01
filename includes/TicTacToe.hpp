#ifndef TICTACTOE_HPP
# define TICTACTOE_HPP
# include <iostream>

class   TicTacToe   {
    private:
        static const int _width = 3;
        static const int _height = 3;
        char _board[_height][_width];
		bool _gameover;
    
    public:
        TicTacToe();
        ~TicTacToe();
        void    print_board();
		void	game_loop();
};

#endif