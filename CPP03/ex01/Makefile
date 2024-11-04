# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/31 17:30:39 by kboulkri          #+#    #+#              #
#    Updated: 2024/11/04 02:48:50 by kboulkri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ScavTrap
SRC		= main.cpp \
			ClapTrap.cpp \
			ScavTrap.cpp
OBJ		= $(SRC:%.cpp=%.o)
CC		= c++
FLAGS	= -Wall -Wextra -Werror -std=c++98

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