#--------Utils------------
YELLOW 	= \033[0;33m
GREEN 	= \033[0;32m
RED 	= \033[0;31m
END 	= \033[0m

RM		=	rm -rf
MK		=	mkdir
#------------------------
NAME = philo

CC = gcc 
FLAGS = -Werror -Wall -Wextra -g

SRC = srcs
INC = includes
OBJ = obj

CFILES =	main.c \
			init.c \
			routine.c \
			status.c \
			utils.c \
			time.c \
			thread.c \
		
HFILES = 	philo.h \
			derf.h \
			struct.h \

OFILES = 	$(CFILES:.c=.o)

SRCS		=	$(addprefix $(SRC)/, $(CFILES))
HEADER		=	$(addprefix $(INC)/, $(HFILES))
OBJS		=	$(addprefix $(OBJ)/, $(OFILES))

$(OBJ)/%.o:	$(SRC)/%.c
			$(CC) $(FLAGS) -I$(INC) -c $< -o $@


all:	$(NAME)

$(NAME): $(OBJ)	$(OBJS)
	@echo "$(GREEN) Compiling..."
	@$(CC) $(OBJS) -o $(NAME) -lpthread
	@echo "$(END)"
	@echo "$(GREEN)  Philosophers Compiled\n $(END)"

$(OBJ):
			@$(MK) $(OBJ)
clean:
	@echo "$(RED) Cleaning..."
	@rm -f $(OBJS)
	@${RM} $(OBJ)/
	@echo "$(END)"

fclean: clean
	@echo "$(RED) Removing executable..."
	@rm -f $(NAME)
	@echo "$(END)"

re:			fclean all

.PHONY: all clean fclean re
