# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/06 14:18:01 by olabrecq          #+#    #+#              #
#    Updated: 2022/02/18 08:33:27 by olabrecq         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCS = 	./srcs/philo.c \
		./srcs/routine.c \
		./srcs/init.c \
		./srcs/utils.c \
		./srcs/status.c

INCLUDES = ./includes/philo.h \

OBJS = ${SRCS:.c=.o}

HEADER = includes/philo.h 

CC = gcc
#  -Werror
CFLAGS 	= -Wall -Wextra -g

# .c.o:		
# 	@echo "\033[0;32m Generating obj..."
# 	@$(CC) ${CFLAGS} ${INCLUDES} -c $< -o $(<:.c=.o)
# 	@echo "\033[0m"

all:	${NAME}

${NAME}:	${OBJS}
	@echo "\033[0;33m Compiling..."
	@$(CC) ${OBJS} -o ${NAME} -lpthread
	@echo "\033[0m"
	@echo "\n\033[32m\033[1m  Philosophers Compiled\n\033[0m"

clean:
	@echo "\033[0;31m Cleaning..."
	@rm -f ${OBJS}
	@echo "\033[0m"

fclean: clean
	@echo "\033[0;31m Removing executable..."
	@rm -f ${PROG}
	@echo "\033[0m"

re:			fclean all

.PHONY: all clean fclean re