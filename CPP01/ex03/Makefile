# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/18 13:34:16 by kboulkri          #+#    #+#              #
#    Updated: 2024/09/18 16:00:50 by kboulkri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= callofweapon
SRC		= srcs/HumanA.cpp \
		  srcs/HumanB.cpp \
		  srcs/Weapon.cpp \
		  srcs/main.cpp
OBJ		= $(SRC:%.cpp=%.o)
INCL	= include/HumanA.hpp \
		  include/HumanB.hpp \
		  include/Weapon.hpp
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