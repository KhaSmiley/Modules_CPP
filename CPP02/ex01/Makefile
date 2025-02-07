# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/26 18:40:38 by kboulkri          #+#    #+#              #
#    Updated: 2024/10/26 18:42:18 by kboulkri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= myfirststep
SRC		= Fixed.cpp \
		  main.cpp
OBJ		= $(SRC:%.cpp=%.o)
INCL	= Fixed.hpp
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