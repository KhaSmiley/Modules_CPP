NAME	= Bureaucrat
SRC		= main.cpp \
		  AForm.cpp \
		  PresidentialPardonForm.cpp \
		  RobotomyRequestForm.cpp \
		  ShrubberyCreationForm.cpp \
			Bureaucrat.cpp \
			Intern.cpp
OBJ		= $(SRC:%.cpp=%.o)
CC		= c++
FLAGS	= -Wall -Wextra -Werror -std=c++98 -g

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