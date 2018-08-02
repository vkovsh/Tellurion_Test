NAME				=	tic_tac_toe

CC					=	g++
CC_FLAGS			=	-Wall -Werror -Wextra -g -std=c++11

SRC_PATH			=	./srcs/

INC_PATH			=	./includes/
OBJ_PATH			=	./obj/

OBJ					=	$(addprefix $(OBJ_PATH),$(OBJ_NAME))

INC					=	$(addprefix -I, $(INC_PATH))

OBJ_NAME			=	$(SRC_NAME:.cpp=.o)

SRC_NAME			=	main.cpp				\
						TicTacToe.cpp			\
						HumanPlayer.cpp			\
						ArtificialPlayer.cpp

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) -o $(NAME) $(OBJ)
	@echo "Compiling" [ $(NAME) ]

$(OBJ_PATH)%.o: $(SRC_PATH)%.cpp
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CC_FLAGS) -o $@ -c $< $(INC)
	@echo "Linking" [ $< ]

clean:
	@rm -rf $(OBJ_PATH)
	@echo "Cleaning obj [ $(NAME) ]..."

fclean: clean
	@rm -f $(NAME)
	@echo "Remove [ $(NAME) ]..."

re: fclean all