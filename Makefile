		# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/02 11:58:19 by olabrecq          #+#    #+#              #
#    Updated: 2022/03/02 15:00:26 by olabrecq         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC	 = srcs
INC  = includes
OBJ  = obj

CC = gcc
CFLAGS 	= -Wall -Werror -Wextra -g

RM		=	rm -rf
MK		=	mkdir

CFILES = 	philo.c \
			routine.c \
			init.c \
			utils.c \
			status.c

HFILES = 	philo.h \

OFILES = 	${CFILES:.c=.o}

SRCS		=	$(addprefix $(SRC)/, $(CFILES))
HEADER		=	$(addprefix $(INC)/, $(HFILES))
OBJS		=	$(addprefix $(OBJ)/, $(OFILES))

VPATH		=	$(SRCS)

$(OBJ)/%.o:	$(SRC)/%.c
			$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

all:	$(NAME)

$(NAME): $(OBJ)	$(OBJS)
	@echo "\033[0;33m Compiling..."
	@$(CC) $(OBJS) -o $(NAME) -lpthread
	@echo "\033[0m"
	@echo "\n\033[32m\033[1m  Philosophers Compiled\n\033[0m"

$(OBJ):
			@$(MK) $(OBJ)
clean:
	@echo "\033[0;31m Cleaning..."
	@rm -f $(OBJS)
	@${RM} $(OBJ)/
	@echo "\033[0m"

fclean: clean
	@echo "\033[0;31m Removing executable..."
	@rm -f $(PROG)
	@echo "\033[0m"

re:			fclean all

.PHONY: all clean fclean re