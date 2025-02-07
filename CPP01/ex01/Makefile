# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/11 18:31:49 by kboulkri          #+#    #+#              #
#    Updated: 2024/09/11 18:34:46 by kboulkri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= zombie
SRC		= Zombie.cpp \
		  zombieHorde.cpp \
			main.cpp
OBJ		= $(SRC:%.cpp=%.o)
INCL	= Zombie.hpp
CC		= c++
FLAGS	= -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp $(INCL)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re