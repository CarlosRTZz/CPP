NAME = ex00

CC = c++

CFLAGS = -Wall -Werror -Wextra -std=c++98

RM = rm -rf

OBJS_DIR = objs

SRCS = WrongAnimal.cpp \
		WrongCat.cpp \
		Animal.cpp \
		Cat.cpp \
		Dog.cpp \
		main.cpp

OBJS = $(addprefix ${OBJS_DIR}/, ${SRCS:%.cpp=%.o})

all: ${NAME}

${OBJS_DIR}/%.o: %.cpp
	mkdir -p ${@D}
	${CC} ${CFLAGS} -I. -c $< -o $@

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

clean:
	${RM} ${OBJS_DIR}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re