NAME	= PmergeMe
SRC		= main.cpp \
			PmergeMe.cpp
OBJ		= $(SRC:%.cpp=%.o)
CC		= c++
FLAGS	= -Wall -Wextra -Werror -g3 -std=c++98 
# -fno-stack-protector

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re