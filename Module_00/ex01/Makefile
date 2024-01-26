# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cortiz <cortiz@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/19 13:45:01 by cortiz            #+#    #+#              #
#    Updated: 2024/01/26 09:45:05 by cortiz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PhoneBook

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

OBJS_DIR = objs

SRCS =	Contact.cpp	\
		PhoneBook.cpp	\
		main.cpp	\

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
