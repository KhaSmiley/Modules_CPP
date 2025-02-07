NAME = megaphone
SRCS = megaphone.cpp
FLAGS = -Wall -Wextra -Werror -std=c++98
CC	= c++
OBJS = ${SRCS:.cpp=.o}

all : ${NAME}

${NAME} : ${OBJS}
	${CC} ${FLAGS} ${OBJS} -o ${NAME}

%.o: %.cpp $(INCL)
	$(CC) $(FLAGS) -c $< -o $@

clean :
	rm -f ${OBJS}

fclean : clean
	rm -f ${NAME}

re : fclean all

.PHONY : all clean fclean re